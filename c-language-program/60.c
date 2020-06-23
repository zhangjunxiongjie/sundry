#include <stdio.h>  //输出“BOY”
int main ()
{
char a='B',b='O',c='Y';  //定义字符变量，字符变量用单引号隔开，字符串变量用双引号隔开
int f=66;
putchar(a);  //putchar输出语句，可输出定义的字符变量，也可直接输出字符（但须用单引号隔开）
putchar(b);
putchar(c);
putchar('\n');
putchar('d');
putchar('\n');
putchar(f);
putchar('\n');
return 0;
}


#include <stdio.h>  //屏幕上输入“BOY”然后将其输出
int main ()
{
char a,b,c;
a=getchar();     //类似于scanf的输入函数，但scanf应用更广泛，功能更多。
b=getchar();
c=getchar();
putchar(a);
putchar(b);
putchar(c);
putchar('\n');
return 0;
}


#include <stdio.h>  
int main()
{
putchar(getchar());
putchar(getchar());
putchar(getchar());
putchar('\n');
return 0;
}
