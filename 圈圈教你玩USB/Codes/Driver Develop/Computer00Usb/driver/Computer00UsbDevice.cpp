// Computer00UsbDevice.cpp
//
// Generated by DriverWizard 3.2.0 (Build 2485)
// Requires DDK and DriverWorks
// File created on 8/22/2008
//
// This source file contains the implementation of a subclass of KDevice.
// WDM drivers implement a subclass of KPnpDevice and override member
// functions to handle requests (IRPs) from the system.
//

#include <vdw.h>
#include <kusb.h>
#include <kusbbusintf.h>
#include "Computer00UsbDriver.h"
#include "Computer00UsbDevice.h"
#include "..\\intrface.h"

#pragma hdrstop("Computer00Usb.pch")

// Global driver trace object
// TODO:	Use KDebugOnlyTrace if you want trace messages
//			to appear only in checked builds.  Use KTrace if
//			you want trace messages to always appear.  Call
//			method SetOutputLevel to set the output threshold.
extern KDebugOnlyTrace T;

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::Computer00UsbDevice
//		This is the constructor for the class representing the Functional
//		Device Object, or FDO.  It is derived from KPnpDevice, which builds
//		in automatic dispatching of subfunctions of IRP_MJ_POWER and IRP_MJ_PNP
//		to virtual member functions.
//		The object being constructed contains a data member (m_Lower) of type
//		KPnpLowerDevice. By initializing it, the driver binds the FDO to the
//		PDO and creates an interface to the upper edge of the system class driver.
//
//	Arguments:
//		IN	Pdo
//				Physical Device Object.  This is a pointer to a system
//				device object that represents the physical device.
//
//		IN	Unit
//				Unit number to append to the device's base device name 
//				to distinguish multiple units of this device type.
//
//	Return Value:
//		none
//
Computer00UsbDevice::Computer00UsbDevice(PDEVICE_OBJECT Pdo, ULONG Unit) :
	DeviceName(NULL),
	KPnpDevice(Pdo, &GUID_DEVINTERFACE_COMPUTER00USB)
{
	if (!NT_SUCCESS(m_ConstructorStatus))
	{
		T.Trace(TraceError, __FUNCTION__": Failed to create device Computer00UsbDevice"
			" unit number %d status %x\n", Unit, m_ConstructorStatus);
		ASSERT(FALSE);
		return;
	}

	// Initialize the lower device
	m_Lower.Initialize(this, Pdo);

	// Initialize the interface object.  The wizard generates code 
	// to support a single interface.  You may create and add additional 
	// interfaces.  By default, the wizard uses InterfaceNumber 0 (the 
	// first interface descriptor), ConfigurationValue 1 (the first
	// configuration descriptor), and initial interface alternate
	// setting of 0.  If your device has multiple interfaces or alternate
	// settings for an interface, you can add additional KUsbInterface
	// objects or adjust the parameters passed to this function.
	m_Interface.Initialize(
					m_Lower, //KUsbLowerDevice
					0,		 //InterfaceNumber
					1,		 //ConfigurationValue 
					0		 //Initial Interface Alternate Setting
					); 

	// Initialize each Pipe object
	//Ep1In.Initialize(m_Lower, 81, 8);	
	//Ep1Out.Initialize(m_Lower, 1, 8);	
	//Ep2In.Initialize(m_Lower, 82, 64);	
	//Ep2Out.Initialize(m_Lower, 2, 64);	

//原来代码有误，修改如下
	Ep1In.Initialize(m_Lower, 0x81, 8);	
	Ep1Out.Initialize(m_Lower, 0x01, 8);	
	Ep2In.Initialize(m_Lower, 0x82, 64);	
	Ep2Out.Initialize(m_Lower, 0x02, 64);	

#if (_WDM_ && (WDM_MAJORVERSION > 1 ||((WDM_MAJORVERSION == 1) && (WDM_MINORVERSION >= 0x20))))
	// Initialize USB direct client access interface
	if (STATUS_SUCCESS == m_BusIntf.Initialize(m_Lower.TopOfStack()))
		m_fBusIntfAvailable = TRUE;
	else
		m_fBusIntfAvailable = FALSE;
#endif

	// Inform the base class of the lower edge device object
	SetLowerDevice(&m_Lower);

	// Initialize the PnP Policy settings to the "standard" policy
	SetPnpPolicy();

	// TODO: Customize the PnP Policy for this device by setting
	//		 flags in m_Policies.

	// Initialize the Power Policy settings to the "standard" policy
	SetPowerPolicy();

	// TODO: Customize the Power Policy for this device by setting
	//		 flags in m_PowerPolicies.


	LoadRegistryParameters();
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::~Computer00UsbDevice
//		This is the destructor for the class. 
//
//	Arguments:
//		none
//
//	Return Value:
//		none
//
Computer00UsbDevice::~Computer00UsbDevice()
{
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::LoadRegistryParameters
//		Read the registry to initialize driver data members.
//
//	Arguments:
//		none
//
//	Return Value:
//		none
//
void Computer00UsbDevice::LoadRegistryParameters()
{
    // Read the driver's registry values from the registry
	NTSTATUS status = STATUS_SUCCESS;
	UNICODE_STRING	regPath;
	KRegistryKey	RegKey;
    ULONG			length;


	status = RegKey.Initialize(
				m_Lower.DeviceObject(),
                PLUGPLAY_REGKEY_DRIVER,
                KEY_ALL_ACCESS
				);

	if (!NT_SUCCESS(status))
	{
		T.Trace(TraceWarning, __FUNCTION__":: Failed to open root key for DeviceName %x", status);
	}
	else
	{
		length = 0;

		// Attempt to read the value key
		status = RegKey.QueryValue(
                L"DeviceName", 
				DeviceName,
				length,
				PagedPool
				);

        if (NT_SUCCESS(status) && DeviceName != NULL)
        {
            T.Trace(TraceInfo, __FUNCTION__ ": RegKey.QueryValue returned %d bytes, DeviceName = %S\n", length, DeviceName);
        }
		else
		{
            T.Trace(TraceWarning, __FUNCTION__ ": RegKey.QueryValue failed to get DeviceName, STATUS %x\n", status);
		}
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::DefaultPnp
//		Default handler for IRP_MJ_PNP. 
//		This routine just passes the IRP through to the lower device. IRPs 
//		that correspond to any virtual members of KpnpDevice that handle 
//		minor functions of IRP_MJ_PNP and that are not overridden get 
//		passed to this routine.
//
//	Arguments:
//		IN	I
//			the plug and play IRP
//
//	Return Value:
//		NTSTATUS
//			Result returned from lower device
//
NTSTATUS Computer00UsbDevice::DefaultPnp(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);
	T << I; 

	I.ForceReuseOfCurrentStackLocationInCalldown();
	NTSTATUS status = m_Lower.PnpCall(this, I);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::DefaultPower
//		Default handler for IRP_MJ_POWER. 
//		This routine just passes the IRP through to the lower device. IRPs 
//		that correspond to any virtual members of KpnpDevice that handle 
//		minor functions of IRP_MJ_POWER and that are not overridden get 
//		passed to this routine.
//
//	Arguments:
//		IN	I
//			the power IRP
//
//	Return Value:
//		NTSTATUS
//			Result returned from lower device
//
NTSTATUS Computer00UsbDevice::DefaultPower(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);
	T << I; 

	I.IndicatePowerIrpProcessed();
	I.CopyParametersDown();
	NTSTATUS status = m_Lower.PnpPowerCall(this, I);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::SystemControl
//		Default handler for IRP_MJ_SYSTEM_CONTROL. 
//		This routine just passes the IRP through to the next device since 
//		this driver is not a WMI provider.
//
//	Arguments:
//		IN	I
//			the system control (WMI) IRP
//
//	Return Value:
//		NTSTATUS
//			Result returned from lower device
//
NTSTATUS Computer00UsbDevice::SystemControl(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);
	T << I; 

	NTSTATUS status = STATUS_SUCCESS;

	I.ForceReuseOfCurrentStackLocationInCalldown();
	status = m_Lower.PnpCall(this, I);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::OnStartDevice
//		Handler for IRP_MJ_PNP subfcn IRP_MN_START_DEVICE. 
//		Initialize the hardware device. Typically, the driver initializes
//		physical resources here.  Call I.AllocatedResources() for a list
//		of the raw resources that the system has assigned to the device,
//		or I.TranslatedResources() for the translated resource list.
//
//	Arguments:
//		IN	I
//			the start device IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::OnStartDevice(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	I.Information() = 0;
	status = STATUS_UNSUCCESSFUL;

	AC_STATUS acStatus = AC_SUCCESS;

	// By default, the wizard passes a ConfigurationValue of 1 to 
	// ActivateConfiguration().  This corresponds to the first configuration 
	// that the device reports in its configuration descriptor.  If the device 
	// supports multiple configurations, pass the appropriate
	// ConfigurationValue of the configuration to activate here.
	acStatus = m_Lower.ActivateConfiguration(
		1	// ConfigurationValue 1 (the first configuration)
		);

	switch (acStatus)
	{
		case AC_SUCCESS:
			T << "USB ActivateConfiguration OK\n";
			status = STATUS_SUCCESS;

			// TODO: Use the USB direct client access			
			TestBusInterface();
			break;

		case AC_COULD_NOT_LOCATE_INTERFACE:
			T << "ActivateConfiguration Error: Could not locate interface\n";
			break;

		case AC_COULD_NOT_PRECONFIGURE_INTERFACE:
			T << "ActivateConfiguration Error: Could not get configuration descriptor\n";
			break;

		case AC_CONFIGURATION_REQUEST_FAILED:
			T << "ActivateConfiguration Error: H/W did not accept configuration URB\n";
			break;

		case AC_FAILED_TO_INITIALIZE_INTERFACE_OBJECT:
			T << "ActivateConfiguration Error: Failed to initialize interface object\n";
			break;

		case AC_FAILED_TO_GET_DESCRIPTOR:
			T << "ActivateConfiguration Error: Failed to get device descriptor\n";
			break;

		case AC_FAILED_TO_OPEN_PIPE_OBJECT:
			// NOTE: this may not be an error.  It could mean that
			// the device has an endpoint for which a KUsbPipe object has
			// not been instanced.  If the intention is to not use this endpoint,
			// then it's likely not a problem.  
			status = STATUS_SUCCESS;
			T << "ActivateConfiguration Warning: Failed to open pipe object\n";
			break;

		default:
			T << "ActivateConfiguration Error: Unexpected error activating USB configuration\n";
			break;
	}

	// TODO:	Add USB device-specific code to start the hardware.

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::OnStopDevice
//		Handler for IRP_MJ_PNP subfcn IRP_MN_STOP_DEVICE. 
//		The system calls this when the device is stopped.  Release any 
//		hardware resources in this routine.
//
//	Arguments:
//		IN	I
//			the stop device IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::OnStopDevice(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	// TODO: Add device-specific code to stop your hardware device.
    // The base class will handle completion of the IRP

	// Release the system resources
	Invalidate();

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, STATUS_SUCCESS);

	// Can't fail this IRP
	return STATUS_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::OnRemoveDevice
//		Handler for IRP_MJ_PNP subfcn IRP_MN_REMOVE_DEVICE. 
//		The system calls this when the device is removed.
//		Our PnP policy will take care of 
//			(1) giving the IRP to the lower device
//			(2) detaching the PDO
//			(3) deleting the device object
//
//	Arguments:
//		IN	I
//			the remove device IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::OnRemoveDevice(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	// TODO: Add device-specific code to remove your hardware device.
    // The base class will handle completion of the IRP

	// Release the system resources
	Invalidate();

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, STATUS_SUCCESS);

	// Can't fail this IRP
	return STATUS_SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::OnQueryCapabilities
//		Handler for IRP_MJ_PNP subfcn IRP_MN_QUERY_CAPABILITIES. 
//		The system calls this to query the device capabilities.
//		The Bus driver fills in the device capabilities structure.
//		This method is usually only overridden to alter the 
//		device capabilities reported by the bus driver.
//
//	Arguments:
//		IN	I
//			the query capabilities IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::OnQueryCapabilities(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	I.CopyParametersDown();
	I.SetCompletionRoutine(LinkTo(OnQueryCapabilitiesComplete), this, TRUE, TRUE, TRUE);

	status = m_Lower.PnpCall(this, I);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::OnQueryCapabilitiesComplete
//		Completion routine for IRP_MJ_PNP subfcn IRP_MN_QUERY_CAPABILITIES. 
//		The system calls OnQueryCapabilities to query the device capabilities.
//		The Bus driver fills in the device capabilities structure.
//		This method is called when the IRP is completed to alter the 
//		device capabilities reported by the bus driver.
//
//	Arguments:
//		IN	I
//			the query capabilities IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::OnQueryCapabilitiesComplete(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.");

	NTSTATUS status = I.Status();


	if (I->PendingReturned)
		I.MarkPending();

	if (NT_SUCCESS(status)) 
	{
		// TODO: Adjust device capabilities structure as required.
		I.DeviceCapabilities()->SurpriseRemovalOK = TRUE;
	}

	T.Trace(TraceInfo, __FUNCTION__"--.");

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::TestBusInterface
//		This routine uses the USB direct client interface to 
//		query information.
//
//	Arguments:
//		none
//
//	Return Value:
//		none
//
void Computer00UsbDevice::TestBusInterface()
{
#if (_WDM_ && (WDM_MAJORVERSION > 1 ||((WDM_MAJORVERSION == 1) && (WDM_MINORVERSION >= 0x20))))

	if (m_fBusIntfAvailable) 
	{
		T.Trace(TraceInfo, "USB Bus Interface Version: %u\n", m_BusIntf.Version());
		T.Trace(TraceInfo, "High Speed Device: %S\n", (m_BusIntf.IsDeviceHighSpeed()?"TRUE":"FALSE"));

		USBD_VERSION_INFORMATION UsbVerInfo;
		RtlZeroMemory(&UsbVerInfo, sizeof(USBD_VERSION_INFORMATION));
		ULONG HcdCapabilities = 0;

		m_BusIntf.GetUSBDIVersion(&UsbVerInfo, &HcdCapabilities);

		T.Trace(TraceInfo, "USBDI_Version: %u\n", UsbVerInfo.USBDI_Version);
		T.Trace(TraceInfo, "Supported_USB_Version: %u\n", UsbVerInfo.Supported_USB_Version);

		ULONG TotalBW, ConsumedBW;
		NTSTATUS Status = m_BusIntf.GetBandwidth(&TotalBW,&ConsumedBW);

		if (STATUS_SUCCESS == Status) 
		{
			T.Trace(TraceInfo, "Total Bandwidth: %u\n", TotalBW);
			T.Trace(TraceInfo, "Consumed Bandwidth: %u\n", ConsumedBW);
		}

		PWSTR HcName = NULL;
		Status = m_BusIntf.GetControllerName(HcName);

		if (STATUS_SUCCESS == Status && HcName) 
		{
			T.Trace(TraceInfo, "HC Name: %s\n", HcName);
			delete HcName;
		}

		ULONG CurrentFrame;
		m_BusIntf.QueryBusTime(&CurrentFrame);

		T.Trace(TraceInfo, "Current Frame: %u\n", CurrentFrame);
	}
#endif
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::OnDevicePowerUp
//		Handler for IRP_MJ_POWER subfcn IRP_MN_SET_POWER 
//		for a request to go to power on state from low power state
//		This function was called by the framework from the completion
//		routine of the IRP_MJ_POWER dispatch handler in KPnpDevice.
//		The bus driver has completed the IRP and this driver can now
//		access the hardware device.  
//		This routine runs at DISPATCH_LEVEL.
//
//	Arguments:
//		IN	I
//			the power IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::OnDevicePowerUp(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	// TODO: Add device-specific code to:
	//		 Restore any context to the hardware device that
	//		 was saved during the handling of a power down request.
	//		 See the OnDeviceSleep function.
	//		 Do NOT complete this IRP.
    //		 The base class will handle completion of the IRP

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::OnDeviceSleep
//		Handler for IRP_MJ_POWER subfcn IRP_MN_SET_POWER 
//		for a request to go to a low power state from a high power state
//		This function was called by the framework from the IRP_MJ_POWER 
//		dispatch handler in KPnpDevice prior to forwarding to the PDO.
//		The hardware has yet to be powered down and this driver can now
//		access the hardware device.  
//		This routine runs at PASSIVE_LEVEL.
//
//	Arguments:
//		IN	I
//			the power IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::OnDeviceSleep(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	// TODO: Add device-specific code to:
	//		 Save any context to the hardware device that will be required 
	//		 during a power up request. See the OnDevicePowerUp function.
	//		 Do NOT complete this IRP.  The base class handles forwarding
	//		 this IRP to the PDO.

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::Create
//		Dispatch routine for IRP_MJ_CREATE requests.  
//
//	Arguments:
//		IN I 
//			the create IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::Create(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	// TODO: For any IRP, to display the contents of the IRP
	//		 in a formatted way, use the KTrace << operator:
	//			 T << I;

	NTSTATUS status = STATUS_SUCCESS;

	// For devices that expose an interface instead of symbolic 
	// link, DO_EXCLUSIVE flag is not used by the I/O manager.   
	// So, exclusivity must be enforced here.
	if (m_OpenCounter.Test() > 0)
	{
		status = STATUS_SHARING_VIOLATION;

		I.Information() = 0;
		I.PnpComplete(this, status);

		T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

		return status;
	}

	// TODO: At this point, perform custom processing for IRP_MJ_CREATE
	// Generally a create IRP is targeted at our FDO, so its not needed
	// to pass it down to the PDO.  

	I.Information() = 0;
	I.PnpComplete(this, status);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::Close
//		Dispatch routine for IRP_MJ_CLOSE requests.  
//
//	Arguments:
//		IN I 
//			the close IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::Close(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	// TODO: At this point, perform custom processing for IRP_MJ_CLOSE
	// Generally a close IRP is targeted at our FDO, so we don't need
	// to pass it down to the PDO.  

	I.Information() = 0;
	I.PnpComplete(this, status);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::Read
//		Dispatch routine for IRP_MJ_READ requests.  
//
//	Arguments:
//		IN I 
//			the read IRP
//
//	Return Value:
//		NTSTATUS
// 注：用/**/方式注释掉的代码为向导生成的代码
NTSTATUS Computer00UsbDevice::Read(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	//原来向导生成在后面，从后面移动上来
	// Get a pointer to the caller's buffer.
	PUCHAR pBuffer = (PUCHAR) I.BufferedReadDest();
	ULONG readSize = I.ReadSize();
	ULONG bytesRead = 0;

	// TODO: Validate the parameters of the IRP.  Replace "FALSE"
	//		 in the following line with error checking code that
	//		 evaulates to TRUE if the request is not valid.
	/*if (FALSE)*/
	if(pBuffer==NULL) //如果准备的读缓冲区为无效地址，则返回参数无效
	{
		status = STATUS_INVALID_PARAMETER; //状态设置为无效参数
		I.Information() = 0; //读取字节数为0
		I.PnpComplete(status); //完成该IO操作
//调试信息
		T.Trace(TraceWarning, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

		return status; //返回状态
	}

	// Always ok to read 0 elements
	if (I.ReadSize() == 0) //如果读长度为0，那么总是成功的
	{
		I.Information() = 0; //读字节数为0
		I.PnpComplete(this, status);  //完成该IO
//调试信息
		T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

		return status;
	}

	/*
	移动到了上面
	// Get a pointer to the caller's buffer.
	PUCHAR pBuffer = (PUCHAR) I.BufferedReadDest();
	ULONG readSize = I.ReadSize();
	ULONG bytesRead = 0;
	*/

	// TODO: At this point, perform any processing for IRP_MJ_READ
	//		 To satisfy the read now, transfer data from the driver
	//		 to the caller's buffer at "pBuffer".  Then, indicate
	//		 how much data was transferred:
 
	/**************以下为圈圈新增代码************/
 //创建一个中断传输的URB，用来从端点1读取数据
 PURB pUrb=Ep1In.BuildInterruptTransfer( pBuffer, //接收数据的缓冲区
            readSize, //读数据的数据字节数
            TRUE,  //TRUE表示设备传输的字节数可以少于指定的字节数
            NULL,  //连接下一个传输的URB，这里没有，置为NULL
            NULL,  //指向一个已经存在的URB。置为NULL，分配一个新的URB
            TRUE); //TURE表示读数据

	if(pUrb==NULL)  //如果分配失败
 {
  status=STATUS_INSUFFICIENT_RESOURCES;  //设置状态为资源不足
 }
 else
 {
  //提交URB，并设置等待3秒后就超时
  status=Ep1In.SubmitUrb(pUrb,NULL,NULL,3000);
  //获取实际读到的数据字节数
  bytesRead=pUrb->UrbBulkOrInterruptTransfer.TransferBufferLength;
  delete pUrb; //删除刚刚分配的URB
 }
	/*************新增代码完毕****************/

	//保存传输数据的字节数
	I.Information() = bytesRead;
 //完成该IRP
	I.PnpComplete(this, status);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::Write
//		Dispatch routine for IRP_MJ_WRITE requests.  
//
//	Arguments:
//		IN I 
//			the write IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::Write(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

 //原来向导生成在后面，从后面移动上来
	// Get a pointer to the caller's buffer.
	PUCHAR pBuffer = (PUCHAR) I.BufferedWriteSource();
	ULONG writeSize = I.WriteSize();
	ULONG bytesSent = 0;

	// TODO: Validate the parameters of the IRP.  Replace "FALSE"
	//		 in the following line with error checking code that
	//		 evaulates to TRUE if the request is not valid.
	/*if (FALSE)*/
	if(pBuffer==NULL) //如果要发送的数据缓冲区为无效地址，则返回参数无效
	{
		status = STATUS_INVALID_PARAMETER; //状态为无效参数
		I.Information() = 0; //传输字节为0
		I.PnpComplete(status); //完成该IRP

		T.Trace(TraceWarning, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

		return status;
	}

	// Always ok to write 0 elements
	if (I.WriteSize() == 0)  //如果读长度为0，那么总是成功的
	{
		I.Information() = 0;
		I.PnpComplete(this, status);

		T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

		return status;
	}

	/*
	移动到了上面
	// Get a pointer to the caller's buffer.
	//PUCHAR pBuffer = (PUCHAR) I.BufferedWriteSource();
	//ULONG writeSize = I.WriteSize();
	//ULONG bytesSent = 0;
 */

	// TODO: At this point, perform any processing for IRP_MJ_WRITE
	//		 To satisfy the write now, transfer data to the driver
	//		 from the caller's buffer at "pBuffer".  Then, indicate
	//		 how much data was transferred:

	/**************以下为圈圈新增代码************/
 //创建一个中断传输的URB，用来往端点1发送数据
 PURB pUrb=Ep1Out.BuildInterruptTransfer( pBuffer,  //发送数据的缓冲区
            writeSize, //发送数据的数据字节数
            FALSE, //FALSE表示设备传输的字节少数不可以于指定的字节数
            NULL,  //连接下一个传输的URB，这里没有，置为NULL
            NULL,  //指向一个已经存在的URB。置为NULL，分配一个新的URB
            FALSE);  //FALSE表示发送数据

	if(pUrb==NULL)  //如果分配失败
 {
  status=STATUS_INSUFFICIENT_RESOURCES;  //设置状态为资源不足
 }
 else
 {
  //提交URB，并无限等待
  status=Ep1Out.SubmitUrb(pUrb,NULL,NULL,0);
  //获取实际发送的数据字节数
  bytesSent=pUrb->UrbBulkOrInterruptTransfer.TransferBufferLength;
  delete pUrb; //删除刚刚分配的URB
 }
	/*************新增代码完毕****************/

	I.Information() = bytesSent;

	I.PnpComplete(this, status);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::DeviceControl
//		Dispatch routine for IRP_MJ_DEVICE_CONTROL requests.  
//
//	Arguments:
//		IN I 
//			the ioctl IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::DeviceControl(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	switch (I.IoctlCode())
	{

    case EP1_READ:
		status = EP1_READ_Handler(I);
		break;

    case EP1_WRITE:
		status = EP1_WRITE_Handler(I);
		break;

    case EP2_READ:
		status = EP2_READ_Handler(I);
		break;

    case EP2_WRITE:
		status = EP2_WRITE_Handler(I);
		break;

	default:
		status = STATUS_INVALID_DEVICE_REQUEST;
		break;
	}

	// If the IRP's IOCTL handler deferred processing using some driver
	// specific scheme, the status variable is set to STATUS_PENDING.
	// In this case we simply return that status, and the IRP will be
	// completed later.  Otherwise, complete the IRP using the status
	// returned by the IOCTL handler.
	if (status != STATUS_PENDING)
	{
		I.PnpComplete(this, status);
	}

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::EP1_READ_Handler
//		Handler for ioctl EP1_READ.  The DeviceControl
//		method will complete the IRP.
//
//	Arguments:
//		IN I 
//			the ioctl IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::EP1_READ_Handler(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	ULONG inputSize = I.IoctlInputBufferSize();
	ULONG outputSize = I.IoctlOutputBufferSize();

 // Buffered ioctl - using the same buffer so read the buffer before writing the buffer
 PVOID inputBuffer = I.IoctlBuffer();
 PVOID outputBuffer = I.IoctlBuffer();

	// TODO: Validate the parameters of the IRP.  Replace "FALSE"
	//		 in the following line with error checking code that
	//		 evaulates to TRUE if the request is not valid.
 /*if (FALSE)*/
	//注意：当读数据时，应该将数据保存在应用程序提供的输出缓冲中，
	//因为驱动程序将会将读到的数据输出给应用程序
	if(outputBuffer==NULL) //如果缓冲区为无效地址
	{
		status = STATUS_INVALID_PARAMETER;
		I.Information() = 0;
	}
	else //如果参数有效
	{
	
		// TODO: copy data
		//		 To satisfy the ioctl now, transfer data using the
		//		 caller's buffers at "inputBuffer" and/or "outputBuffer".  
		//		 Then, indicate how much data was transferred:
		/**************以下为圈圈新增代码************/
		if(outputSize==0) //如果读数据长度为0，则不用传输数据
		{
			I.Information() = 0;
		}
		else //数据长度不为0
		{
   //创建一个中断传输的URB，用来从端点1读取数据
   PURB pUrb=Ep1In.BuildInterruptTransfer(outputBuffer, //接收数据的缓冲区
              outputSize, //读数据的数据字节数
              TRUE,  //TRUE表示设备传输的字节数可以少于指定的字节数
              NULL,  //连接下一个传输的URB，这里没有，置为NULL
              NULL,  //指向一个已经存在的URB。置为NULL，分配一个新的URB
              TRUE);  //TURE表示读数据

			if(pUrb==NULL)  //如果分配失败
			{
				status=STATUS_INSUFFICIENT_RESOURCES;  //设置状态为资源不足
				I.Information()=0; //数据传输为0
			}
			else
			{
				//提交URB，并设置等待3秒后就超时
				status=Ep1In.SubmitUrb(pUrb,NULL,NULL,3000);
				//获取实际读到的数据字节数
				I.Information()=pUrb->UrbBulkOrInterruptTransfer.TransferBufferLength;
				delete pUrb; //删除刚刚分配的URB
			}
		}
/*************新增代码完毕****************/
	}

	T.Trace(NT_SUCCESS(status)?TraceInfo:TraceWarning, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::EP1_WRITE_Handler
//		Handler for ioctl EP1_WRITE.  The DeviceControl
//		method will complete the IRP.
//
//	Arguments:
//		IN I 
//			the ioctl IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::EP1_WRITE_Handler(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	ULONG inputSize = I.IoctlInputBufferSize();
	ULONG outputSize = I.IoctlOutputBufferSize();

 // Buffered ioctl - using the same buffer so read the buffer before writing the buffer
 PVOID inputBuffer = I.IoctlBuffer();
 PVOID outputBuffer = I.IoctlBuffer();

	// TODO: Validate the parameters of the IRP.  Replace "FALSE"
	//		 in the following line with error checking code that
	//		 evaulates to TRUE if the request is not valid.
	/*if (FALSE)*/
	//注意：当发送数据时，应该将从输入缓冲区中获取数据，
	//因为应用程序会将数据放在输入缓冲区中
	if(inputBuffer==NULL) //如果输入缓冲区为无效地址
	{
		status = STATUS_INVALID_PARAMETER;
		I.Information() = 0;
	}
	else
	{
	
		// TODO: copy data
		//		 To satisfy the ioctl now, transfer data using the
		//		 caller's buffers at "inputBuffer" and/or "outputBuffer".  
		//		 Then, indicate how much data was transferred:

		/**************以下为圈圈新增代码************/
		if(inputSize==0) //如果输出数据长度为0，则不用传输数据
		{
			I.Information() = 0;
		}
		else //数据长度不为0
		{
			//创建一个中断传输的URB，用来往端点1发送数据
			PURB pUrb=Ep1Out.BuildInterruptTransfer( inputBuffer,  //发送数据的缓冲区
														inputSize, //发送数据的数据字节数
														FALSE,  //FALSE表示设备传输的字节少数不可以于指定的字节数
														NULL,  //连接下一个传输的URB，这里没有，置为NULL
														NULL,  //指向一个已经存在的URB。置为NULL，分配一个新的URB
														FALSE);  //FALSE表示发送数据

			if(pUrb==NULL)  //如果分配失败
			{
				status=STATUS_INSUFFICIENT_RESOURCES;  //设置状态为资源不足
				I.Information()=0; //数据传输为0
			}
			else
			{
				//提交URB，并无限等待
				status=Ep1Out.SubmitUrb(pUrb,NULL,NULL,0);
				//获取实际发送数据的字节数
				I.Information()=pUrb->UrbBulkOrInterruptTransfer.TransferBufferLength;
				delete pUrb; //删除刚刚分配的URB
			}
		}
/*************新增代码完毕****************/
	}

	T.Trace(NT_SUCCESS(status)?TraceInfo:TraceWarning, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::EP2_READ_Handler
//		Handler for ioctl EP2_READ.  The DeviceControl
//		method will complete the IRP.
//
//	Arguments:
//		IN I 
//			the ioctl IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::EP2_READ_Handler(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	ULONG inputSize = I.IoctlInputBufferSize();
	ULONG outputSize = I.IoctlOutputBufferSize();

 // Buffered ioctl - using the same buffer so read the buffer before writing the buffer
 PVOID inputBuffer = I.IoctlBuffer();
 PVOID outputBuffer = I.IoctlBuffer();

	// TODO: Validate the parameters of the IRP.  Replace "FALSE"
	//		 in the following line with error checking code that
	//		 evaulates to TRUE if the request is not valid.
 /*if (FALSE)*/
	//注意：当读数据时，应该将数据保存在应用程序提供的输出缓冲中，
	//因为驱动程序将会将读到的数据输出给应用程序
	if(outputBuffer==NULL) //如果缓冲区为无效地址
	{
		status = STATUS_INVALID_PARAMETER;
		I.Information() = 0;
	}
	else //如果参数有效
	{
	
		// TODO: copy data
		//		 To satisfy the ioctl now, transfer data using the
		//		 caller's buffers at "inputBuffer" and/or "outputBuffer".  
		//		 Then, indicate how much data was transferred:

		/**************以下为圈圈新增代码************/
		if(outputSize==0) //如果读数据长度为0，则不用传输数据
		{
			I.Information() = 0;
		}
		else //数据长度不为0
		{
			//创建一个批量传输的URB，用来从端点2读取数据
			PURB pUrb=Ep2In.BuildBulkTransfer( outputBuffer,  //接收数据的缓冲区
														outputSize, //读数据的数据字节数
														TRUE,  //TURE表示读数据
														NULL,  //连接下一个传输的URB，这里没有，置为NULL
														TRUE,  //TRUE表示设备传输的字节数可以少于指定的字节数
														NULL);  //指向一个已经存在的URB。置为NULL，分配一个新的URB

			if(pUrb==NULL)  //如果分配失败
			{
				status=STATUS_INSUFFICIENT_RESOURCES;  //设置状态为资源不足
				I.Information()=0; //数据传输为0
			}
			else
			{
				//提交URB，并设置等待3秒后就超时
				status=Ep2In.SubmitUrb(pUrb,NULL,NULL,3000);
				//获取实际读到的数据字节数
				I.Information()=pUrb->UrbBulkOrInterruptTransfer.TransferBufferLength;
				delete pUrb; //删除刚刚分配的URB
			}
		}
/*************新增代码完毕****************/
	}

	T.Trace(NT_SUCCESS(status)?TraceInfo:TraceWarning, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::EP2_WRITE_Handler
//		Handler for ioctl EP2_WRITE.  The DeviceControl
//		method will complete the IRP.
//
//	Arguments:
//		IN I 
//			the ioctl IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::EP2_WRITE_Handler(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	ULONG inputSize = I.IoctlInputBufferSize();
	ULONG outputSize = I.IoctlOutputBufferSize();

	// Buffered ioctl - using the same buffer so read the buffer before writing the buffer
 PVOID inputBuffer = I.IoctlBuffer();
 PVOID outputBuffer = I.IoctlBuffer();

	// TODO: Validate the parameters of the IRP.  Replace "FALSE"
	//		 in the following line with error checking code that
	//		 evaulates to TRUE if the request is not valid.
	/*if (FALSE)*/
	//注意：当发送数据时，应该将从输入缓冲区中获取数据，
	//因为应用程序会将数据放在输入缓冲区中
	if(inputBuffer==NULL) //如果输入缓冲区为无效地址
	{
		status = STATUS_INVALID_PARAMETER;
		I.Information() = 0;
	}
	else
	{
		// TODO: copy data
		//		 To satisfy the ioctl now, transfer data using the
		//		 caller's buffers at "inputBuffer" and/or "outputBuffer".  
		//		 Then, indicate how much data was transferred:
		/**************以下为圈圈新增代码************/
		if(inputSize==0) //如果输出数据长度为0，则不用传输数据
		{
			I.Information() = 0;
		}
		else //数据长度不为0
		{
			//创建一个批量传输的URB，用来往端点2发送数据
			PURB pUrb=Ep2Out.BuildBulkTransfer( inputBuffer,  //发送数据的缓冲区
														inputSize, //发送数据的数据字节数
														FALSE,  //FALSE表示发送数据
														NULL,  //连接下一个传输的URB，这里没有，置为NULL
														FALSE,  //FALSE表示设备传输的字节少数不可以于指定的字节数
														NULL);  //指向一个已经存在的URB。置为NULL，分配一个新的URB

			if(pUrb==NULL)  //如果分配失败
			{
				status=STATUS_INSUFFICIENT_RESOURCES;  //设置状态为资源不足
				I.Information()=0; //数据传输为0
			}
			else
			{
				//提交URB，并无限等待
				status=Ep2Out.SubmitUrb(pUrb,NULL,NULL,0);
				//获取实际发送数据的字节数
				I.Information()=pUrb->UrbBulkOrInterruptTransfer.TransferBufferLength;
				delete pUrb; //删除刚刚分配的URB
			}
		}
/*************新增代码完毕****************/
	}

	T.Trace(NT_SUCCESS(status)?TraceInfo:TraceWarning, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::CleanUp
//		Dispatch routine for IRP_MJ_CLEANUP requests.  
//
//	Arguments:
//		IN I 
//			the cleanup IRP
//
//	Return Value:
//		NTSTATUS
//
NTSTATUS Computer00UsbDevice::CleanUp(KIrp I)
{
	T.Trace(TraceInfo, __FUNCTION__"++.  IRP %p\n", I);

	NTSTATUS status = STATUS_SUCCESS;

	// TODO: At this point, perform custom processing for IRP_MJ_CLEANUP

	I.PnpComplete(this, status);

	T.Trace(TraceInfo, __FUNCTION__"--.  IRP %p, STATUS %x\n", I, status);

	return status;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//  Computer00UsbDevice::Invalidate
//		This method performs resource cleanup.
//		This function is called from OnStopDevice, OnRemoveDevice and
//		OnStartDevice (in error conditions).  It calls the Invalidate
//		member funcitons for each resource to free the underlying system
//		resource if allocated.  It is safe to call Invalidate more than
//		once for a resource, or for an uninitialized resource.
//
//	Arguments:
//		none
//
//	Return Value:
//		none
//
VOID Computer00UsbDevice::Invalidate()
{
	NTSTATUS status = STATUS_SUCCESS;

	status = m_Lower.DeActivateConfiguration();
	if (!NT_SUCCESS(status))
	{
		T.Trace(TraceWarning, __FUNCTION__" DeActivateConfiguration failed, STATUS %x\n", status);
	}

	m_Lower.ReleaseResources();

    // Free our registry value buffer
    if (DeviceName != NULL)
    {
        delete DeviceName;
        DeviceName = NULL;
    }

}
