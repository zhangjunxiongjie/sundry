#include<stdio.h>
void main ()
{
    float f,c;
    scanf ("%f",&c);
    f=5.0/9*c+32.0;
    printf("%f\n",f);
}                                     //�����¶�ת��Ϊ�����¶�//


#include< stdio.h>
int main ()
{
    char c1;
    int c2;
    c1=getchar();  //����������䣨����scanf��ͬ�����������Сд��ĸ��//
    c2=c1+32;
    (char)c2;         //��ɾ����//
    putchar(c2);
    putchar('\n');   //�����䵫��printf������ͬ//
    return 0;
}              //�����дӢ����ĸ���СдӢ����ĸ//



#include<stdio.h>   //Ӣ����ĸ��Сд���򻥻�//
int main ()
{
    char c1,c2;
    scanf ("%c",&c1);
    if(97<=c1&&c1<=122)
    {
        c2=c1-32;
        printf("%c\n",c2);
    }
    else
        if ('a'<=c1&&c1>='z')
        {
            c2=c1+32;
            printf("%c\n",c2);
        }
    return 0;
}

