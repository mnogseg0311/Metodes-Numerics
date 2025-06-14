//Programa que eval�a la funci�n f, usando simple precisi�n, definida con una f�rmula alternativa a la del ejercicio 1 de la pr�ctica de M�todos Num�ricos de 2023
#include <stdio.h>
#include <math.h>

int main() {
    float x = 1.2E-5;		//Valor en el que queremos evaluar la funci�n f
    float fx = 0;		//Variable donde guardamos f(x)
    
    if (x==0)		//Por definici�n de f, f(0)= 1/2
        fx = 1/2;
    else		//Usaremos la funci�n sinf, que toma y devuelve valores en simple precisi�n
        fx = (2*sinf(x/2)*sinf(x/2))/(x*x);
    printf("f(%.8G) = %.8G\n", x, fx);		//Retornamos f evaluada en x
    return 0;
}
