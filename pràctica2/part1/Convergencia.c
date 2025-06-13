//Programa que calcula el cero real del polinomio x^3 - x - 400 utilizando la iteración propuesta en el ejercicio 2
//e imprime por pantalla una tabla que muestra los cocientes de las diferencias entre las iteraciones para apreciar su convergencia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void    imprime_fila(double ek, double ekmenos, int n)
{
    char    *aux;       //variable que utilizamos para no imprimir directamente y así poder controlar que quede alineado

    aux = malloc(sizeof(char) * 23);        //reservamos memoria
    if (!aux)
        return ;
    sprintf(aux, "%.16G", ek / ekmenos);             //guardamos en aux el primer cociente
    for (int len = strlen(aux); len < 22; len++)         //añadimos los espacios necesarios para que quede recto
        strcat(aux, " ");
    printf("|     %d     | %s | ", n + 1, aux);      //imprimimos el primer cociente
    sprintf(aux, "%.16G", ek / (ekmenos*ekmenos));   //guardamos en aux el segundo cociente
    for (int len = strlen(aux); len < 22; len++)         //añadimos los espacios necesarios para que quede recto
        strcat(aux, " ");
    printf("%s | ", aux);                            //imprimimos el segundo cociente
    sprintf(aux, "%.16G", ek / (ekmenos*ekmenos*ekmenos));      //guardamos en aux el tercer cociente
    for (int len = strlen(aux); len < 22; len++)         //añadimos los espacios necesarios para que quede recto
        strcat(aux, " ");
    printf("%s | \n", aux);                          //imprimimos el tercer cociente
    for (int i = 0; i < 88; i++)                     //imprimimos un separador de filas
        printf("-");
    printf("\n");   //imprimimos un salto de línea
    free(aux);      //liberamos la memoria
}

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
	double	xk = 6, xkmas;                      //variables donde vamos guardando las equis, xk se inicializa con el valor de x_0
	double	bk = 1/fprima(xk), bkmas;           //variables donde vamos guardando las bes, el valor b_0 inicial depende de x_0
	double	ekmenos, ek = 0;                    //ek es la diferencia en valor absoluto entre xkmas y xk
	int	n = 1, nmax = 10;                       //con n sabemos cuántas iteraciones hemos hecho y, nmax es un límite para estas

	xkmas = xk - bk * f(xk);                    //inicializamos xkmas con x_1
	bkmas = bk * (2 - fprima(xkmas) * bk);      //inicializamos bkmas con b_1
	ekmenos = fabs(xkmas - xk);                 //inicializamos ekmenos con e_1
	for (int i = 0; i < 88; i++)                //imprimimos una separación
        printf("-");
    printf("\n");
	printf("| iteracion |       e_k / e_k-1      |    e_k / (e_k-1)^2     |    e_k / (e_k-1)^3     |\n");       //imprimimos las referencias de la tabla
	for (int i = 0; i < 88; i++)                //imprimimos una separación
        printf("-");
    printf("\n");
	while (f(xkmas) != 0 && n <= nmax)          //iteramos hasta llegar al máximo u obtener una x_k la imagen de la qual sea 0, en precisión doble
	{
		xk = xkmas;
		bk = bkmas;
		xkmas = xk - bk * f(xk);
		bkmas = bk * (2 - fprima(xkmas) * bk);
		ek = fabs(xkmas - xk);
		imprime_fila(ek, ekmenos, n);           //imprimimos una fila de la tabla
		ekmenos = ek;
		n++;
	}
	return (0);
}
