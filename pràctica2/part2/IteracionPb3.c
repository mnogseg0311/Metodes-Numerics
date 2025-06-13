//Programa que calcula el cero real del polinomio x^3 - x - 400 utilizando la iteración propuesta en el ejercicio 2, el método de Halley

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

double  fdobleprima(double x) {     //f''(x)
    return 6*x;
}

int	main()
{
	double	xk = 4, xkmas = 0;                  //variables donde vamos guardando las equis, xk se inicializa con el valor de x_0
	int	n = 1, nmax = 10;                        //con n sabemos cuantas iteraciones hemos hecho y, nmax es un límite para estas

	xkmas = xk - 2*f(xk)*fprima(xk)/(2*fprima(xk)*fprima(xk) - f(xk)*fdobleprima(xk));                    //inicializamos xkmas con x_1
	while (f(xkmas) != 0 && n <= nmax)          //iteramos hasta llegar al máximo u obtener una x_k con precisión suficiente
	{
		xk = xkmas;
		xkmas = xk - 2*f(xk)*fprima(xk)/(2*fprima(xk)*fprima(xk) - f(xk)*fdobleprima(xk));
		n++;
	}
	printf("x_%d = %.16G, f(x_%d) = %.16G\n", n - 1, xkmas, n - 1, f(xkmas));       //imprimimos en la consola la raíz obtenida
	return (0);
}
