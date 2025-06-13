//apartado c del problema extra
//crea dos polinomios de tercer grado aleatoriamente (con coeficientes naturales) p y q
//calcula una aproximaci�n (muy erronea seg�n que casos) con el algoritmo visto en el apartado b del problema de la pr�ctica

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

double	f(double x, int p[4], int q[4])     //retorna el cociente de los polinomios evaluado en x
{
	return ((p[0]*x*x*x + p[1]*x*x + p[2]*x + p[3])/(q[0]*x*x*x + q[1]*x*x + q[2]*x + q[3]));
}

double	g(double x, int p[4], int q[4])         //g(x)
{
	return ((1 + x)/(f(x, p, q)*f(x, p, q)) - 1);
}

void	aproximar(double x, int p[4], int q[4])
{
	double	b = f(x, p, q);     //guardaremos el producto de las im�genes de las iteraciones
	double	a = x;              //guardamos las iteraciones
	double	amas;               //auxiliar para las iteraciones
	int		k = 20;             //n�mero de f(x) que generamos aleatoriamente


	for (int j = 1; j <= k; j++)        //iteramos
	{
		amas = g(a, p, q);
		b *= f(a, p, q);
		a = amas;
	}
	amas = g(a, p, q);
	printf("p(x) = %dx^3 + %dx^2 + %dx + %d\n", p[0], p[1], p[2], p[3]);        //imprimimos
	printf("q(x) = %dx^3 + %dx^2 + %dx + %d\n", q[0], q[1], q[2], q[3]);
	printf("aproximacion raiz = %.16G\n", b * sqrt(1 + amas));
	printf("error absoluto = %.16G\n\n", fabs(sqrt(1 + x) - fabs(b * sqrt(1 + amas))));
}

int main()
{
    double  x = 8;      //aproximaremos la ra�z de 1 + x
    int     p[4];       //guardaremos los coeficientes de p(x)
    int     q[4];       //guardaremos los coeficientes de q(x)
    int     aproximaciones = 20;        //numero de funciones que queremos testear

    srand (time(NULL));         //inicializamos el generador de numeros aleatorios
    printf("arrel real: sqrt(%f) = %f\n\n", x + 1, sqrt(x + 1));      //imprimimos la ra�x en precisi�n doble
    for (int k = 0; k <= aproximaciones; k++)       //tantas veces como queramos generar una f aleatoria para probarla
    {
        for (int i = 0; i <= 4; i++)        //generamos los coeficienes de p i q aleatoriamente
        {
            p[i] = rand();
            q[i] = rand();
        }
        aproximar(x, p, q);         //calculamos la aproximaci�n
    }
    return (0);
}
