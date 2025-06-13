
#include <stdio.h>
#include <math.h>

double f(double x) {
	return x*x*x - x -400;
}

double df(double x) {
	return 3*x*x - 1;
}

double bk(double b, double x) {
	return b*(2-df(x)*b);
}

double xk(double x, double b) {
	return x - b*f(x);
}

int main() {
	double x = 6, b = 1/df(x), xaux = 0, ek = 0, ekaux = 0;
	int n=0,  nmax=100;
	
	ek = fabs(xaux - x);
	while (ek > 1E-14 && n <=  nmax) {
		ekaux = ek;
		xaux = x;
		x = xk(x,b);
		b = bk(b,x);
		ek = fabs(xaux - x);
		n++;
		printf("x = %.16G, b = %.16G, n = %i\n", x, b, n);
		printf("ek/e(k-1) = %.16G\n", ek/ekaux);
		printf("ek/e(k-1) = %.16G\n", ek/(ekaux*ekaux));
		printf("ek/e(k-1) = %.16G\n\n", ek/(ekaux*ekaux*ekaux));
	} 
	printf("x = %.16G después de %i iteraciones\n", x, n);
	return 0;
}





