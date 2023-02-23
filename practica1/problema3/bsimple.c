#include <stdio.h>
#include <math.h>

int	calculate_var_2(float *vect, int n)
{
	float	sn2;
	float	x;
	
	x = 0;
	for (int i = 0; i < n; i++)
		x += vect[i];
	x = (x*x)/n;
	sn2 = 0;
	for (int i = 0; i < n; i++)
		sn2 += vect[i]*vect[i];
	sn2 = (sn2 - x)/(n - 1);
	return (sqrtf(sn2));
}

int	calculate_var_1(float *vect, int n)
{
	float	sn2;
	float	x;

	x = 0;
	for (int i = 0; i < n; i++)
		x += vect[i];
	x = x/n;
	sn2 = 0;
	for (int i = 0; i < n; i++)
		sn2 += (vect[i] - x)*(vect[i] - x);
	sn2 = sn2/(n - 1);
	return (sqrtf(sn2));
}

int	main()
{
	float	vect[] = {10000, 10001, 10002};
	float	variance1;
	float	variance2;
	int		len;

	len = 3;
	variance1 = calculate_var_1(vect, len);
	variance2 = calculate_var_2(vect, len);
	printf("first formula:\nvariance=%.8G\n", variance1);
	printf("second formula:\nvariance=%.8G\n", variance2);
	return (0);
}
