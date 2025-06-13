//Programa que calcula la iteración pk propuesta en el ejercicio 4 que teoricamente converge en pi
//Imprime por pantalla el error absoluto de cada paso de la iteración.

#include <stdio.h>
#include <math.h>

int	main()
{
	double	pk;                             //guardaremos los valores de la sucesión siguiendo la iteración
	double	ak, akmenos = 1;                //guardaremos la media aritmética, inicializamos akmenos con a_0
	double	bk, bkmenos = 1/sqrt(2);        //guardaremos la media geométrica, inicializamos bkmenos con b_0
	double	ck;                             //guardaremos la diferencia de los cuadrados de las medias
	double	sk, skmenos = 1./2;             //guardaremos la anterior menos dos a la k veces la ck
	int	k = 1, kmax = 15;                   //k indica en qué iteración está, kmax es el número de iteraciónes que vamos a calcular
	double PI = 3.14159265358979323846;     //aproximación de pi como un double

	while (k <= kmax)           //iteramos
	{
		ak = (akmenos + bkmenos) / 2;
		bk = sqrt(akmenos * bkmenos);
		ck = ak*ak - bk*bk;
		sk = skmenos - pow(2, k) * ck;
		pk = 2 * ak*ak / sk;
		printf("Ea_%d = %.16G\n", k, pk - PI);      //imprimimos el error absoluto de pk respecto pi
		akmenos = ak;
		bkmenos = bk;
		skmenos = sk;
		k++;
	}
	return (0);
}
