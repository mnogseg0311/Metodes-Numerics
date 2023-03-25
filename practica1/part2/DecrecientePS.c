//Programa que calcula, en doble precisi�n, la suma de los inversos de los cuadrados de los naturales diferentes de 0. Con �ndice del sumatorio decreciente.

#include <math.h>
#include <stdio.h>

int	main()
{
	int 	n = 100000;   //N�mero de sumantes de la suma parcial a calcular
	float	sn = 0;       //Vairable, en simple precisi�n, en la que vamos guardando las sumas parciales
	float   a = n;        //Variable auxiliar

	for(int i = n; i >= 1; i--)     //Calculamos la suma
    {
        sn += 1/(a*a);
        a--;
    }
	printf("Sn = %.8G\n", sn);       //Imprimimos sn por pantalla
	return (0);
}
