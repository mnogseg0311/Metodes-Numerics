//Programa que calcula el cero real del polinomio x^3 - x - 400 utilizando la iteración propuesta en el ejercicio 2

#include <stdio.h>
#include <math.h>

double	f(double x)			//f(x)
{
	return (x*x*x - x - 400);
}

double	fprima(double x)		//f'(x)
{
	return (3*x*x - 1);
}

int	main()
{
	double	xk = 6, xkmas = 0;                  //variables donde vamos guardando las equis, xk se inicializa con el valor de x_0
	double	bk = 1/fprima(xk), bkmas = 0;       //variables donde vamos guardando las bes, el valor b_0 inicial depende de x_0
	int	n = 1, nmax = 10;                        //con n sabemos cuantas iteraciones hemos hecho y, nmax es un límite para estas

	xkmas = xk - bk * f(xk);                    //inicializamos xkmas con x_1
	bkmas = bk * (2 - fprima(xkmas) * bk);      //inicializamos bkmas con b_1
	while (f(xkmas) != 0 && n <= nmax)          //iteramos hasta llegar al máximo u obtener una x_k la imagen de la qual sea 0, en precisión doble
	{
		xk = xkmas;
		bk = bkmas;
		xkmas = xk - bk * f(xk);
		bkmas = bk * (2 - fprima(xkmas) * bk);
		n++;
	}
	printf("x_%d = %.16G, f(x_%d) = %.16G\n", n, xkmas, n, f(xkmas));       //imprimimos en la consola la raíz obtenida
	return (0);
}
