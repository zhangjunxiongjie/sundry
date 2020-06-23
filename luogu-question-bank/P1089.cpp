#include <stdio.h>
int main()
{
	int it[12];
	int i,tr=0,jy=0;//jy上月结余，tr总的存储金额 
	for(i=0;i<12;i++)
	{
		scanf("%d",it+i);
		if(tr>=0&&jy+300<it[i])
			tr=-(i+1);
		if(tr>=0&&jy+300>=it[i])
		{
			jy=jy+300-it[i];
			while(jy>=100)
			{
				tr+=100;
				jy-=100;
			}	
		} 
	//	printf("%d:%d:%d.",i,tr,jy);
	}
	if(tr>=0)
		printf("%.0f\n",tr*1.2+jy);
	else
		printf("%d\n",tr);
}



