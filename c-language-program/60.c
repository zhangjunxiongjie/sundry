#include <stdio.h>  //�����BOY��
int main ()
{
char a='B',b='O',c='Y';  //�����ַ��������ַ������õ����Ÿ������ַ���������˫���Ÿ���
int f=66;
putchar(a);  //putchar�����䣬�����������ַ�������Ҳ��ֱ������ַ��������õ����Ÿ�����
putchar(b);
putchar(c);
putchar('\n');
putchar('d');
putchar('\n');
putchar(f);
putchar('\n');
return 0;
}


#include <stdio.h>  //��Ļ�����롰BOY��Ȼ�������
int main ()
{
char a,b,c;
a=getchar();     //������scanf�����뺯������scanfӦ�ø��㷺�����ܸ��ࡣ
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
