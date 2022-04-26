/******************************************************************
   本程序只供学习使用，未经作者许可，不得用于其它任何用途
   
        欢迎访问我的USB专区：http://group.ednchina.com/93/
        欢迎访问我的blog：   http://www.ednchina.com/blog/computer00
                             http://computer00.21ic.org

SCSI.c file

作者：电脑圈圈
建立日期: 2008.08.15
修改日期: 2009.03.16
版本：V1.1
版权所有，盗版必究。
Copyright(C) 电脑圈圈 2008-2018
All rights reserved            
*******************************************************************/


#include "MyType.H"
#include "UsbCore.h"
#include "AT91SAMxUSB.h"
#include "SCSI.h"
#include "Uart.h"
#include "config.h"
#include "Led.h"
#include "SD.h"

//定义端点1最大包长度为64字节
#define EP1_SIZE 64

//定义端点2最大包长度为64字节
#define EP2_SIZE 64

uint32 ByteAddr;  //字节地址

uint8 * pEp1SendData;
uint8 * pEp2ReceiveBuf;

uint32 Ep1DataLength;
uint32 Ep2DataLength;

//INQUIRY命令需要返回的数据
//请对照书中INQUIRY命令响应数据格式
const uint8 DiskInf[36]=
{
 0x00, //磁盘设备
 0x80, //其中最高位D7为RMB。RMB=0，表示不可移除设备。如果RMB=1，则为可移除设备。
 0x00, //各种版本号0
 0x01, //数据响应格式
 0x1F, //附加数据长度，为31字节
 0x00, //保留
 0x00, //保留
 0x00, //保留
 0xB5,0xE7,0XC4,0xD4,0xC8,0xA6,0xC8,0xA6, //厂商标识，为字符串“电脑圈圈”
 
 //产品标识，为字符串“做的USB-SD读卡器”
 0xD7,0xF6,0xB5,0xC4,0x55,0x53,0x42,0x2D,0x53,0x44,0xB6,0xC1,0xBF,0xA8,0xC6,0xF7,
 0x31,0x2E,0x30,0x31 //产品版本号，为1.01
};

//READ_FORMAT_CAPACITIES命令需要返回的数据
//请对照书中READ_FORMAT_CAPACITIES命令响应数据格式
const uint8 MaximumCapacity[12]=
{
 0x00, 0x00, 0x00, //保留
 0x08,  //容量列表长度
 0x01, 0x00, 0x00, 0x00,  //块数(最大支持8GB)
 0x03, //描述符代码为3，表示最大支持的格式化容量
 //每块大小为512字节
 (SECTOR_SIZE>>16),(SECTOR_SIZE>>8),SECTOR_SIZE
};

//READ_CAPACITY命令需要返回的数据
uint8 DiskCapacity[8]=
{
 //能够访问的最大逻辑块地址
 0,
 0,
 0,
 0,
 //块的大小
 (SECTOR_SIZE>>24),
 (SECTOR_SIZE>>16),
 (SECTOR_SIZE>>8),
 SECTOR_SIZE
};

//REQUEST SENSE命令需要返回的数据，初始化为无效命令
//请参看书总数据结构的解释
uint8 SenseData[18]=
{
 0x70, //错误代码，固定为0x70
 0x00, //保留
 0x05, //Sense Key为0x05，表示无效请求（ILLEGAL REQUEST）
 0x00, 0x00, 0x00, 0x00, //Information为0
 0x0A, //附加数据长度为10字节
 0x00, 0x00, 0x00, 0x00, //保留
 0x20, //Additional Sense Code(ASC)为0x20，表示无效命令操作码（INVALID COMMAND OPERATION CODE）
 0x00, //Additional Sense Code Qualifier(ASCQ)为0
 0x00, 0x00, 0x00, 0x00 //保留
};

/********************************************************************
函数功能：设置sense数据为无效命令。
入口参数：无。
返    回：无。
备    注：无。
********************************************************************/
void SetSenseDataInvalidCommand(void)
{
 uint i;
 for(i=0;i<18;i++)
 {
  SenseData[i]=0;
 }
 SenseData[0]=0x70; //错误代码，固定为0x70
 SenseData[2]=0x05; //Sense Key为0x05，表示无效请求（ILLEGAL REQUEST）
 SenseData[7]=0x0A; //附加数据长度为10字节
 SenseData[12]=0x20; //Additional Sense Code(ASC)为0x20，表示无效命令操作码（INVALID COMMAND OPERATION CODE）
}
/////////////////////////End of function/////////////////////////////

/********************************************************************
函数功能：设置sense数据为无错误。
入口参数：无。
返    回：无。
备    注：无。
********************************************************************/
void SetSenseDataNoSense(void)
{
 uint i;
 for(i=0;i<18;i++)
 {
  SenseData[i]=0;
 }
 SenseData[0]=0x70; //错误代码，固定为0x70
 SenseData[2]=0x00; //Sense Key为0x00，表示无错误(NO SENSE)
 SenseData[7]=0x0A; //附加数据长度为10字节
 SenseData[12]=0x00; //Additional Sense Code(ASC)为0
}
/////////////////////////End of function/////////////////////////////

/********************************************************************
函数功能：从CBW中获取传输数据的字节数。
入口参数：无。
返    回：需要传输的字节数。
备    注：无。
********************************************************************/
uint32 GetDataTransferLength(void)
{
 uint32 Len;
 
 //CBW[8]~CBW[11]为传输长度（小端结构）
 
 Len=CBW[11];
 Len=Len*256+CBW[10];
 Len=Len*256+CBW[9];
 Len=Len*256+CBW[8];
 
 return Len;
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：从CBW中获取逻辑块地址LBA的字节数。
入口参数：无。
返    回：逻辑块地址LBA。
备    注：无。
********************************************************************/
uint32 GetLba(void)
{
 uint32 Lba;
 
 //读和写命令时，CBW[17]~CBW[20]为逻辑块地址（大端结构）
 
 Lba=CBW[17];
 Lba=Lba*256+CBW[18];
 Lba=Lba*256+CBW[19];
 Lba=Lba*256+CBW[20];
 
 return Lba;
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：填充CSW。
入口参数：Residue：剩余字节数；Status：命令执行的状态。
返    回：无。
备    注：无。
********************************************************************/
void SetCsw(uint32 Residue, uint8 Status)
{
 //设置CSW的签名，其实可以不用每次都设置的，
 //开始初始化设置一次就行了，这里每次都设置
 CSW[0]='U';
 CSW[1]='S';
 CSW[2]='B';
 CSW[3]='S';
 
 //复制dCBWTag到CSW的dCSWTag中去
 CSW[4]=CBW[4];
 CSW[5]=CBW[5];
 CSW[6]=CBW[6];
 CSW[7]=CBW[7];
    
 //剩余字节数
 CSW[8]=Residue&0xFF;
 CSW[9]=(Residue>>8)&0xFF;
 CSW[10]=(Residue>>16)&0xFF;
 CSW[11]=(Residue>>24)&0xFF;
 
 //命令执行的状态，0表示成功，1表示失败。
 CSW[12]=Status;
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：获取磁盘数据函数。
入口参数：无。
返    回：无。
备    注：无。
********************************************************************/
void GetDiskData(void)
{
 if(0==(ByteAddr&(SECTOR_SIZE-1)))  //如果是扇区的整数倍
 {
  //从Sd卡中读出一个扇区
  SdReadOneSector(ByteAddr,SdSectorBuf,Ep1DataLength/SECTOR_SIZE-1);
  pEp1SendData=SdSectorBuf;  //指向缓冲区首地址
 }
 ByteAddr+=EP1_SIZE; //调整字节地址，每次发送最大包长度的数据
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：将数据通过端点1发送。
入口参数：无。
返    回：无。
备    注：当发送数据长度为0，并且处于数据阶段时，将自动发送CSW。
********************************************************************/
void Ep1SendData(void)
{
 if(Ep1DataLength==0) //如果需要发送的数据长度为0
 {
  OffLed3();  //关闭LED3
  if(TransportStage==DATA_STAGE) //并且处于数据阶段
  {
   //则直接进入状态阶段
   TransportStage=STATUS_STAGE;
   Ep1DataLength=sizeof(CSW); //数据长度为CSW的大小
   pEp1SendData=CSW; //返回的数据为CSW
  }
  else
  {
   return; //如果是状态阶段的数据发送完毕，则返回
  }
 }
 
#ifdef DEBUG0
 if(TransportStage==STATUS_STAGE)
 {
  Prints("状态阶段。\r\n");
 }
#endif

 //如果要发送的长度比端点1最大包长要多，则分多个包发送
 if(Ep1DataLength>EP1_SIZE)
 {
  //发送端点1最大长度字节
  UsbChipWriteEndpointBuffer(1,EP1_SIZE,pEp1SendData);
  //指针移动EP1_SIZE字节
  pEp1SendData+=EP1_SIZE;
  Ep1DataLength-=EP1_SIZE;
  //如果是READ(10)命令，并且是数据阶段，则需要获取磁盘数据
  if((CBW[15]==READ_10)&&(TransportStage==DATA_STAGE))
  {
   GetDiskData(); //获取磁盘数据
  }
 }
 else
 {
  //可以全部发送完
  UsbChipWriteEndpointBuffer(1,(uint8)Ep1DataLength,pEp1SendData);
  Ep1DataLength=0;  //传输长度为0
  //如果是数据发送完毕，则进入仅批量传输协议的状态阶段
  if(TransportStage==DATA_STAGE)
  {
   TransportStage=STATUS_STAGE;
   Ep1DataLength=sizeof(CSW); //数据长度为CSW的大小
   pEp1SendData=CSW; //返回的数据为CSW
  }
  else if(TransportStage==STATUS_STAGE) //如果是状态阶段完毕，则进入到命令阶段
  {
   TransportStage=COMMAND_STAGE;  //进入到命令阶段
  }
 }
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：处理SCSI命令的函数。
入口参数：无。
返    回：无。
备    注：虽然叫SCSI命令，但是实际使用的是UFI命令。
********************************************************************/
void ProcScsiCommand(void)
{
 OnLed3();  //进入命令处理阶段，LED3亮。
 TransportStage=DATA_STAGE; //进入到数据阶段
 //CBW中偏移量为15的字段为命令的类型
 switch(CBW[15])
 {
  case INQUIRY:  //INQUIRY命令
  #ifdef DEBUG0
   Prints("查询命令。返回数据：\r\n");
  #endif
   pEp1SendData=(uint8 *)DiskInf; //返回磁盘信息
   Ep1DataLength=GetDataTransferLength(); //获取需要返回的长度
   SetCsw(Ep1DataLength-sizeof(DiskInf),0); //设置剩余字节数以及状态成功
   if(Ep1DataLength>sizeof(DiskInf)) //如果请求的数据比实际的要长
   {
    Ep1DataLength=sizeof(DiskInf); //则只返回实际的长度
   }
   SetSenseDataNoSense();  //设置Sense为无错误
   Ep1SendData(); //返回数据
  break;
  
  case READ_FORMAT_CAPACITIES: //读格式化容量
  #ifdef DEBUG0
   Prints("读格式化容量命令。返回数据：\r\n");
  #endif
   pEp1SendData=(uint8 *)MaximumCapacity; //返回最大格式化容量信息
   Ep1DataLength=GetDataTransferLength(); //获取需要返回的长度
   SetCsw(Ep1DataLength-sizeof(MaximumCapacity),0); //设置剩余字节数以及状态成功
   if(Ep1DataLength>sizeof(MaximumCapacity)) //如果请求的数据比实际的要长
   {
    Ep1DataLength=sizeof(MaximumCapacity); //则只返回实际的长度
   }
   SetSenseDataNoSense();  //设置Sense为无错误
   Ep1SendData(); //返回数据
  break;
  
  case READ_CAPACITY: //读容量命令
  #ifdef DEBUG0
   Prints("读容量命令。返回数据：\r\n");
  #endif
   //扇区数目，要减掉2个扇区，避免连续读、写时出错！
   if(SdCapacity!=0) //如果容量不为0
   {
    DiskCapacity[0]=(SdCapacity-2)>>24;
    DiskCapacity[1]=(SdCapacity-2)>>16;
    DiskCapacity[2]=(SdCapacity-2)>>8;
    DiskCapacity[3]=(SdCapacity-2);
    //磁盘扇区大小
    DiskCapacity[4]=(SECTOR_SIZE>>24);
    DiskCapacity[5]=(SECTOR_SIZE>>16);
    DiskCapacity[6]=(SECTOR_SIZE>>8);
    DiskCapacity[7]=SECTOR_SIZE;
   }
   else //如果容量为0
   {
    uint32 i;
    for(i=0;i<8;i++)
    {
     DiskCapacity[i]=0;
    }
   }
   pEp1SendData=(uint8 *)DiskCapacity; //返回磁盘容量
   Ep1DataLength=GetDataTransferLength(); //获取需要返回的长度
   SetCsw(Ep1DataLength-sizeof(DiskCapacity),0); //设置剩余字节数以及状态成功
   if(Ep1DataLength>sizeof(DiskCapacity)) //如果请求的数据比实际的要长
   {
    Ep1DataLength=sizeof(DiskCapacity); //则只返回实际的长度
   }
   SetSenseDataNoSense();  //设置Sense为无错误
   Ep1SendData(); //返回数据
  break;
  
  case READ_10: //READ(10)命令
  #ifdef DEBUG0
   Prints("READ(10)命令。返回数据：\r\n");
  #endif
   Ep1DataLength=GetDataTransferLength(); //获取需要返回的长度
   ByteAddr=GetLba()*SECTOR_SIZE; //获取字节地址，字节地址为逻辑块地址乘以每块大小
   SetCsw(0,0); //设置剩余字节数为0，状态成功
   SetSenseDataNoSense();  //设置Sense为无错误
   GetDiskData(); //获取需要返回的数据
   Ep1SendData(); //返回数据
  break;
  
  case WRITE_10: //WRITE(10)命令
  #ifdef DEBUG0
   Prints("WRITE(10)命令。输出数据：\r\n");
  #endif

   Ep2DataLength=GetDataTransferLength(); //获取需要写数据的长度
   pEp2ReceiveBuf=SdSectorBuf; //准备接收数据
   ByteAddr=GetLba()*SECTOR_SIZE; //获取字节地址，字节地址为逻辑块地址乘以每块大小
   SetSenseDataNoSense();  //设置Sense为无错误
   SetCsw(0,0); //设置剩余字节数为0，状态成功
  break;
  
  case PREVENT_ALLOW_MEDIUM_REMOVAL:  //是否可移除
  #ifdef DEBUG0
   Prints("PREVENT_ALLOW_MEDIUM_REMOVAL命令。返回SENSE数据：\r\n");
  #endif
   //CBW[19]的最低位表示是否可以移除磁盘，0表示可以，1表示不可以。
   //这里用来控制LED显示。当设置为1时，LED4亮；当设置为0时，LED4灭
   if(CBW[19]&0x01) 
   {
    OnLed4();
   }
   else
   {
    OffLed4();
   }
   Ep1DataLength=0; //设置长度为0，发送数据将返回CSW
   SetSenseDataNoSense();  //设置Sense为无错误
   SetCsw(0,0); //设置CSW为成功
   Ep1SendData(); //返回CSW
  break;
  
  case VERIFY:  //校验，这里认为数据总是对的
  #ifdef DEBUG0
   Prints("VERIFY命令。返回SENSE数据：\r\n");
  #endif
   Ep1DataLength=0; //设置长度为0，发送数据将返回CSW
   SetSenseDataNoSense();  //设置Sense为无错误
   SetCsw(0,0); //设置CSW为成功
   Ep1SendData(); //返回CSW
  break;
  
  case REQUEST_SENSE: //该命令询问前一个命令执行失败的原因
  #ifdef DEBUG0
   Prints("REQUEST SENSE命令。返回SENSE数据：\r\n");
  #endif
   pEp1SendData=(uint8 *)SenseData; //返回探测数据
   Ep1DataLength=GetDataTransferLength(); //获取需要返回的长度
   SetCsw(Ep1DataLength-sizeof(SenseData),0); //设置剩余字节数以及状态成功
   if(Ep1DataLength>sizeof(SenseData)) //如果请求的数据比实际的要长
   {
    Ep1DataLength=sizeof(SenseData); //则只返回实际的长度
   }
   Ep1SendData(); //返回数据
  break;
  
  case TEST_UNIT_READY: //测试磁盘是否准备好
   Ep1DataLength=0; //设置长度为0，发送数据将返回CSW
   SetSenseDataNoSense();  //设置Sense为无错误
   SetCsw(0,0); //设置CSW为成功
   Ep1SendData(); //返回CSW
  break;
  
  default: //其它命令不认，返回执行失败
   if(CBW[12]&0x80) Ep1DataLength=1; //如果为输入请求，则随便返回1字节
   else Ep1DataLength=0; //否则为输出请求，则设置长度为0，直接返回CSW
   SetCsw(GetDataTransferLength()-Ep1DataLength,1); //设置CSW为失败
   SetSenseDataInvalidCommand();  //设置为无效命令
   Ep1SendData(); //返回CSW
  break;
 }
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：处理输出数据。
入口参数：无。
返    回：无。
备    注：无。
********************************************************************/
void ProcScsiOutData(void)
{
 uint8 Len;
 //读端点2数据
 Len=UsbChipReadEndpointBuffer(2,EP2_SIZE,pEp2ReceiveBuf);
 //清除端点缓冲区
 UsbChipClearBuffer(2); 
 Ep2DataLength-=Len; //调整剩余长度
 pEp2ReceiveBuf+=Len; //调整接收缓冲区
 ByteAddr+=Len; //调整地址
 if(0==(ByteAddr&(SECTOR_SIZE-1))) //如果地址是扇区整数倍，则需要写数据到Sd卡
 {
  //写一个扇区数据。注意地址要调整到扇区的开始处
  SdWriteOneSector(ByteAddr-SECTOR_SIZE,SdSectorBuf,Ep2DataLength/SECTOR_SIZE);
  pEp2ReceiveBuf=SdSectorBuf; //设置接收缓冲区地址
 }
 
 //数据传输完毕，进入到状态阶段
 if(Ep2DataLength==0)
 {
  Ep1DataLength=0;
  //此时Ep1DataLength为0，并且处于数据阶段，调用发送数据函数将返回CSW
  Ep1SendData();
 }
}
////////////////////////End of function//////////////////////////////