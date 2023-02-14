#include <stdio.h>
#include <math.h>

int	main()
{
	double	a = 3.2;
	double	b = 5.657;
	double	c = -2;
	double	x1;
	double	x2;
	
	x1 = (-b + sqrt(b*b - 4*a*c))/2*a;
	x2 = (-b - sqrt(b*b - 4*a*c))/2*a;
	printf("x1=%.16G\nx2=%.16G\n", x1, x2);
	return (0);
}
