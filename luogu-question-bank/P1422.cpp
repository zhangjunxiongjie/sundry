#include <stdio.h>
int main()
{
	int tr;
	float ty;
	scanf("%d",&tr);
	if(tr<=150)
		ty=tr*0.4463;
	else if(tr<=400)
		ty=150*0.4463+(tr-150)*0.4663;
	else if(tr>400)
		ty=150*0.4463+250*0.4663+(tr-400)*0.5663;
	printf("%.1f",ty);
	return 0;
}
