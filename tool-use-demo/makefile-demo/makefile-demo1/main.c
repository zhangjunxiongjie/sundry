#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>
#include "max.h"
#include "min.h"

int main()
{

	srand(time(NULL));
	int a1 = rand();
	int a2 = rand();

	int maxValue = max(a1, a2);
	int minValue = min(a1, a2);
	printf("max number: %d, min number: %d.\n", maxValue, minValue);

	return 0;
}

