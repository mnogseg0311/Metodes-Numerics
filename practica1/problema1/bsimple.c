#include <stdio.h>
#include <math.h>

int	main()
{
	float	x;
	float	fx;

	x = 1.2E-5;
	if (x == 0)
		fx = 1/2;
	else
		fx = 2*sinf(x/2)*sinf(x/2)/(x*x);
	printf("%.8G\n", fx);
	return (0);
}
