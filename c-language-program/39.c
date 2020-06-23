//程序解一元二次方程
#include <stdio.h> //仅适用于有解的一元二次方程
#include <math.h>
int main()
{
	double a, b, c, disc, x1, x2, p, q;
	scanf("%lf%lf%lf", &a, &b, &c);
	disc = b * b - 4 * a * c;
	p = -b / (2.0 * a);
	q = sqrt(disc) / (2.0 * a);
	x1 = p + q;
	x2 = p - q;
	printf("x1=%7.2f\nx2=%7.2f\n", x1, x2);
	return 0;
}

#include <stdio.h> //可解出不存在实数解的一元二次方程
#include <math.h>
int main()
{
	double a, b, c, disc, x1, x2, realpart, imagpart;
	scanf("%lf,%lf,%lf", &a, &b, &c);
	printf("The equation ");
	if (fabs(a) <= 1e-6)
		printf("is not a quadratic\n");
	else
	{
		disc = b * b - 4 * a * c;
		if (fabs(disc) <= 1e-6)
			printf("has two equal roots:%8.4f\n", -b / (2 * a));
		else if (disc > 1e-6)
		{
			x1 = (-b + sqrt(disc)) / (2 * a);
			x2 = (-b - sqrt(disc)) / (2 * a);
			printf("has two equal roots:%8.4f and %8.4f\n", x1, x2);
		}
		else
		{
			realpart = -b / (2 * a);
			imagpart = sqrt(disc) / (2 * a);
			printf(" has complex roots:\n");
			printf("%8.4f+%8.4fi\n", realpart, imagpart);
			printf("%8.4f-%8.4fi\n", realpart, imagpart);
		}
	}
	return 0;
}
