//Programa de ejemplo que calcula, en simple precisi�n, la varianza muestral de 150 n�meros determinados para observar discrepancias entre las dos f�rmulas dadas en el
//ejercicio 3 de M�todos Num�ricos de 2023
#include <stdio.h>
#include <math.h>

int main() {
    int n = 150; 		//N�mero de elementos de los que queremos calcular la varianza muestral
    float x[n]; 		//Inicializamos el vector donde guardaremos los valores de los que calcularemos la varianza muestral
    float X = 0; 		//Variable auxiliar, en simple precisi�n
    float Y = 0; 		//Variable auxiliar, en simple precisi�n
    float Z = 0; 		//Variable auxiliar, en simple precisi�n
    float sn = 0; 		//Variable en la que se guarda, en simple precisi�n, la varianza muestral
    float a = 0;		//Variable auxiliar utilizada para crear el vector
    int i; 			//�ndice para los bucles

    //Inicializamos el vector
    for (i=0; i<n; i++)	{	//Los elementos elegidos conforman una sucesi�n creciente a partir del 13.000
        x[i] = 13000 + a/30; 	//Entre ellos hay un incremento de 1/30
        a++;
        }
    //Calculamos la varianza muestral usando la primera f�rmula del ejercicio
    for (i=0; i<n; i++)		//Calculamos el primer sumatorio de x barra y lo guardamos en la variable auxiliar X
        X += x[i];
    X /= n;
    for (i=0; i<n; i++)
        sn += (x[i] - X)*(x[i] - X);
    sn /= (n-1);
    //Retornamos por pantalla el resultado obtenido, dando todas las cifras significativas
    fprintf(stdout, "La varianza muestral del vector introducido es: %.8G \n\n", sn); 
    //Calculamos la varianza muestral usando la segunda f�rmula del ejercicio	
    for (i=0; i<n; i++)		//Calculamos el sumatorio de los cuadrados de los valores x_i y lo guardamos en la variable auxiliar Y
        Y += x[i]*x[i];
    for (i=0; i<n; i++)		//Calculamos el sumatorio de los x_i y lo guardamos en la variable auxiliar Z
        Z += x[i];
    //Retornamos la varianza muestral calculada a partir de la segunda f�rmula, dando todas las cifras significativas
    fprintf(stdout, "La varianza muestral del vector introducido es: %.8G \n", (Y-Z*Z/n)/(n-1)); 
    return 0;
}
