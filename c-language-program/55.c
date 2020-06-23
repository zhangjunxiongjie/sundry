#include <stdio.h>       //输出三角形式的杨辉三角
main ()
{
int jc[10][10],i,j,t;
for(i=0;i<10;i++)
jc[i][0]=1;
for(t=0;t<10;t++)
jc[t][t]=1;
for(i=2,j=1;i<10,j<10;j++,i++)
for(t=i;t<10;t++)
jc[t][j]=jc[t-1][j]+jc[t-1][j-1];
for(i=0,t=0;i<10;i++,t++)
{for(j=0;j<=t;j++)
printf("%d ",jc[i][j]);
printf("\n");}
}
