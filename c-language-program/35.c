//�������ÿһ���˰��Ŷ���
#include <stdio.h>
int main ()
{
char i,j,k;
for(i='X';i<='Z';i++)
{
	for(j='X';j<='Z';j++)
	{
		if(i!=j)
		{
			for(k='X';k<='Z';k++)
			{
				if(i!=k&&j!=k)
				{
					if(i!='X'&&k!='X'&&k!='Z')
					{
						printf("A�Ķ���%c��B�Ķ���%c��C�Ķ���%c��\n",i,j,k);
					}	
				}
			}
		}
	}
}
return 0;
} 


//������
#include <stdio.h>
int main ()
{
	char ad[3]={'A','B','C'},bd[3]={'X','Y','Z'};
	char dj[6];
	int i,t=0;
	while (i<6)
	{
		dj[i]=ad[t];
		i=+2;
		t++;
	}
	for(t=0;t<3;t++)
	  if(bd[t]!='X'&&bd[t]!='z')
		dj[5]=bd[t];
	for(t=0;t<3;t++)
      if(bd[t]!='X'&&bd[t]!=dj[5])
		dj[1]=bd[t];
	for(t=0;t<3;t++)
	  if(bd[t]!=dj[5]&&bd[t]!=dj[1])
		dj[3]=bd[t];
	for(i=0;i<6;i=i+2)
		printf("%c�Ķ�����%c��\n",dj[i],dj[i+1]);
	return 0;
}