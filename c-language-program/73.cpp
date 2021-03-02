//判断输入字符串中字母数字空格和其他的个数并输出
#include <stdio.h>
#include <string.h> //计算字符串长度函数的头文件
int main()			//先输入一个字符串将其保存在字符数组a【】中，然后再判断
{
	int cd, i;
	int szgs = 0, zfgs = 0, kggs = 0, qtgs = 0;
	char a[100];
	gets(a);		//字符串输入语句
	cd = strlen(a); //侧字符串长度（总的字符个数）的函数
	for (i = 0; i < cd; i++)
	{
		if ('0' <= a[i] && a[i] <= '9') //数字的判断
			szgs++;
		else if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z')) //字母的判断
			zfgs++;
		else if (a[i] == ' ') //空格的判断，此处注意等号别写成了赋值符号
			kggs++;
		else //其它
			qtgs++;
	}
	puts(a);			//字符串输出语句
	printf("%d\n", cd); //输出字符串的总的字符个数
	printf("字母个数：%d\n", zfgs);
	printf("数字个数：%d\n", szgs);
	printf("空格个数：%d\n", kggs);
	printf("其他个数：%d\n", qtgs);
	return 0;
}

#include <stdio.h>
#include <string.h> //测定字符串长度函数的头文件
int main()
{
	int szgs = 0, zfgs = 0, kggs = 0, qtgs = 0;
	char b, a[20]; //临时储存输入的字符串
	int i, cd;
	for (i = 0; (b = getchar()) != '\n'; i++) //每输入一个字符将这个字符临时储存在字符变量a中
	{										  //每输入一个字符循环并判断一次，直至输入回车时退出循环不在输入
		a[i] = b;
		if (('a' <= a[i] && a[i] <= 'z') || ('A' <= a[i] && a[i] <= 'Z'))
			zfgs++;
		else if ('0' <= a[i] && a[i] <= '9')
			szgs++;
		else if (a[i] == ' ')
			kggs++;
		else
			qtgs++;
	}
	cd = strlen(a); //测定字符串长度
	puts(a);		//字符串输出语句
	printf("%d\n", cd);
	printf("字母个数：%d\n", zfgs);
	printf("数字个数：%d\n", szgs);
	printf("空格个数：%d\n", kggs);
	printf("其他个数：%d\n", qtgs);
	return 0;
}
