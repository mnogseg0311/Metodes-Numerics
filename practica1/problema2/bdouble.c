#include <stdio.h>
#include <math.h>

//si b>0 peta x1, si b<0, x2

int	main()
{
	double	a = 20;
	double	b = -70;
	double	c = 4E-6;
	double	x1;
	double	x2;
	
	x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
	x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
	printf("x1=%.16G\nx2=%.16G\n", x1, x2);
	return (0);
}
