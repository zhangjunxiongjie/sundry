//密码转译
#include <stdio.h>
int main ()
{
char c;
c=getchar();
while(c!='\n')    //***循环语句内的输入语句可以连续给一个字符型变量多次赋值并转义***
{ 
  if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))  //此例中的字符型变量类似于字符串变量，将一个字符串赋给它在进行转义
  {
    if(c>='W'&&c<='Z'||c>='w'&&c<='z')
      c=c-22;  
    else
      c=c+4;
  } 
  printf("%c",c);
  c=getchar();
}
printf("\n");
return 0;
}

//密码转译
#include <stdio.h>
int main ()
{
char c;
while((c=getchar())!='\n')    //输入嵌套语句
{ 
  if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))  //此例中的字符型变量类似于字符串变量，将一个字符串赋给它在进行转义
  {
	c=c+4;
    if(c>='Z'&&c<='Z'+4||c>='z'&&c<='z'+4)    //利用字符ASCII码的特点
      c=c-26;  
  } 
  printf("%c",c);
}
printf("\n");
return 0;
}