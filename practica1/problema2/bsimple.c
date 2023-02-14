#include <stdio.h>
#include <math.h>

int	main()
{
	float	a = 1.25E9;
	float	b = 65.657E15;
	float	c = -45.42E12;
	float	x1;
	float	x2;
	
	x1 = (-b + sqrtf(b*b - 4*a*c))/2*a;
	x2 = (-b - sqrtf(b*b - 4*a*c))/2*a;
	printf("x1=%.8G\nx2=%.8G\n", x1, x2);
	return (0);
}
