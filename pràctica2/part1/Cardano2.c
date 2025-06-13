// Programa que calcula el cero real positivo de x^3 - x - 400 a partir de la fórmula de Cardano, en doble precisión

#include <stdio.h>
#include <math.h>

int main() {
    double x = 0; //    Inicializamos en doble precisión la variable en la que guardaremos el valor aproximado del cero del polinomio

    x += pow(200 + 1./9*sqrt(3239997), 1./3); //   Aproximación de la raíz
    x += pow (200 - 1./9*sqrt(3239997), 1./3); //   Aproximación de la raíz

    printf("El cero aproximado del polinomio es: %.16G \n", x); //    Imprimimos por pantalla el valor de la aproximación del cero del polinomio
    printf("p(alfa) = %.16G \n", x*x*x - x - 400); //    Imprimos el valor del polinomio evaluado en la aproximación encontrada

    return 0;
}
