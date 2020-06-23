// 给入一个长整型数字返回它的位数每位数字，及逆序 

#include <stdio.h>
int main ()
{
	int qws(long int a);
	void scs(long int b,int z[]);
	long int t;
	int ws,i;         //ws  表示输入数t的位数 
	printf ("请输入一个长整型数字："); 
	scanf("%ld",&t);   //输入一个数字 
	ws=qws(t);
	int z[ws];   //数组z【】储存输入数t的所有数字 
	scs(t,z);
	printf("这个数的位数是%d\n",ws);
	printf("每位数字为："); 
	
	for(i=ws-1;i>=0;i--)
	    printf("%d,",z[i]);
	
	printf("\n它的逆序是：");
	
	for(i=i+1;i<ws;i++)
	    printf("%d",z[i]);
	
	return 0;
}

int qws(long int a)  //求数字的位数 
{                     //可以求任何数字的位数 
	int m,i=-1;
	while(a!=0||m!=0)
	{
	    m=a%10;
	    a/=10;
	    i++;
	}
	return (i);
}

void scs(long int b,int z[])   //分离数字的没位数并保存于z【】数组 
{
	int qws(long int a);   //利用指针知识可知数组中的数直接传到到了主函数数组 
	int ws,i=0;
	ws=qws(b);
	while(i<ws)
	{
	    z[i]=b%10;
	    b/=10;
	    i++;
	}
}
