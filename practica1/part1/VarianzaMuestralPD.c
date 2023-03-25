//Programa que calcula, en doble precisión, la varianza muestral de n números determinados
#include <stdio.h>
#include <math.h>

int main() {
    int n = 3; 				//Número de elementos de los que queremos calcular la varianza muestral
    double x[] = {10000,10001,10002}; 	//Elementos de los que queremos calcular la varianza muestral
    double X = 0; 			//Variable auxiliar, en doble precisión
    double Y = 0; 			//Variable auxiliar, en doble precisión
    double Z = 0; 			//Variable auxiliar, en doble precisión
    double sn = 0; 			//Variable en la que se guarda, en doble precisión, la varianza muestral
    int i; 				//Índice para los bucles

    //Calculamos la varianza muestral usando la primera fórmula del ejercicio
    for (i=0; i<n; i++)		//Calculamos el primer sumatorio de x barra y lo guardamos en la variable auxiliar X
        X += x[i];
    X /= n;
    for (i=0; i<n; i++)
        sn += (x[i] - X)*(x[i] - X);
    sn /= (n-1);
    //Retornamos por pantalla el resultado obtenido, dando todas las cifras significativas
    fprintf(stdout, "La varianza muestral del vector introducido es: %.16G \n", sn);
    //Calculamos la varianza muestral usando la segunda fórmula del ejercicio	
    for (i=0; i<n; i++)		//Calculamos el sumatorio de los cuadrados de los valores x_i y lo guardamos en la variable auxiliar Y
        Y += x[i]*x[i];
    for (i=0; i<n; i++)		//Calculamos el sumatorio de los x_i y lo guardamos en la variable auxiliar Z
        Z += x[i];
    //Retornamos la varianza muestral calculada a partir de la segunda fórmula, dando todas las cifras significativas
    fprintf(stdout, "La varianza muestral del vector introducido es: %.16G \n", (Y-Z*Z/n)/(n-1)); 
    return 0;
}
