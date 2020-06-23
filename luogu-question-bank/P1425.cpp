/*这个文件夹是做洛谷题库的专用文件夹。 
*/ 

#include <stdio.h>
int main()
{
	int i1,i2,t1,t2;
	scanf("%d%d%d%d",&i1,&i2,&t1,&t2);
    if(t2<i2)
    {
    	t1--;
    	t2=t2+60-i2;
    	t1-=i1;
	}
    else if(t2==i2)
    {
    	t2=0;
    	t1-=i1;
	}
    else
    {
    	t2-=i2;
    	t1-=i1;
	}
	printf("%d %d\n",t1,t2);
	return 0;
}
