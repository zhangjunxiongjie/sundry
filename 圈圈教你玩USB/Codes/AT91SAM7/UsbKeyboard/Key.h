/******************************************************************
   本程序只供学习使用，未经作者许可，不得用于其它任何用途
   
        欢迎访问我的USB专区：http://group.ednchina.com/93/
        欢迎访问我的blog：   http://www.ednchina.com/blog/computer00
                             http://computer00.21ic.org

KEY.H  file

作者：电脑圈圈
建立日期: 2008.06.27
修改日期: 2009.03.07
版本：V1.1
版权所有，盗版必究。
Copyright(C) 电脑圈圈 2008-2018
All rights reserved            
*******************************************************************/


#ifndef __KEY_H__
#define __KEY_H__

#include "MyType.h"

extern volatile uint8 KeyCurrent,KeyOld,KeyNoChangedTime;
extern volatile uint8 KeyPress;
extern volatile uint8 KeyDown,KeyUp,KeyLast;

extern volatile uint8 KeyCanChange;

void KeyInit(void);
uint8 KeyGetValue(void);
void KeyScan(void);

//误差范围
#define KEY_ERROR_RANGE 20

//无按键按下时的值
#define KEY0_VALUE 429

//各按键按下时的值
#define KEY1_VALUE 763
#define KEY2_VALUE 607
#define KEY3_VALUE 503
#define KEY4_VALUE 335
#define KEY5_VALUE 201
#define KEY6_VALUE 0

#define KEY1 0x01
#define KEY2 0x02
#define KEY3 0x04
#define KEY4 0x08
#define KEY5 0x10
#define KEY6 0x20
#define KEY7 0x40
#define KEY8 0x80

#endif
