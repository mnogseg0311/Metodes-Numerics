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
		fx = 2*sin(x/2)*sin(x/2)/(x*x);
	printf("%.16G\n", fx);
	return (0);
}
