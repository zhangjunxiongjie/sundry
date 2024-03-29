/******************************************************************
   本程序只供学习使用，未经作者许可，不得用于其它任何用途
			
        欢迎访问我的USB专区：http://group.ednchina.com/93/
        欢迎访问我的blog：   http://www.ednchina.com/blog/computer00
                             http://computer00.21ic.org

        感谢PCB赞助商——电子园： http://bbs.cepark.com/

KEY.H  file

作者：电脑圈圈
建立日期: 2008.06.27
修改日期: 2008.06.27
版本：V1.1
版权所有，盗版必究。
Copyright(C) 电脑圈圈 2008-2018
All rights reserved            
*******************************************************************/


#ifndef __KEY_H__
#define __KEY_H__

#include <at89x52.h>
#include "MyType.h"

extern volatile uint8 idata KeyCurrent,KeyOld,KeyNoChangedTime;
extern volatile uint8 idata KeyPress;
extern volatile uint8 idata KeyDown,KeyUp,KeyLast;

extern volatile uint8 KeyCanChange;

// 按键端口变量初始化
void InitKeyboard(void);

// 按键读取端口
#define KeyIO P1

// 获取按键值的宏。由于开关按下为0，所以对结果取反
#define GetKeyValue() (~KeyIO)

// 
#define KEY1 0x01 // 鼠标左移
#define KEY2 0x02 // 鼠标右移
#define KEY3 0x04 // 鼠标上移
#define KEY4 0x08 // 鼠标下移
#define KEY5 0x10 // 滚轮往下
#define KEY6 0x20 // 滚轮往上
#define KEY7 0x40 // 鼠标左键
#define KEY8 0x80 // 鼠标右键

#endif
