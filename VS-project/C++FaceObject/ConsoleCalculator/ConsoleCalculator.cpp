// 此项目用于实现控制台陷入式的简单计算器。 
// help 帮助文档， exit 退出（结束程序），cls 清屏。 

// 加 减 乘 除 括号 输入
// 对输入字符串的算术解析
// 通过给运算符设置优先级的方法来实现运算符解析
// 算术运算 + - 一级 * / 二级 一层括号增加两级
// cos sin tan ^次方 %取余 
// 逻辑运算 < > <= >= && || ! 
// 进制转换 二进制 八进制 十进制 十六进制 
// 命令
// 命令后面跟表达式。
// run -s 算术运算
// run -l 逻辑运算
// run -j 进制转换
// help 帮助
// cls 清屏
// exit 退出程序

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string instr; // 输入字符后窜；
	cin >> instr;

}