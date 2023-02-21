#include <stdio.h>
#include <math.h>

int	calculate_var_1(float *vect, int n)
{
	float	sn2;
	float	x;
	int		i;

	i = 0;
	x = 0;
	while (i < n)
	{
		x += vect[i];
		i++;
	}
	x = x/n;
	i = 0;
	sn2 = 0;
	while (i < n)
	{
		sn2 += (vect[i] - x)*(vect[i] - x);
		i++;
	}
}

int	main()
{
	float	*vect;
	float	variance1;
	float	variance2;
	int		len;

	vect = {1, 3, 2E-2, 5, 66, 7/8};
	len = 6;
	variance1 = calculate_var_1(vect, len);
	variance2 = calculate_var_2(vect, len);
	printf("first formula:\nvariance=%.8G\n", variance1);
	printf("second formula:\nvariance=%.8G\n", variance2);
	return (0);
}
