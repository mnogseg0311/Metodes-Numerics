//apartado c del problema extra
//crea dos polinomios de tercer grado aleatoriamente (con coeficientes naturales) p y q
//calcula una aproximación (muy erronea según que casos) con el algoritmo visto en el apartado b del problema de la práctica
//de las diferentes f(x) hasta encontrar una con la precisión deseada
//en algunos casos la aproximación da un -1.#IND seguramente a causa del cálculo de una raíz negativa. Vuelvase a compilar.

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

double	aproximar(double x, int p[4], int q[4])
{
	double	b = f(x, p, q);     //guardamos el producto de las imágenes de las iteraciones
	double	a = x;              //guardamos las iteraciones
	double	amas;               //auxiliar para las iteraciones
	double  eabs;               //guardamos el error absoluto
	int		k = 20;             //número de f(x) que generamos aleatoriamente

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
	eabs = fabs(sqrt(1 + x) - fabs(b * sqrt(1 + amas)));                    //calculamos el error absoluto
	printf("error absoluto = %.16G\n\n", eabs);
	return (eabs);
}

int main()
{
    double  x = 8;      //aproximaremos la raíz de 1 + x
    int     p[4];       //guardaremos los coeficientes de p(x)
    int     q[4];       //guardaremos los coeficientes de q(x)

    srand (time(NULL));         //inicializamos el generador de numeros aleatorios
    printf("arrel real: sqrt(%f) = %f\n\n", x + 1, sqrt(x + 1));      //imprimimos la raíx en precisión doble
    for (int i = 0; i <= 4; i++)        //inicializamos
    {
        p[i] = rand();
        q[i] = rand();
    }
    while (aproximar(x, p, q) >= 1E-3)       //hasta encontrar una suficientemente precisa
    {
        for (int i = 0; i <= 4; i++)        //generamos los coeficienes de p i q aleatoriamente
        {
            p[i] = rand();
            q[i] = rand();
        }
    }
    return (0);
}
