//Programa que calcula la iteraci�n pk propuesta en el ejercicio 4 que teoricamente converge en pi
//Imprime por pantalla el error absoluto de cada paso de la iteraci�n.

#include <stdio.h>
#include <math.h>

int	main()
{
	double	pk;                             //guardaremos los valores de la sucesi�n siguiendo la iteraci�n
	double	ak, akmenos = 1;                //guardaremos la media aritm�tica, inicializamos akmenos con a_0
	double	bk, bkmenos = 1/sqrt(2);        //guardaremos la media geom�trica, inicializamos bkmenos con b_0
	double	ck;                             //guardaremos la diferencia de los cuadrados de las medias
	double	sk, skmenos = 1./2;             //guardaremos la anterior menos dos a la k veces la ck
	int	k = 1, kmax = 15;                   //k indica en qu� iteraci�n est�, kmax es el n�mero de iteraci�nes que vamos a calcular
	double PI = 3.14159265358979323846;     //aproximaci�n de pi como un double

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
