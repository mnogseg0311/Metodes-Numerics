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
		fx = (1 - cosf(x))/(x*x);
	printf("%.8G\n", fx);
	return (0);
}

