//Programa que calcula la iteración pk propuesta en el ejercicio 4 que teoricamente converge en pi
//Imprime por pantalla una tabla que muestra los cocientes de las diferencias entre las iteraciones para apreciar su convergencia

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int int_len(int n)
{
    int i = 1;      //va a guardar el número de dígitos
    int pot = 10;   //iremos multiplicando por 10 para obtener las potencias de 10

    //mientras la división entera del entero entre la potencia de diez sea distinta de 0, aún nos faltan dígitos
    while (n / pot != 0)
    {
        pot = 10 * pot;
        i++;
    }
    return (i);
}

void    imprime_fila(double ek, double ekmenos, int k)
{
    char    *aux;       //variable que utilizamos para no imprimir directamente y así poder controlar que quede alineado

    aux = malloc(sizeof(char) * 23);        //reservamos memoria
    if (!aux)
        return ;
    sprintf(aux, "%d", k);          //guardamos en aux la iteracion
    for (int len = int_len(k); len < 6; len++)         //añadimos los espacios necesarios para que quede recto
            strcat(aux, " ");
    printf("|     %s|", aux);      //imprimimos el número de iteracion
    sprintf(aux, "%.16G", ek / ekmenos);             //guardamos en aux el primer cociente
    for (int len = strlen(aux); len < 22; len++)         //añadimos los espacios necesarios para que quede recto
        strcat(aux, " ");
    printf(" %s | ", aux);      //imprimimos el primer cociente
    sprintf(aux, "%.16G", ek / (ekmenos*ekmenos));   //guardamos en aux el segundo cociente
    for (int len = strlen(aux); len < 22; len++)         //añadimos los espacios necesarios para que quede recto
        strcat(aux, " ");
    printf("%s |\n", aux);                            //imprimimos el segundo cociente
    for (int i = 0; i < 63; i++)                     //imprimimos un separador de filas
        printf("-");
    printf("\n");   //imprimimos un salto de línea
    free(aux);      //liberamos la memoria
}

int	main()
{
	double	pk, pkmenos =0;                 //guardaremos los valores de la sucesión siguiendo la iteración
	double	ek, ekmenos;                    //ek es la diferencia en valor absoluto entre pk y pkmenos
	double	ak, akmenos = 1;                //guardaremos la media aritmética, inicializamos akmenos con a_0
	double	bk, bkmenos = 1/sqrt(2);        //guardaremos la media geométrica, inicializamos bkmenos con b_0
	double	ck;                             //guardaremos la diferencia de los cuadrados de las medias
	double	sk, skmenos = 1./2;             //guardaremos la anterior menos dos a la k veces la ck
	int	k = 1, kmax = 15;                   //k indica en qué iteración está, kmax es el número de iteraciónes que vamos a calcular

	for (int i = 0; i < 63; i++)                //imprimimos una separación
        printf("-");
    printf("\n");
	printf("| iteracion |       e_k / e_k-1      |    e_k / (e_k-1)^2     |\n");       //imprimimos las referencias de la tabla
	for (int i = 0; i < 63; i++)                //imprimimos una separación
        printf("-");
    printf("\n");
	while (k <= kmax)          //iteramos
	{
		ak = (akmenos + bkmenos) / 2;
		bk = sqrt(akmenos * bkmenos);
		ck = ak*ak - bk*bk;
		sk = skmenos - pow(2, k) * ck;
		pk = 2 * ak*ak / sk;
		ek = fabs(pk - pkmenos);
		if (k >= 2)
            imprime_fila(ek, ekmenos, k);       //imprimimos una fila de la tabla
		akmenos = ak;
		bkmenos = bk;
		skmenos = sk;
		pkmenos = pk;
		ekmenos = ek;
		k++;
	}
	return (0);
}
