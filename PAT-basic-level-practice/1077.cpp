#include <stdio.h>
int main ()
{
	int i,i1,i2,i3;
	int a[2];
	float max,min;
	float t,b[100][100];
	char ch;
	for(i1=0,i2=1;(ch=getchar())!='\n';)
	{
		if(i2==1&&ch!=' ')
		{
			a[i1]=ch-48;
			i1++;
		}
		else if(i2==0&&ch!=' ')
		{
			a[i1-1]=(a[i1-1]*10)+ch-48;
		}
		if(ch==' ')
		{
            i2=1; 
		}
		else
			i2=0;
	}
//	printf("%d\n",a[1]);
    for(i1=0;i1<a[0];i1++)
	{
		for(i2=1,i3=0;(ch=getchar())!='\n';)
		{
			if(i2==1&&ch!=' ')
			{
				if(ch=='-')
				{
					b[i1][i3]=-1.0;
					i3++;
				}
				else
				{
					b[i1][i3]=(float)(ch-48);
				    i3++;
				}
			}
			else if(i2==0&&ch!=' '&&(b[i1][i3-1]!=-1.0))
			{
			    b[i1][i3-1]=(b[i1][i3-1]*10)+ch-48;
			}
			if(ch==' ')
				i2=1;
			else
				i2=0;
		}
	}
	/*for(i1=0;i1<a[0];i1++)
	{
		for(i2=0;i2<a[0];i2++)
			printf("%f ",b[i1][i2]);
		printf("\n");
	}
	printf("\n");*/
    for(i1=0;i1<a[0];i1++)
	{   
		for(i3=1;;i3++)
		{
			if(b[i1][i3]>=0&&b[i1][i3]<=a[1])
			{
			//	printf("%f ",b[i1][i3]);
                 max=b[i1][i3];
				 min=b[i1][i3];
				 break;
			}
		}
	//	printf("%f %f\n",max,min);
		for(i2=1,t=(float)(a[0]-3);i2<a[0];i2++)
		{
			if(b[i1][i2]<0||b[i1][i2]>a[1])
			{
				b[i1][i2]=0;
				t=t-1;
			}
			else if(b[i1][i2]>max)
			{
                max=b[i1][i2];
			//	printf("%f ",max);
			}
			else if(b[i1][i2]<min)
			{
				min=b[i1][i2];
			//	printf("%f ",min);
			}
			
            if(i2==a[0]-1)
			{
				for(i=2;i<a[0];i++)
				{
					b[i1][1]=b[i1][1]+b[i1][i];
				}
				//printf("%f ",b[i1][1]);
				b[i1][1]=(b[i1][1]-max-min)/t;
			}
		}
		//printf("%f %f\n",max,min);
		if(((b[i1][1]+b[i1][0])/2-((int)(b[i1][1]+b[i1][0]))/2)>=0.5)
		    printf("%d\n",((int)(b[i1][1]+b[i1][0])/2)+1);
		else
			printf("%d\n",(int)((b[i1][1]+b[i1][0])/2.0));
	}


/*	for(i1=0;i1<a[0];i1++)
	{
		for(i2=0;i2<a[0];i2++)
			printf("%d ",b[i1][i2]);
		printf("\n");
	}
	printf("\n");*/
	return 0;
}
