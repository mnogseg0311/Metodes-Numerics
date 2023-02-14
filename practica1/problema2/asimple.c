#include <stdio.h>
#include <math.h>

int	main()
{
	float	a = 3.2;
	float	b = 5.657;
	float	c = -2;
	float	x1;
	float	x2;
	
	x1 = (-b + sqrtf(b*b - 4*a*c))/2*a;
	x2 = (-b - sqrtf(b*b - 4*a*c))/2*a;
	printf("x1=%.8G\nx2=%.8G\n", x1, x2);
	return (0);
}
