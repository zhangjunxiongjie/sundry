/******************************************************************
   本程序只供学习使用，未经作者许可，不得用于其它任何用途

        欢迎访问我的USB专区：http://group.ednchina.com/93/
        欢迎访问我的blog：   http://www.ednchina.com/blog/computer00
                             http://computer00.21ic.org

UART.C  file

作者：电脑圈圈
建立日期: 2008.06.27
修改日期: 2009-05-10
版本：V1.1
版权所有，盗版必究。
Copyright(C) 电脑圈圈 2008-2018
All rights reserved            
*******************************************************************/

#include <90USB162.H>
#include "UART.h"
#include "MyType.h"
#include "config.h"
#include "Led.h"

#if (defined DEBUG0)||(defined DEBUG1)
/********************************************************************
函数功能：串口中断处理。
入口参数：无。
返    回：无。
备    注：无。
********************************************************************/
interrupt [USART1_RXC] void Uart0Isr(void)
{
 //(unsigned char)(UDR1);  //读取数据
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：串口初始化。
入口参数：无。
返    回：无。
备    注：无。
********************************************************************/
void Uart1Init(void)
{
 // USART1 initialization
 // Communication Parameters: 8 Data, 1 Stop, No Parity
 // USART1 Receiver: On
 // USART1 Transmitter: On
 // USART1 Mode: Asynchronous
 // USART1 Baud Rate: 9600
 UCSR1A=0x00;
 UCSR1B=0x98;  //接收中断使能，允许接收、发送
 UCSR1C=0x06;
 UBRR1H=0x00;
 UBRR1L=0x67;
 DDRD|=1<<3; //PD3设置为输出
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：往串口发送一字节数据。
入口参数：d: 要发送的字节数据。
返    回：无。
备    注：无。
********************************************************************/
void UartPutChar(uint8 d)
{
 while(!((UCSR1A)&(1<<5))); //等待发送完毕
 UDR1=d;  //发送数据
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：发送一个字符串。
入口参数：pd：要发送的字符串指针。
返    回：无。
备    注：无。
********************************************************************/
void Prints(flash uint8 * pd)
{
 while((*pd)!='\0') //发送字符串，直到遇到0才结束
 {
  UartPutChar(*pd); //发送一个字符
  pd++;  //移动到下一个字符
 }
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：发送一个字符串。
入口参数：pd：要发送的字符串指针。
返    回：无。
备    注：无。
********************************************************************/
void PrintsRam(uint8 * pd)
{
 while((*pd)!='\0') //发送字符串，直到遇到0才结束
 {
  UartPutChar(*pd); //发送一个字符
  pd++;  //移动到下一个字符
 }
}
////////////////////////End of function//////////////////////////////

#ifdef DEBUG1

/********************************************************************
函数功能：将整数转按十进制字符串发送。
入口参数：x：待显示的整数。
返    回：无。
备    注：无。
********************************************************************/
void PrintLongInt(uint32 x)
{
 int8 i;
 uint8 display_buffer[10];

 for(i=9;i>=0;i--)
 {
  display_buffer[i]='0'+x%10;
  x/=10;
 }
 for(i=0;i<9;i++)
 {
  if(display_buffer[i]!='0')break;
 }
 for(;i<10;i++)UartPutChar(display_buffer[i]);
}
////////////////////////End of function//////////////////////////////

#endif

const uint8 HexTable[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
/********************************************************************
函数功能：将短整数按十六进制发送。
入口参数：待发送的整数。
返    回：无。
备    注：无。
********************************************************************/
void PrintShortIntHex(uint16 x)
{
 uint8 i;
 uint8 display_buffer[7];
 display_buffer[6]=0;
 display_buffer[0]='0';
 display_buffer[1]='x';
 for(i=5;i>=2;i--) //将整数转换为4个字节的HEX值
 {
  display_buffer[i]=HexTable[(x&0xf)];
  x>>=4;
 }
 PrintsRam(display_buffer);
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：将长整数按十六进制发送。
入口参数：待发送的整数。
返    回：无。
备    注：无。
********************************************************************/
void PrintLongIntHex(uint32 x)
{
 uint8 i;
 uint8 display_buffer[11];
 display_buffer[10]=0;
 display_buffer[0]='0';
 display_buffer[1]='x';
 for(i=9;i>=2;i--) //将整数转换为4个字节的HEX值
 {
  display_buffer[i]=HexTable[(x&0xf)];
  x>>=4;
 }
 PrintsRam(display_buffer);
}
////////////////////////End of function//////////////////////////////

#if (defined DEBUG0)||(defined DEBUG1)
/********************************************************************
函数功能：发送一个byte的数据。
入口参数：待发送的数据。
返    回：无。
备    注：无。
********************************************************************/
void Printc(uint8 x)
{
 UartPutChar(x);
}
////////////////////////End of function//////////////////////////////

/********************************************************************
函数功能：以HEX格式发送一个byte的数据。
入口参数：待发送的数据
返    回：无。
备    注：无。
********************************************************************/
void PrintHex(uint8 x)
{
 Printc('0');
 Printc('x');
 Printc(HexTable[x>>4]);
 Printc(HexTable[x&0xf]);
 Printc(' ');
}
////////////////////////End of function//////////////////////////////
#endif
#endif
