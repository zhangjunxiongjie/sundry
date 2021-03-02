#include<stdio.h>
void main ()
{
    float f,c;
    scanf ("%f",&c);
    f=5.0/9*c+32.0;
    printf("%f\n",f);
}                                     //摄氏温度转化为华氏温度//


#include< stdio.h>
int main ()
{
    char c1;
    int c2;
    c1=getchar();  //任意输入语句（但与scanf不同，仅限输入大小写字母）//
    c2=c1+32;
    (char)c2;         //可删除？//
    putchar(c2);
    putchar('\n');   //输出语句但与printf有所不同//
    return 0;
}              //输入大写英文字母输出小写英文字母//



#include<stdio.h>   //英文字母大小写程序互换//
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

