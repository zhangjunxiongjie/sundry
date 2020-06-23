#include <stdio.h>
int main ()
{
	int i,i1,i2,i3;
	int b[100][4];
	char ch;
	scanf("%d\n",&i);
	for(i3=0;i3<i;i3++)
	    for(i2=0;i2<4;i2++)
	    	b[i3][i2]=0;
    for(i3=0;i3<i;i3++)
	{
		while((ch=getchar())!='\n')
		{
		    if(('A'<=ch&&ch<='Z')||('a'<=ch&&ch<='z'))
			{
		    	b[i3][0]=1;
                b[i3][3]++;
			}
	    	else if('0'<=ch&&ch<='9')
			{
			    b[i3][1]=1;
		    	b[i3][3]++;
			}
	    	else if(ch=='.')
		    	b[i3][3]++;
	    	else
		    	b[i3][2]=1;
		}
	}
	for(i1=0;i1<i;i1++)
	{
		if(b[i1][3]>=6)
		{
		    if(b[i1][2]==1)
			{
		     	printf("Your password is tai luan le.\n");
			}
		    else 
			{
		    	if(b[i1][0]==1&&b[i1][1]==1)
                    printf("Your password is wan mei.\n");
		    	else if(b[i1][0]!=1&&b[i1][1]==1)
			    	printf("Your password needs zi mu.\n");
				else if(b[i1][0]==1&&b[i1][1]!=1)
			    	printf("Your password needs shu zi.\n");
			    else
				{
					printf("≥Ã–Ú±¿¿££°\n");
					for(i2=0;i2<100000;i2++);
					for(i2=0;i2<100000;i2++)
					    printf("µÁƒ‘º¥Ω´±¨’®«Îæ°øÏ¿Îø™£°\n");
				}
			}

		}
    	else
		{
            printf("Your password is tai duan le.\n");
		}

	}
	return 0;
}
