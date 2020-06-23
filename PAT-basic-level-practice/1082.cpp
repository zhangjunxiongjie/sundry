#include <stdio.h>
int main ()
{
	void px(int t,int* a);
	int i,i1,i2;
	char ch;
	int b[100][5],c[5];
	int i3,i4=1;
	while((ch=getchar())!='\n')
	{
		if(i4==1&&ch!=' ')
		{
			i=ch-48;
			
		}
		else if(i4!=1&&ch!=' ')
		{
			i=i*10+ch-48;
		}
		if(ch==' ')
		   i4=1;
		else
		   i4=0;
		
	} 
	for(i4=0;i4<i;i4++)
	{
		b[i4][4]=0;
	}
	for(i3=0;i3<i;i3++)
	{
		for(i1=0;(ch=getchar())!='\n';)
		{
          if(ch!=' '&&i1<4)
		  {
			b[i3][i1]=ch-48;
			//printf("%d ",b[i3][i1]);
			i1++;
		  } 
		  else if(i1>=4&&ch!=' '&&ch!='-')
		  {
			  b[i3][i1]=b[i3][i1]+(ch-48)*(ch-48);
             // printf("%d ",b[i3][i1]);
		  }
		}
	}

	for(i1=0;i1<i;i1++)
	{
		for(i2=i1+1;i2<i;i2++)
		{
           if(b[i1][4]<b[i2][4])
		   {
			   for(i3=0;i3<5;i3++)
			   {
				   c[i3]=b[i1][i3];
				   b[i1][i3]=b[i2][i3];
				   b[i2][i3]=c[i3];
			   }
			 
		   }
		}
	}
	for(i2=0;i2<4;i2++)
	printf("%d",b[i-1][i2]);
	printf(" ");
	for(i2=0;i2<4;i2++)
	printf("%d",b[0][i2]);
	printf("\n");
	return 0;
}


