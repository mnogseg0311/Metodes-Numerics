#include <stdio.h>
#include <math.h>

int	main()
{
	float	a = 20;
	float	b = -70;
	float	c = 4E-6;
	float	x1;
	float	x2;
	
	if (b > 0)
	{
		x1 = (-2*c)/(b + sqrtf(b*b - 4*a*c));
		x2 = (-b - sqrtf(b*b - 4*a*c))/(2*a);
	}
	else
	{
		x1 = (-b + sqrtf(b*b - 4*a*c))/(2*a);
		x2 = (-2*c)/(b - sqrtf(b*b - 4*a*c));
	}
	printf("x1=%.8G\nx2=%.8G\n", x1, x2);
	return (0);
}
