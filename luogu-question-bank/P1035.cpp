//算法有待改进 

#include <stdio.h>
#include <math.h> 
int main()
{
	long double Series;
	long double ty;
    int tb;
	long int i;
    scanf("%d",&tb);
    for(i=pow(2,tb);;i++)
    {
        for(ty=i,Series=0.0;ty>0.0;ty--)
        	Series+=1.0/ty;
        if(Series>tb)
            break;
    }
    printf("%ld\n",i);
    return 0;
}
