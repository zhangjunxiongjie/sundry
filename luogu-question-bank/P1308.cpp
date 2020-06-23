#include <stdio.h>
int main()
{
	char BJ[10],JT[10000],ch;
	int tr=0,ty=0,i;
	int num=0,chu=-1,bj=1;
	while((ch=getchar())!='\n')
	{
		if(ch!=' '&&ch<97)
			ch+=32;
		BJ[tr++]=ch;
	}
	while((ch=getchar())!='\n')
	{
		if(ch!=' '&&ch<97)
			ch+=32;
		JT[ty++]=ch;
	}
	for(i=0;i<ty;i++)
	{
		if(bj)
		{
			for(ch=0;ch<tr;ch++,i++)
				if(JT[i]!=BJ[ch])
					break;
			if(ch==tr&&JT[i]==' ')
			{
				num++;
				if(chu==-1)
					chu=i-tr;	
			}	
		}
		if(JT[i]==' ')
			bj=1;
		else
			bj=0;
	}
	if(num!=0)
		printf("%d %d\n",num,chu);
	else
		printf("-1\n");
	return 0;
}










