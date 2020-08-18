# 8051 汇编语言程序设计概述



## 汇编语言概述



### 程序与指令



- 程序是指令的有序集合。
- 单片机运行就是执行指令序列的过程。
- 编写这一指令序列的过程称为编程设计或程序设计。
- 单片机编程语言常见为汇编语言与 C51 高级语言。
- 汇编语言：用英文字符表示指令，这些英文字符被称为助记符。 
- 汇编语言源程序：用汇编语言编写的应用程序。
- 汇编语言与微处理器硬件紧密相关。
- “汇编”：汇编语言源程序需转换（翻译）成为二进制代码表示的机器语言程序，才能识别和执行。
- 完成 “翻译” 的程序称为汇编程序。经汇编程序 “汇编” 得到的以 “0”、“1” 代码形式的机器语言程序称为目标程序。
- 优点：用汇编语言编写程序效率高，占用存储空间小，运行速度快，能编写出最优化的程序。
- 缺点：可读性差，离不开具体的硬件，是面向 “硬件” 的语言，通用性较差。



### 高级语言

- 不受微处理器具体 “硬件” 的限制，优点：通用性强，直观、易懂、易学，可读性好。
- 目前多数 8051 单片机用户使用 C 语言（C51）来进行程序设计，已公认为高级语言中高效简洁而又贴近 51 单片机硬件的编程语言。
- 将 C 语言向单片机上移植，始于20世纪80年代的中后期。
- 经过十几年努力，C51 已成为单片机的实用高级编程语言。
- 尽管目前已有不少设计人员使用 C51 来进行程序开发，但在对程序的空间和时间要求较高的场合，汇编语言仍必不可少。
- 在这种场合下，可使用 C 语言和汇编语言混合编程。在很多需要直接控制硬件且对实时性要求较高的场合，则更是非用汇编语言不可。
- 掌握汇编语言并能进行程序设计，是学习和掌握单片机程序设计的基本功之一。



### 汇编语言语句和格式



**汇编语言源程序子程序使用 RET 结束，中断子程序使用 RETI 结束，整个源程序使用 END 结束。**



**两种基本语句：指令语句和伪指令语句。**

1. 指令语句
   每一指令语句在汇编时都产生一个指令代码（机器代码），执行该指令代码对应着机器的一种操作。
2. 伪指令语句
   是控制汇编（翻译）过程的一些控制命令。在汇编时没有机器代码与之对应。

**下面介绍指令语句格式。**

汇编语言语句是符合典型的汇编语言的四分段格式：

**标号（LABLE） + 操作码（OPCODE）+ 操作数（OPRAND）+ 注释（COMMENT）**

- 标号字段和操作码字段之间要有冒号“：”分隔。
- 操作码字段和操作数字段间的分界符是空格。
- 双操作数之间用逗号相隔。
- 操作数字段和注释字段之间的分界符用分号“；”。
- 任何语句都必须有操作码字段，其余各段为任选项。

1. 标号字段
   语句所在地址的标志符号，才能被访问。如标号“START”和“LOOP”等。有关标号规定如下：
   - 标号后必须跟冒号“：”。
   - 标号由 1～8 个 ASCII 码字符组成，第一个字符必须是字母。
   - 同一标号在一个程序中只能定义一次，不能重复定义。
   - 不能使用汇编语言已经定义的符号作为标号，如指令助记符、伪指令以及寄存器的符号名称等。
   - 标号的有无，取决于本程序中的其他语句是否访问该条语句。如无其他语句访问，则该语句前不需标号。

2. 操作码字段
   规定了语句执行的操作，操作码是汇编语言指令中唯一不能空缺的部分。

3. 操作数表示时，需注意两种情况：
   （1）十六进制、二进制和十进制形式的操作数表示

   - 多数情况，操作数或操作数地址是采用十六进制形式来表示的。则需加后缀“H”。
   - 在某些特殊场合用二进制表示，需加后缀“B”。
   - 若操作数采用十进制形式，则需加后缀“D”，也可省略。
   - 若十六进制操作数以字符A～F开头，需在它前面加一个 “0”，以便汇编时把它和字符A～F区别开。

   （2）工作寄存器和特殊功能寄存器的表示

   - 当操作数为工作寄存器或特殊功能寄存器时，允许用工作寄存器和特殊功能寄存器的代号表示。
   - 例如，工作寄存器用R7～R0，累加器用A（或Acc）表示。另外，工作寄存器和特殊功能寄存器也可用其地址表示，如累加器A可用其地址 E0H 来表示。

4. 注释字段

   - 用于解释指令或程序的含义，对可读性非常有用。
   - 使用时须以分号开头，长度不限，一行写不下可换行书写，但注意也要以分号开头
   - 汇编时，遇到“；” 就停止“翻译”。因此，注释字段不会产生机器代码。





## 汇编程序实例



### 延时算法

**1、相关的名词**

（1）时钟周期
	时钟周期也称为（晶体）振荡周期，一个时钟周期＝1 / （时钟）晶振的频率。
（2）状态周期
	状态周期是振荡频率经 2 分频后得到的周期，一个状态周期为时钟周期的 2 倍。
（3）机器周期
	单片机在工作时，通常把一条指令的执行过程划分为若干个阶段，每一阶段完成一项工作。例如，取指令、存储器读、写等，每一项工作就称为一个基本操作。完成一个基本操作所需要的时间称为机器周期。一个机器周期＝6 个状态周期＝12 个时钟周期。如果晶振频率为12MHZ，则一个机器周期＝ 12 ×（1/12000000）＝1μs 。
（4）指令周期
	执行一条指令所需要的时间称为指令周期，一般由若干个机器周期组成，指令不同，所需的机器周期也不同。51 单片机的指令有单字节、双字节和三字节的。一般单字节、双字节指令和三字节指令都是双机器周期，只有乘、除指令占用 4 个机器周期。一个单周期指令包含一个机器周期，如果晶振频率为 12MHZ。则执行一条单周期指令所用的时间＝ 1μs，执行双周期指令所用的时间＝ 2μs 进行编程时， 在完成相同任务的情况下， 选用占用机器周期少的指令会提高程序的执行效率， 特别是在编写大型程序的时， 其效果更加明显。

**2、延时子程序延时时间的精确计算**

实例 1：约 50ms 的延时子程序
源程序如下：

| 延时子程序 DELAY: | 指令执行次数       | 耗时 = 指令周期 * 指令执行次数 |
| ----------------- | ------------------ | ------------------------------ |
| MOV R7, #200      | 1 次               | 1 * 1 = 1μs                    |
| D1: MOV R6, #125  | R7 次 = 200        | 1 * 200 = 200μs                |
| D2: DJNZ R6, D2   | R6 * R7 次 = 25000 | 2 * 25000 = 50000μs            |
| DJNZ R7, D1       | R7 次 = 200        | 2 * 200 = 400μs                |
| RET               | 1 次               | 2 * 1 = 2μs                    |
|                   |                    | 延时时间 = 50603μs             |



实例 2：约 1 秒的延时子程序
源程序如下：

| 延时子程序 DELAY: | 指令执行次数            | 耗时 = 指令周期 * 指令执行次数 |
| ----------------- | ----------------------- | ------------------------------ |
| MOV R7, #10       | 1 次                    | 1 * 1 = 1μs                    |
| D1: MOV R6, #200  | R7次 = 10               | 1 * 10 = 10μs                  |
| D2: DJNZ R5, #250 | R6 * R7次 = 2000        | 1 * 2000 = 2000μs              |
| DJNZ R5, $        | R5 * R6 * R7次 = 500000 | 2 * 500000 = 1000000μs         |
| DJNZ R6, D2       | R6 * R7次 = 2000        | 2 * 2000 = 4000μs              |
| DJNZ R7, D1       | R7次 = 10               | 2 * 10 = 20μs                  |
| RET               | 1 次                    | 2 * 1 = 2μs                    |
|                   |                         | 延时时间 = 1006033μs           |



**延时程序示例：设晶振频率为 12MHZ 则时钟周期为 1 / 12us，机器周期为 1us，指令周期 试编制 50ms 延时子程序。**

```asm
DEL50MS:
	MOV R7, #200 ; 1US
	DEL1:
		MOV R6, #123 ; 1us * 200
		NOP ; 1us * 200
		DEL2:
			DJNZ R6, DEL2 ; 2us * 123 * 200
 		
		DJNZ R7, DEL1 ; 2us * 200
	
	RET ; 2us
	
	; 延时时间 (1 + 1 + 2 * 123 + 2) * 200 + 1 + 2 = 50003 us = 50.003 ms
```



### 寻址方式



```asm
; 六种寻址方式：寄存器寻址，直接寻址，立即寻址，寄存器间接寻址，变址间接寻址，相对寻址。

MOV 40H, #36H ; 目的操作数（地址：40H）使用直接寻址，源操作数（ #36H ）使用立即寻址 （40H） ← 36H

MOV R0, #40H ; 寄存器寻址，立即寻址 （R0） ← 40H

MOV A, R0 ; 直接寻址，寄存器寻址。（A） ← （R0）

MOV A, @R0 ; 直接寻址，寄存器间接寻址 （A） ← （（R0））==（40H）== 36H 

MOV DPTR，#1234H ; 直接寻址，立即寻址 （DPTR） ← 1234H

MOVC A, @A + DPTR ; 直接寻址，变址间接寻址（基址寄存器 + 变址寄存器间接寻址）（A） ← （（A） + （DPTR））=（36H + 1234H）

AJMP START ; 相对寻址，START 位置标号。
```



### 内部数据外移



**功能描述：将内部数据存储器 30H - 37H 单元的内容传送到外部数据存储器以 1000H 开始的连续单元中。**

```asm
ORG 0000H

MOV R0, #30H
MOV DPTR, #1000H
MOV R7, #8 ; 移动的字节数
LP:
	MOV A, @R0 ; 寄存器间接寻址
	MOVX @DPTR, A ; 将数据外移
	INC R0 ; 
	INC DPTR ; 
	DJNZ R7, LP ; 减一为零则跳转

END
```



### 数值运算



**功能描述：判断 30H 的值如果大于 0 则输出 1 到 31H，否则如果等于 0 则输出 0 到 31H，否则如果小于 0 则输出 -1 到 31H。即实现分段函数：**
$$
Y = \begin{Bmatrix}
 1,  & X > 0 & \\ 
 0,  & X = 0 & \\
 -1, & X < 0 &
\end{Bmatrix}
$$


```asm
; 31H 存放 Y， 30H 存放 X
ORG 0000H

MOV A, 30H
JZ EXIT ; 如果 A = 0 则跳转至 EXIT。 X = 0
JB ACC.7, MINUS ; 如果 符号位为 1 则跳转至 MINUS。 X < 0
MOV A, #01H ; X > 0

AJMP EXIT

MINUS:
	MOV A, #0FFH

EXIT:
	MOV 31H, A

END
```



**功能描述：查表法实现简单的平方和**

```asm
ORG 0000H
LJMP MAIN
ORG 0100H
MAIN:
	MOV SP, #3FH ; 设置堆栈起始地址
	MOV A, 31H ; 一个乘数
	LCALL SQR  ; 使用查表法计算平方 
	MOV R1, A ; 存储平方结果
	MOV A, 32H ; 另一个乘数
	LCALL SQR ; 计算另一个数的平方
	ADD A, R1 ; 计算加和
	MOV 33H, A ; 存储平方和结果
	SJMP $

ORG 0200H
SQR:
	ADD A, #01H
	MOVC A, @A ＋ PC
	RET
TAB:
	DB 0, 1, 4, 9, 16, 25
	DB 36, 49, 64, 81

END
```





### MCU 简单控制



**LCALL DELAY ：LCALL 称为子程序调用指令，指令后面的参数 DELAY 是一个标号，用于标识第 6 行程序，执行 LCALL 指令时，程序转到 LCALL 后面的标号所指示的程序行处执行，如果执行指令过程中遇到 RET 指令，则程序就返回到 LCALL 指令下面的一条指令继续执行。**

**RET 指令的作用是：子程序在执行过程中如果遇到这条指令，会返回到主程序， 到调用这段子程序指令的下一条指令继续执行。**



**功能描述：从 P1.0 口输出方波控制 LED 持续闪烁。**

```asm

MAIN:
	SETB P1.0 
    LCALL DELAY 
    CLR P1.0 
    LCALL DELAY 
    LJMP MAIN 
    
DELAY: ; 延时子程序
    MOV R7，#250 
    D1:
    	MOV R6，#250 
    	D2:
    		DJNZ R6，D2 
    	DJNZ R7，D1 
    RET 
END 
```



**功能描述：从 P1 的高四位输入，输出到 P1 的低四位。**

```asm
ORG 00H 
START: 
	MOV A, P1 ; 从 P1 输入
	ANL A, #0F0H ; 位与
	RR A  ; 不带进位循环右移四位
	RR A 
	RR A 
	RR A 
	ORL A, #0F0H  ; 位或
	MOV P1, A  ; 输出到 P1
	SJMP START 
END 
```



**功能描述：使用 P1 高四位输入控制低四位输出。**

```asm
ORG 00H 
START: 
	JB P1.4, NEXT1 ; P1.4 控制 P1.0
	CLR P1.0 
	SJMP NEX1 
NEXT1: 
	SETB P1.0 
	
NEX1: 
	JB P1.5, NEXT2 ; P1.5 控制 P1.1
	CLR P1.1 
	SJMP NEX2 
NEXT2: 
	SETB P1.1 

NEX2: 
	JB P1.6, NEXT3 ; P1.6 控制 P1.2
	CLR P1.2 
	SJMP NEX3 
NEXT3: 
	SETB P1.2 
	
NEX3: 
	JB P1.7, NEXT4 ; P1.7 控制 P1.3 
	CLR P1.3 
	SJMP NEX4 
NEXT4: 
	SETB P1.3 
NEX4: 
	SJMP START 

END 
```



**功能描述：顺序查表控制 P1 输出。**

```asm
ORG 0 
START: 
	MOV DPTR, #TABLE 
LOOP: 
	CLR A ; 清零
	MOVC A, @A+DPTR ; 取数据
	CJNE A, #01H, LOOP1 ; 如果取得的数据不为最后一个数据标志位则跳
	JMP START 
LOOP1: 
	MOV P1, A ; 将取得的数据输出
	MOV R3, #20 
	LCALL DELAY 
	INC DPTR ; 指向下一个数据地址 
	JMP LOOP 
DELAY: 
	MOV R4, #20 
	D1: 
		MOV R5, #248 
		DJNZ R5, $ 
		DJNZ R4, D1 
	DJNZ R3, DELAY 
	RET 

ABLE: 
DB 0FEH,0FDH,0FBH,0F7H 
DB 0EFH,0DFH,0BFH,07FH 
DB 0FEH,0FDH,0FBH,0F7H 
DB 0EFH,0DFH,0BFH,07FH 
DB 07FH,0BFH,0DFH,0EFH 
DB 0F7H,0FBH,0FDH,0FEH 
DB 07FH,0BFH,0DFH,0EFH 
DB 0F7H,0FBH,0FDH,0FEH 
DB 00H, 0FFH,00H, 0FFH 
DB 01H  ; 数据结束标志位
END 
```



**功能描述：顺序循环查表控制 P1 输出。** 

```asm
ORG 0000H 
AJMP MAIN 
ORG 0030H 
MAIN: 
	MOV R1, #0 
	MOV DPTR, #TABLE ;把 TABLE 表中数据的首地址以立即数的形式赋给数据指针 DPTR。TABLE 是一个 “表”的标号，它后面一般是放固定数据表格的。
	MOV A, R1 
	LOOP: 
		MOVC A, @A+DPTR ;查表指令，查询（A+DPTR）地址中的值，将查询的结果放在 A 中。一般要查的表是一个顺序表，DPTR是表中数据的首地址， A 称为偏移量，调整 A 的值可以查询表中指定位置的数据。
		MOV P1, A 
		LCALL DELAY ;调用延时子程序。
		INC R1 ; 寄存器 R1 中的数值自加。
		MOV A, R1 ; 
		CJNE A, #8, LOOP ;若 A 中的值不等于 8，跳转到 LOOP 标号所指的程序处，若等于 8，执行下一条指令。
		AJMP MAIN ; 等于 8，跳转到 MAIN 标号所指的程序处。

DELAY: 	;延时子程序。
	MOV R4, #5 
	D1:
		MOV R3, #200 
		D2:
			MOV R2, #250 
			DJNZ R2,$ 
			DJNZ R3,D2 
		DJNZ R4,D1 
	RET 
	
TABLE: ;数据表，DB 是条伪指令，用于定义字节内容。
DB 11111110B 
DB 11111101B 
DB 11111011B 
DB 11110111B 
DB 11101111B 
DB 11011111B 
DB 10111111B 
DB 01111111B

END 
```



**功能描述：使用 8 * 8 点阵根据 P1.7 的不同输入情况显示不同的字符。**

```asm
ORG 0000H 
START: 
	JB P1.7, DIR1 ; P1.7 为 1 时跳，否则顺序执行。
	MOV DPTR, #TABLE1 ; 数据指针
	SJMP DIR 
DIR1: 
	MOV DPTR, #TABLE2 
DIR: 
	MOV R0, #00H 
	MOV R1, #01H 
NEXT: 
	MOV A, R0 
	MOVC A, @A+DPTR ;　读入数据 
	MOV P0, A ; 输出
	MOV A, R1 
	MOV P2, A 
	LCALL DAY ; 延时
	INC R0  ; 变址寻址
	RL A ; 不带进位循环左移
	MOV R1, A ; 
	CJNE R1, #0DFH, NEXT ;  
	SJMP START 

DAY: 
	MOV R6, #4 
	D1: 
		MOV R7, #248 
		DJNZ R7, $ 
		DJNZ R6, D1 
	RET 

; 两个不同字符的字形码数据
TABLE1: DB 06H,5BH,4FH,66H,6DH 
TABLE2: DB 78H,79H,38H,38H,3FH 
END
```



**功能描述：流水灯控制。**

```asm
ORG 00H ; 程序上电从 00H 开始
MAIN:
	MOV A, #0FEH ; 给 A 赋值为 1111 1110 
LOOP:
	MOV P1, A  ; 将 A 送到 P1 口， 发光二极管低电平点亮
	LCALL DELAY ; 调用延时子程序
	RL A ; 累加器 A 循环左移
	AJMP LOOP ; 重新送 P1 显示

; 延时子程序
DELAY: 
	MOV R3, #20
	D1:
		MOV R4, #50
		D2:
			MOV R5, #250
			DJNZ R5, $
		DJNZ R4, D2
	DJNZ R3, D1
	
	RET
END
```



### 定时计数控制



**功能描述：使用定时计数器计数每计五个数输出一个高电平直到再输入一个计数脉冲重新开始程序。查询方式**

```asm
ORG 0000H
SETB P1.0 ; 初始化

START:
	MOV TMOD, #50H ; 设置 T1 工作方式为 1 计数
	
	MOV TH1, #0FFH ; 初始化
	MOV TL1, #0FBH
	SETB TR1 ; 启动计数器

WAIT:
	; TF1 定时计数器 T1 的溢出标志位
	JNB TF1, WAIT ; 等待溢出，因为 TL1 初值为 #0FBH 所以按下五次后溢出
	CLR TF1 ; 清零溢出标志位
	CLR P1.0 ; 点亮 P1.0

LOOP:
	MOV A, TL1 
	CJNE A, #01H, LOOP ; 等待再次按键，再次按键后继续执行
	SETB P1.0 ;　
	JMP START
END
		
```



**功能描述：使用定时计数器计数每计五个数输出一个高电平直到再输入一个计数脉冲重新开始程序。中断方式**

```asm
ORG 0000H
AJMP MAIN

ORG 001BH
AJMP IR_T1 ; 定时计数器1 中断入口地址

MAIN:
	SETB P1.0 ; 初始化输出端口
	ACALL INIT_T1 ; 计数器初始化
WAIT:
	JMP WAIT ; 等待中断
	
INIT_T1:
	MOV TMOD, #50H ; 设置定时计数器1 工作模式为方式1 计数模式
	
	MOV TH1, #0FFH
	MOV TL1, #0FBH ; 设置定时计数器初值
	
	SETB EA ; 开总中断
	SETB ET1 ; 开定时计数器1中断
	SETB TR1 ; 定时计数器开始运行

	RET

IR_T1:
	CLR P1.0 ; 按键按下五次则溢出发生中断
	
	LOOP:
		MOV A, TL1 ; 等待再次按下则跳出 LOOP
		JZ LOOP ; 根据累加寄存器 A 的值决定是否跳转，A 为 0 时在此处等待
		; 这里应该有按键延时防抖
		
	SETB P1.0
	ACALL INIT_T1 ; 重新初始化并等待中断
	RETI
	
END
```



**功能描述：七段数码管秒表 60s 一个循环。**

```asm
Second EQU 30H 
ORG 0000H 

START:
	MOV Second, #00H ; 当前秒数
	
NEXT:
	MOV A, Second 
	MOV B, #10
	DIV AB ; 除法运算
	MOV DPTR, #TABLE ;  
	MOVC A, @A+DPTR 
	MOV P0, A ; 输出十位数值 
	MOV A, B 
	MOVC A, @A+DPTR 
	MOV P2, A  ; 输出个位数值
	LCALL DELY1S ; 延时一秒 
	INC Second ; 
	MOV A, Second 
	CJNE A, #60, NEXT 
	LJMP START 

DELY1S:
	MOV R5, #100
	D2:
		MOV R6, #20
		D1:
			MOV R7, #248
			DJNZ R7, $
			DJNZ R6, D1
		DJNZ R5,D2
	RET 

TABLE:
	DB 3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH 

END
```



### 中断控制



**功能描述：外部中断使用。**

```asm
ORG 0000H
AJMP START
ORG 0003H ; 中断子程序入口
AJMP INT0

ORG 0030H
START:
	MOV SP, #050H ; 堆栈地址
	MVO A, #0FFH ; 初值
	MOV P1, #0FFH ; 初值
	
	SETB IT0 ; 外部中断 0 触发方式，边沿触发。
	SETB EX0 ; 开外部中断允许
	SETB EA ; 开中断总开关
	SJMP $ ; 

INT0:
	CLR C ; 清零 CY 进位位
	RLC A ; 带进位左移
	MOV P1, A ; 输出
	CJNE A, #0H, EXIT ; 如果 A 所有位均为 0 则重置为全 1，否则退出。
	MOV A, #0FFH 

EXIT:
	RETI
	END
```



**功能描述：外部信号触发中断使用方法。**

```asm
ORG 0000H
JMP START
ORG 0003H ; 外部信号触发中断 0 入口地址
JMP INT_0

START:
	MOV IE, #10000001B ; 开中断总开关和外部信号触发中断开关
	MOV SP, #30H ; 设定堆栈地址
	SETB IT0 ; 设置外部信号中断触发方式，此处设置为边沿触发
	MOV A, #0 ; 清零

LOOP: ; 
	MOV P2, A
	CALL DELAY ;
	CPL A ; 取反
	JMP LOOP ;
	
IN_0: ; 中断子程序定义
	PUSH ACC ; 累加器入出栈时不能用简称 A
	PUSH PSW ; 将程序状态控制字入栈
	SETB RS0 ; 切换工作寄存器，总共 4 组可用的工作寄存器 控制位位于 PSW
	
	... ; 其它工作
	
	POP PSW ; 
	POP ACC ; 出栈
	
	RETI ; 返回主程序
	
```



### 串行通信



**功能描述：两机动作相同，都将 P1 发送给对方然后接收信息输出到 P2。**

```asm
; 甲乙两机程序相同

ORG 0000H 
MAIN:
	MOV TMOD, #2OH ; 设置定时计数器工作方式
	MOV TH1, #OF4H ; 设置定时计数器初值
	MOV TL1, #OF4H  
	MOV PCON, #00H ; 设置波特率倍增位
	MOV SCON, #50H  ; 设置串行工作方式，允许接收数据
	SETB TR1  ; 启动定时计数器
	MOV SBUF, P1 ; 发送数据
	
	JNB TI, $ ; 等待发送数据结束
	CLR TI ;
    JNB RI,$ ; 等待接收数据结束
	CLR RI 
	MOV P2, SBUF ; 将接收数据输出
	JMP MAIN ; 

END
```



**功能描述：串行通信接收端，定时计数器 T1 提供波特率。**

```asm
; 接收端
ORG 0000H
START:
	MOV TMOD, #20H ; 设置定时计数器1 为工作方式2
	MOV TL1, #0FDH ; 定时计数器初值， 波特率为 9600，还与晶振频率有关。
	MOV TH1, #0FDH
	
	SETB TR1 ; 启动定时计数器
	MOV SCON, #50H ; 设置串行口工作方式 1，且允许接收
LOOP:
	JNB RI, LOOP ; 判断接收是否完成，串口数据接收标志位
	CLR RI ; 清接收标志位
	CPL P1.0 ; 取反
	SJMP LOOP
END

```



**功能描述：通过并行口接收八位数据，通过串行口发给 74LS164 ，74LS164（移位寄存器，串转并）接收数据后将数据输出到并行口。**

```asm
ORG 00H
START:
	MOV SCON, #0H ; 设置串行口端口工作模式。
	MOV P2, #00FFH ; 输入口初始化。
LOOP:
	MOV A, P2 
	MOV SBUF, A ; 将内容传递到缓冲寄存器
	JNB TI, $  ; 等待串行数据发送完成。
	CLR TI ; 清标志位
	ACALL DELAY ; 延时
	JMP LOOP

DELAY: ; 延时子程序

```



**功能描述：通过并行口接收八个开关数据然后通过一个串口发送另一个串行口接收然后将其通过另一组并行口输出给 LED。（串行口自检）**

```asm
ORG 00H
START:
	MOV TMOD, #20H ; 定时器工作模式，作为比特率发生器
	MOV TH1, #0FDH ; 根据比特率设置定时器初值，定时计数器 T1 作为串行口波特率发生器时不能使用中断？？
	SETB TR1 ; 启动定时器
	
	ANL PCON, #7FH ; PCON 电源控制寄存器，SMOD 设置为 0 波特率不倍增。
	MOV SCON, #01010000B ; 设置串行口工作方式
	
	MOV P2, #0FFH ; 输入口初始化
LOOP:
	MOV A, P2 ; 输入
	MOV SBUF, A  ; 发送
	
	JNB RI, $ ; 等待接收完毕
	CLR RI ; 清接收标志位
	MOV P0, SBUF ; 将接收数据输出 
	CLR TI ; 清发送标志位
	
	JMP LOOP
END
	
```



**功能描述：甲乙两机以方式1进行数据传送，波特率为11.0592MHz 波特率为1200bit/s 甲机发送的16B数据存放在内RAM的40H-4FH单元中，乙机接收后存在内RAM 以50H位首地址的区域内。**

```asm
; 甲机
ORG 0000H
LJMP TXDA

ORG 0100H 
TXDA:
	MOV TMOD, #20H  ; 定时计数器工作方式
	MOV TL1, #OE8H  ; T1 提供波特率，设置定时器初值
	MOV TH1, #0E8H 
	CLR ET1 ; 禁止 T1 中断
	SETB TR1 ; 启动定时器
	MOV SCON, #40H ; 串行方式1 禁止接收
	MOV PCON, #O0H  ; 设置波特率倍增位 SMOD = 0
	CLR ES  ; 禁止串行中断
	MOV R0, #4OH ; 发送数据区首地址
	MOV R2, #16 ; 发送数据长度

TRSA:
	MOV A，@R0 ; 寄存器间接寻址读出数据
	MOV SBUF, A  ; 发送数据
	JNB TI, $ ; 等待发送完成
	CLR TI ; 清发送标志位
	INC R0  ; 指向下一个发送数据地址
	DJNZ R2, TRSA  ; 减一不为零则跳，判断数据是否发送完
	SJMP $
END

; 乙机
ORG 0000H
LJMP RXDB 

ORG	0100H 
RXDB:
	MOV TMOD, #20H  ; 定时计数器工作方式
	MOV TL1, #OE8H ; 定时器初值
	MoV TH1, #OE8H 
	CLR ET1 ; 关 T1 中断
	SETB TR1 ; 启动定时器
	MOV SCON, #40H ; 设置串行工作方式，禁止接收
	MOV PCON, #00H  ; 置波特率倍增位 SMOD = 0 
	CLR ES ; 禁止串行中断
	MOV R0, #50H ; 置接收数据区首地址
	MOV R2，#16 ; 置接收数据长度
	SETB REN ; 启动接收

RDSB:
	JNB RI，$ ; 等待接收完成
	CLR RI  ; 清标志位
	MOV A, SBUF  ; 
	MOV @R0, A  ; 将数据存放到片内RAM
	INC R0 ; 指向下一个数据存放位置  
	DJNZ R2, RDSB  ;　判断数据是否接收完
	SJMP $

END
```



**功能描述：设计串行方式2收发程序（SMOD（波特率倍增位）= 1， 波特率固定为晶振频率的32分之一）甲机串行发送片内RAM的50H-5FH中的数据，第9位数据作为奇偶校验位，接到接收方正确的回复信号（FFH）后，再发送下一字节数据否则再重发一遍，乙机接收数据将其存在首地址为40H的内RAM中并核对奇偶校验位。核对正确发出回复信号FFH，核对错误发出回复信号00H，并等待重新接收。**

```asm
;甲机

ORG 0000H 
LJMP TRS2
ORG 0100H 
TRS2: 
	MOV SCON, #80H  ; 串行工作方式
	MOV PCON, #80H  ;　波特率倍增位置1
	MOV R0, #50H 　; 发送数据首地址 

TRLP: 
	MOV A, @R0 ; 读出数据 
	MOV C, PSW.0 ; 设置奇偶校验位
	MOV TB8,C ;
	MOV SBUF, A  ; 发送数据
	JNB TI, S  ; 等待发送数据结束
	CLR TI 
	SETB REN  ; 允许接收
	CLR RI  ; 清接收数据标志位
	JNB RI, $ ; 等待数据发送结束
	MOV A, SBUF  ; 读数据
	CPL A  ; 所有位取反
	JNZ TRLP  ; 如果 A 非全零则表示出错则需要重发
	INC R0  ; 否则指向下一个数据存储单元
	CJNE R0, 60H, TRLP ; 判断数据是否发送完毕
	SJMP $ 
END

; 乙机
ORG 0000H
LJMP RXD2
ORG 0100H
RXD2:
	MOV SCON, #80H ; 设置串行工作方式
	MOV PCON, #80H ; 设置倍增位
	MOV R0, #4OH ; 数据存储首地址
	SETB REN ; 允许接收

RWAP:
	JNB RI, $  ; 等待数据接收完毕 
	CLR RI  ; 清标志位
	MOV A, SBUF  ; 读数据

	JB PSW.0, ONE ; 如果奇偶校验位为 1 则跳
	JB RB8, ERR ; 如果奇偶校验位为 0 且接收数据奇偶校验位为 1 则跳

RLOP:
	MOV @R0, A ; 存数据 
	INC RO ; 指向下一个数据存储区
RIT:
	MOV A, #OFFH ; 准备发送正确的核实信息 
	
FDBK:
	MOV SBUF, A 
	CJNE R0, #50H, RWAP ; 判断16个数据是否接收完，如果没有则跳
	CLR REN  ; 允许接收
	SJMP $ ; 
	
ONE:
	JNB RB8, ERR ; 接收数据奇偶校验位为 0 则跳
	SJMP RLOP ; 如果没有出错
ERR:
	MOV A, #00H ; 准备发送出错的核实信息
	SJMP FDBK ; 跳转
	
END

```



**功能描述：串行通信实现点阵的显示控制。**

```asm
; 甲机

CNTA EQU 30H ; 变量定义		
COUNT EQU 31H    			 

ORG 00H
LJMP START

ORG 0BH    ; 定时计数器T0中断入口
LJMP T0X

ORG 30H
START: 
	
	MOV CNTA, #00H     
	MOV COUNT, #00H		
	
	MOV TMOD, #21H ; 定时计数器工作方式，T1 八位自动重装，T0 十六位定时计数器         

	MOV TH1, #0FFH ; 定时计数器 T1 定时初值   
	MOV TL1, #0FFH    
	SETB TR1  ; 定时器 T1 提供发送节拍，T1 的定时时间决定了串口的比特率

	MOV TH0, #(65536-4000) / 256   ; 设置定时计数器 T0 的定时初值。
	MOV TL0, #(65536-4000) MOD 256   
	SETB TR0 ; 启动定时器 T0
	
	SETB ET0 ; 开启定时器 T0 中断允许位
	SETB EA  ; 开启总中断      

	MOV SCON, #40H ; 串行口工作方式1，八位数据传送波特率由定时计数器 T1 给出

WT: ; 每按下一次按键，就改变一次 COUNT 的值，COUNT 的值决定了显示那个字。
	JB P2.0, WT   
	
	; 延时按键消除抖动
	MOV R6,#5
	MOV R7,#248
	D1:
		DJNZ R7,$
		DJNZ R6,D1   
	JB P2.0,WT
	; 
	INC COUNT  
	MOV A, COUNT
	
	CJNE A, #03H, NEXT ;    
	MOV COUNT, #00H

NEXT:
	JNB P2.0, $	; 等待按键弹起
	SJMP WT  ; 继续检测按键是否按下  
	
T0X: ; 定时计数器 T0 中断服务子程序
	NOP     
	MOV TH0,#(65536-4000)/256   ; 重新赋 T0 初值
 	MOV TL0,#(65536-4000)MOD 256
	
	; 输出行选
	MOV DPTR, #TAB  
	MOV A, CNTA   
	MOVC A, @A+DPTR
 	MOV P1, A   
	
	; 列选发送给另一个单片机输出
	MOV DPTR, #GRAPH  
	MOV A, COUNT  
	MOV B, #8 
	MUL AB ; 乘法运算得到第 COUNT 个字列选的首地址   
	ADD A, CNTA ; 得到行选对应的列选 
	MOVC A, @A+DPTR	; 
	
	MOV SBUF, A ; 发送数据  
	JNB TI, $   ; 等待发送完成
	CLR TI ; 清标志位

	INC CNTA ; 
  	MOV A, CNTA  
 	CJNE A, #8, NEX  
 	MOV CNTA, #00H

NEX: 
	RETI

END


; 乙机
TAB: ; 行选 
	DB 0FEH,0FDH,0FBH,0F7H,0EFH,0DFH,0BFH,07FH  

GRAPH: ; 三个字的列选
	DB 12H,14H,3CH,48H,3CH,14H,12H,00H   
	DB 00H,00H,38H,44H,44H,44H,38H,00H
	DB 30H,48H,44H,22H,44H,48H,30H,00H

ORG 0000H
MAIN:
	
	MOV TMOD, #20H ; 定时器T1工作方式	  
	
	MOV TH1, #0FFH ; 定时器初始值，波特率  
	MOV TL1, #0FFH
	
	SETB TR1 ; 启动定时器		    
	
	MOV SCON, #50H ;串行口工作方式，接受使能 REN     
	
	JNB RI, $ ; 查询方式，接收完毕	 
	CLR RI       

	MOV P1, SBUF	  ; 输出数据
	
	JMP MAIN		   

END


```





### 数码管



**功能描述：实现按键计数并使用静态驱动使用七段数码管显示出当前数值。静态驱动**

```asm
COUNT EQU 30H ; 变量 存放数据的空间
SP1 BIT P3.7 ; 位地址赋值伪指令

ORG 00H
AJMP START
ORG 40H ; 避免和中断地址或者变量地址冲突
START:
	MOV COUNT, #00H ; 变量初始化
NEXT:
	MOV A, COUNT
	MOV B, #10
	DIV AB  ; 除操作， A 存放被除数和整除数，B 存放除数和余数
	
	MOV DPTR, #TABLE ; 表起始地址
	
	MOVC A, @A + DPTR  ; 分别输出十位和个位
	MOV P0, A
	
	MOV A, B
	MOVC A, @A + DPTR
	MOV P2, A
	
LOOP: ; 等待按键按下
	JNB SP1, INCR
	JMP LOOP
	
INCR:
	JNB SP1, INCR ; 按键未松开
	
	INC COUNT ; 变量自加一
	MOV A, COUNT
	CJNE A, #100, NEXT ; 当计数到 100 时重新开始计数。
	LJMP START

; 共阴极数码管显示码
TABLE:
	DB 3FH, 06H, 5BH, 4FH, 66H, 6DH, 7DH, 07H, 7FH, 6FH
```



**功能描述：通过 P1 口高四位输出显示数字提供给 7447 低四位控制片选。进而控制四个七段数码管显示数字。动态驱动**

```asm
ORG 0000H
START:
	MOV P1, #81H ; 低四位片选 高四位数码显示。 1000 0001B
	CALL DELAY
	MOV P1, #02H ; 0000 0010B
	CALL DELAY
	MOV P1, #54H ; 0101 0100B
	CALL DELAY
	MOV P1, #18H ; 0001 1000B
	CALL DELAY
	JMP START

DELAY:
	MOV R7, #10
	D1:
		MOV R6, #200
		DJNZ R6, $
	DJNZ R7, D1
	RET
END
```



**功能描述：使用四个七段数码管从 0 开始显示到 9999。**

```asm
ORG 0000H 
MAIN:
	GEE EQU 30H ; 个
	SHI EQU 31H ; 十
	BEI EQU 32H ; 百
	QIAN EQU 33H ; 千
	
	; 初始化
	MOV GEE, #00H
	MOV SHI, #00H
	MOV BEI, #00H 
	MOV QIAN, #00H 
	
	MOV SCON, #00H ; 串行口工作于方式0. 同步移位

DISPLAY:
	ACALL DELAY ;延时
	
	MOV DPTR, #SETTAB 
	MOV A, GEE 
	MOVC A, @A+DPTR 
	MOV SBUF, A ; 发送
D1:
	JNB TI, D1 ; 等待发送完毕
	CLR TI ; 清标志位
	
	MOV DPTR, #SETTAB 
	MOV A, SHI 
	MOVC A, @A+DPTR
	MOV SBUF, A ; 发送
D2:
	JNB TI, D2 ; 等待发送完毕
	CLR TI 
	
	MOV DPTR, #SETTAB 
	MOV A, BEI 
	MOVC A, @A+DPTR 
	MOV SBUF, A 
D3:
	JNB TI, D3
	CLR TI 
	
	MOV DPTR, #SETTAB 
	MOV A, QIAN 
	MOVC A, @A+DPTR 
	MOV SBUF, A ; 发送
D4:
	JNB TI, D4 ; 等待发送完毕
	CLR TI
	
	INC GEE ; 自加一
	MOV A, GEE 
	CJNE A, #0AH, DISPLAY 
	
	MOV GEE, #00H  ; 十进位
	INC SHI 
	MOV A, SHI 
	CJNE A, #0AH, DISPLAY
	
	MOV SHI, #00H  ; 百进位
	INC BEI 
	MOV A, BEI 
	CJNE A, #0AH, DISPLAY
	
	MOV BEI, #00H ; 千进位
	INC QIAN 
	MOV A, QIAN 
	CJNE A, #0AH, DISPLAY 
	
	MOV QIAN, #00H ; 如果到 10000 则从零重新开始
	AJMP DISPLAY

DELAY:
	MOV R1, #0FFH 
	E1:
		MOV R2, #0FFH
		DJNZ R2, $
		DJNZ R1, E1
	RET

SETTAB: 
DB 0FCH, 60H, 0DAH, 0F2H, 66H, 0B6H, 0BEH, 0E0H, 0FEH, 0F6H, 0EEH, 3EH, 9CH, 7AH, 9EH, 8EH ;数显代码

END
```



### 方波信号



**功能描述：控制 P1.0 口输出频率变化范围在 200Hz - 250Hz 的方波信号。**

```asm
ORG 0000H 
AJMP MAIN 
ORG 001BH
AJMP DIN1 ; 中断服务程序

; 定义四个内存位置每个位置一个字节
F2H EQU 30H
F2L EQU 31H 
F3H EQU 32H 
F3L EQU 33H

MAIN:
	; 工作寄存器初始化
    MOV R1，#50
    MOV R2，#02H 
    
    ; 变量初始化，定时器初值由 F2 变为 F3 初值变大，定时时间减小频率变大。
	MOV F2H，#0F6H  ; 2500
	MOV F2L，#3BH 
	MOV F3H，#0F8H ; 2000
	MOV F3L，#2FH
	
	CLR P1.0 	; 清零输出
	MOV TMOD，#00010000B ; 定时器工作方式 
	
	; 设置定时器初值
	MOV TH1，F2H  ; 
	MOV TL1，F2L
	
	SETB EA ; 总中断
	SETB ET1 ; 定时器中断 
	SETB TR1 ; 定时器运行
	
LOOP:
	AJMP LOOP ; 等待中断

DIN1:
	CPL P1.0 ; 取反输出
	
	DJNZ R1, RE ; 寄存器值减一不为零则跳
	MOV R1, #50 ; 
	
	DJNZ R2, RE ; 寄存器值减一不为零则跳
	MOV R2, #02H
	
	; 同一频率脉冲输出五十个周期然后改变定时器初值输出下一个频率脉冲
	MOV A, F2H  ; 判断高位是否相等
	CJNE A, F3H, XIA ; 寄存器值不相等则跳
	AJMP JIA ; 高位相等则执行 JIA
XIA:
	INC F2L ; 低八位
	MOV A，F2L 
	CJNE A, #00H, RE ; 寄存器值不相等则跳
	; 相等时说明低八位有进位则不跳高位进行进位
	INC F2H 
	MOV A, F2H 
	CJNE A, F3H, RE ; 寄存器值不相等则跳
	; 高位相等则向下执行
JIA:
	INC F2L ; 判断低位是否相等
	MOV A, F2L 
	CJNE A, #F3L, RE  ; 寄存器值不相等则跳
	CLR TR1 ; 暂停定时器不再产生脉冲也不再定时。
	
RE: ; 重新赋定时器值
	MOV TH1，F2H
	MOV TL1，F2L 
	
	RETI 

END
```



**功能描述：时钟频率为 12 MHz 当 T0（P3.4）引脚产生从 1 到 0 的负跳变（边沿触发）时则从 P1.0 引脚输出一个频率为 5KHz 的方波。**

```asm
ORG 0000H
LJMP MAIN ; 转向主程序

ORG 000BH 
LJMP IT0P ; 转 T0 中断服务程序

ORG 001BH 
LUMP IT1P ; 转 T1 中断服务程序

ORG 1000H
MAN:
	MOV SP, #6OH  ; 主程序，设堆栈指针
	MOV TMOD, #25H ; T0 为模式 1、计数方式，T1 为模式 2
	MOV TLO, #OFFH ; T0置计数初值
	MOV THO, #OFFH 
	SETB ETO ; 允许 T0 中断 
	MOV TL1, #9CH ; T1置计数初值
	MOV TH1, #9CH 
	SETB EA       ; 开总中断
	SETB TRO     ; 启动 T0
HERE:
	AJMP HERE ; 等待中断

ORG 1200H ; T0 中断服务程序
IT0P:
	CLR TRO ; 停止 T0 计数
	SETB ET1 ; 允许 T1 中断
	SETB TRI ; 启动 T1  
	RETI 

ORG 1300H ; T1中断服务程序
IT1P:
	CPL P1.0 ; P1.0位取反  
	RETI
END
```



**功能描述：系统晶振频率为 12 MHz ，使用定时计数器实现周期为 1s 的方波输出。**

```asm
; 软件实现

ORG 0000H ; 跳转到主程序
AJMP MAIN

ORG 000BH ; 中断服务子程序
LJMP DVT0

ORG 0030H
MAIN:
	MOV TMOD, #01H ; T0 工作方式 
	MOV TH0, #4EH  ; 装入循环计数初值
	MOV TL0, #20H ; 
	MOV R7, #50 ; 计数50次
	SETB ET0 ; TO开中断
	SETB EA ; CPU开中断
	SETB TR0 ; 启动T0
	SJMP $ 	; 等待中断

DVT0:
	DJNZ R7, NT0 ; 计数次数未到
	MOV R7, #50 ; 数次数到
	CPL P1.7 ; 
	
NT0:
	MOV TH0, #4EH 
	MOV TL0, #20H
	SETB TR0 
	RETI 

END

; 两个定时计数器级联实现
; ......

```



**功能描述：利用定时计数器测定输入方波的高电平持续时间。**

```asm
ORG 0000H
LJMP MAIN 

ORG 1000H 
MAIN: 
	MOV TMOD, #90H ; 设置 T1 工作模式，GATE 位置 1
	MOV TL1, #00H ; 定时初值
	MOV TH1, #O0H 

LP1: 
	JB P3.3, LP1 ; 高电平时等待，P3.3 定时器 T1 门控位
	SETB TR1 ; 低电平时启动 T1
LP2: 
	JNB P3.3, LP2 ; 如果还为低电平则等待
LP3: 
	JB P3.3, LP3 ; 高电平时 T1 门控位有效开始计时直到 P3.3 低电平时停止计数
	CLR TR1
	MOV R0, TH1 ; 寄存器0，1，存放着高电平时间长度
	MOV R1, TL1
HERE: 
	SJMP HERE 

END
```



**功能描述：判断 P3.2 输入信号低电平时长，并输出到 P0 口。**

```asm
ORG 0000H 
LJMP START 
ORG 0013H 
LJMP TOINT 

START: 
	MOV P0, #O0H  ; 输出口清空
	MOV TMOD, #01H  ; 定时计数器工作方式
	MOV THO, #4CH  ; 定时计数器初值
	MOV TLO, #00H 
	SETB EA  ; 打开总中断
	SETB ETO  ; 打开 T0 中断
	MOV SP, #6OH  ; 设置堆栈地址
	MOV 30H, #00H  ; 变量初始化
	MOV 31H, #O0H  ; 30H 存储中断次数， 31H 存储低电平持续了多少个 0.1s
LOOP: 
	JB P3.2, LOOP ; 等待 P3.2 低电平
	SETB TR0 ; 启动定时
	MOV 31H, #00H ; 记录
	MOV P0, 31H ; 输出计时结果

LOOP1:
	JNB P3.2, LOOP1 ; 等待低电平结束
	CLR TRO  ; 关闭计时
	MOV TH0, #4CH ; 重新赋初值
	MOV TL0, #00H  
	AJMP LOOP 

TOINT: ; 中断服务子程序
	MOV THO, #4CH 
	MOV TLO, #00H 
	PUSH ACC ; 入栈 
	INC 30H 
	MOV A, 30H 
	
	; 比较不相等则跳
	CJNE A, #2, NEXT0 ; 每一次中断计时 50ms 两次中断计数 0.1s

REL0:
	MOV 30H, #00H ; 
	MOV A, 31H 
	ADD A, #1 ; 
	
	; 组成的两位十进制数表示低电平持续了多少个 0.1s
	DA A  ; BCD 码调整，即四位表示一个十进制数。
	MOV 31H, A

NEXT0:
	MOV P0, 31H  ; 输出
	POP ACC  ; 出栈
	RETI 

END
```



### AD转化



**程序介绍：利用 ADC0809 模拟通道 3 输入电压，经单片机处理后在数码管上用相对应的16进制数显示出来，0-5V 对应为 0-0FFH，实际应用例如：数据采集。**

```asm
ORG 0000H 
MAIN1:
	ACALL DELAY ; 延时
	ACALL AD ; 呼叫 AD 子程序，进行 AD 转换
	
	; 将转换的数字量屏蔽高位低位送显 
	MOV 31H，30H ; ???
	
	MOV A, 30H 
	ANL A，#OFH 
	MOV DPTR，#SETTAB 
	MOVC A，@A+DPTR 
	MOV SBUF，A ; 
D1:
	JNB TI，D1 ; 等待发送完成
	CLR TI 
	
	; 将转换的数字量屏蔽低位高位送显
	MOV A，30H
	ANL A，#0F0H 
	SWAP A  ; 高四位和低四位交换 
	MOV DPTR，#SETTAB 
	MOVC A，@A+DPTR 
	MOV SBUF，A 	
D2: 
	JNB TI，D2 ; 等待发送完成
	CLR TI
	
	AJMP MAIN1 ; 返回主程序

AD:
	MOV DPTR，#7FO0H ; 指向转换地址
	MOV A，#03H ; 指向转换口
	MOVX @DPTR, A ; 转换
	
	MOV R1，#64H ; 100 
D3:
	DJNZ R1，D3 ; 等 100微秒 转换完
	
	MOVX A, @DPTR ; 转换后的值给 A
	MOV 30H，A ; 转换的值给 30H 
	RET
    
    
DELAY: ;延时
	MOV R2，#OFFH 
	D14:
		MOV R3，#OFFH 
		D12:
			DJNZ R3，D12
		DJNZ R2，D14
	RET 

SETTAB:
DB 0FCH,60H,0DAH,0F2H,66H,0B6H,0BEH,0E0H,0FEH,0F6H 
DB 0EEH,3EH,9CH,7AH,9EH,8EH

END
```



### 按键控制



**功能描述：根据 P3.7 的输入情况控制 P1 的输出。**

```asm
ORG 0000H 
START:
	MOV R1, #00H ; 初始化R1为0，表示从0开始计数
	MOV A, R1 ; 
	CPL A ; 取反指令
	MOV P1, A ;送出P1端口由发光二极管显示
REL:
	JB P3.7, REL ; 判断SP1是否按下
	LCALL DELAY10MS ; 若按下，则延时10ms左右
	JB P3.7, REL ; 再判断SP1是否真得按下
	INC R1 ; 若确实按下，则进行按键处理, 使计数内容加1
	MOV A, R1 ; 并送出P1端口由发光二极管显示
	CPL A ; 取反
    MOV P1, A ; 显示
    JNB P3.7, $ ; 等待SP1释放
	SJMP REL ; 继续对K1按键扫描

DELAY10MS:
	MOV R6, #20 ; 延时10ms子程序
    L1:
        MOV R7, #248
        DJNZ R7, $
        DJNZ R6, L1
	RET

END
```



**功能描述：根据 P1.0，P1.1，P1.2 的不同输入情况执行不同的工作。**

```asm
ORG 0000H
LJMP KEYA
ORG 0100H 
KEYA:
	ORL P1, #07H ; 清输入位 
	MOV A, P1 ; 进行输入
	CPL A  ; 取反
	ANL A, #00000111B ; 位与屏蔽高五位 
	JZ GRET ; A 全零则跳，全零则表示无键按下
	LCALL DY10ms ;  延时
	MOV A, P1 ; 再输入
	CPL A  ; 
	ANL A, #00000111B ;  
	JZ GRET ; 按键去抖
	JB ACC.0, KA0 ; 根据按键按下的情况跳转至对应的功能模块
	JB ACC.1, KA1
	JB ACC.2, KA2
GRET:
	SJMP $
KA0:
	LCALL WORK0 ; 调入对应的功能模块
	SJMP GRET 

KA1:
	LCALL WORK1
	SJMP GRET 
	
KA2:
	LCALL WORK2
	SJMP GRET 

END
```



### LCD 显示控制



**功能描述：使用 LCD1602 在第一行显示 “SHXY” ，在第二行显示 “ZDH” 。**

```asm
RW BIT P2.1
RS BIT P2.0
E  BIT P2.7
ORG 0000H
JMP START
ORG 0040H 
START:
	MOV SP, #5FH ; 设置堆栈指针
	CALL INIT ; 初始化 LCD
	
	MOV A, #8OH ; 写命令
	CALL WRC
	MOV A, #53H ; 写第一行显示数据
	CALL WRD 
	MOV A, #48H
	CALL WRD 
	MOV A, #58H 
	CALL WRD
	MOV A, #59H 
	CALL WRD 
	
	MOV A, #0C4H ; 写命令 
	CALL WRC  
	MOV A, #44H  ; 写第二行显示数据
	CALL WRD 
	MOV A, #50H 
	CALL WRD 
	MOV A, #4AH 
	CALL WRD
	SJMP $

INIT: ; 初始化
	MOV A, #O1H ; 清屏
	CALL WRC ; 写命令
	MOV A, #38H ; 显示设置
	CALL WRC 
	MOV A, #0EH 
	CALL WRC 
	MOV A, #06H 
	CALL WRC 
	RET
	
CBUSY:
	PUSH ACC 
	PUSH DPH
	PUSH DPL
	PUSH PSW 
WEIT:
	; 时序
	CLR RS 
	SETB RW 
	CLR E 
	SETB E
	
	MOV A, P1 ; 读数据
	CLR E ; 时序
	JB ACC.7, WEIT ; 忙则等待
	
	POP PSW
	POP DPL
	POP DPH
	POP ACC
	
	CALL DELAY
	RET

WRC: ; 写命令
	CALL CBUSY ; 判断是否忙
	; 时序
	CLR E 
	CLR RS
	CLR RW
	SETB E
	; 并行口输出
	MOV P1, A
	CLR E ; 时序
	CALL DELAY 
	RET
	
WRD: ; 写显示数据
	CALL CBUSY ; 判断是否忙
	; 时序
	CLR E
	SETB RS
	CLR RW
	SETB E
	; 并行口输出
	MOV P1, A
	CLR E ; 时序
	CALL DELAY
	RET

DELAY: ; 延时
	MOV R7, #5
	LP1:
		MOV R6, #0F8H
		DJNZ R6, $
		DJNZ R7, LP1
	RET
END
```



























