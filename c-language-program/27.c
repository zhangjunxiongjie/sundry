//����ת��
#include <stdio.h>
int main ()
{
char c;
c=getchar();
while(c!='\n')    //***ѭ������ڵ�����������������һ���ַ��ͱ�����θ�ֵ��ת��***
{ 
  if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))  //�����е��ַ��ͱ����������ַ�����������һ���ַ����������ڽ���ת��
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

//����ת��
#include <stdio.h>
int main ()
{
char c;
while((c=getchar())!='\n')    //����Ƕ�����
{ 
  if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))  //�����е��ַ��ͱ����������ַ�����������һ���ַ����������ڽ���ת��
  {
	c=c+4;
    if(c>='Z'&&c<='Z'+4||c>='z'&&c<='z'+4)    //�����ַ�ASCII����ص�
      c=c-26;  
  } 
  printf("%c",c);
}
printf("\n");
return 0;
}