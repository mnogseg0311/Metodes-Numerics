//Programa que evalúa la función f, usando doble precisión, definida con una fórmula alternativa a la del ejercicio 1 de la práctica de Métodos Numéricos de 2023
#include <stdio.h>
#include <math.h>

int main() {
    double x = 1.2E-5;		//Valor guardado en el que queremos evaluar la función f
    double fx = 0;		//Variable donde guardamos f(x)
    
    if (x==0)		//Por definición de f, f(0)= 1/2
        fx = 1/2;
    else		//Usaremos la función sin, que toma y devuelve valores en doble precisión
    	fx = (2*sin(x/2)*sin(x/2))/(x*x);
    printf("f(%.16G) = %.16G\n", x, fx);		//Retornamos f evaluada en x
    return 0;
}
