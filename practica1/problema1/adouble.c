#include <stdio.h>
#include <math.h>

int	main()
{
	double	x;
	double	fx;

	x = 1.2E-5;
	if (x == 0)
		fx = 1/2;
	else
		fx = (1 - cos(x))/(x*x);
	printf("%.16G\n", fx);
	return (0);
}
