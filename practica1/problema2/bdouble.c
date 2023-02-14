#include <stdio.h>
#include <math.h>

int	main()
{
	double	a = 1.25E9;
	double	b = 65.657E15;
	double	c = -45.42E12;
	double	x1;
	double	x2;
	
	x1 = (-b + sqrt(b*b - 4*a*c))/2*a;
	x2 = (-b - sqrt(b*b - 4*a*c))/2*a;
	printf("x1=%.16G\nx2=%.16G\n", x1, x2);
	return (0);
}
