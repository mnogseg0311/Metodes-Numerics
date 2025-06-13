// Programa que calcula un cero del polinomio x^3-x-40 utilizando la f�rmula de Cardano
#include <stdio.h>
#include <math.h>

int main() {
    float xf = powf(20 + sqrtf(32397)/9, (float)1/3) + powf(20 - sqrtf(32397)/9, (float)1/3); //    Aproximaci�n de la ra�z en simple precisi�n
    double xd = pow(20 + sqrt(32397)/9, 1./3) + pow(20 - sqrt(32397)/9, 1./3); //   Aproximaci�n de la ra�z en doble precisi�n

    fprintf(stdout, "xf = %.8G \n", xf); //     Imprimimos la aproximaci�n en simple precisi�n
    fprintf(stdout, "xd = %.16G \n", xd); //    Imprimimos la aproximaci�n en doble precisi�n

    fprintf(stdout, "p(alfa) = %.8G\n", xf*xf*xf -xf -40); //   Eval�amos el polinomio en la aproximaci�n de la ra�z en simple precisi�n
    fprintf(stdout, "p(alfa) = %.16G\n", xd*xd*xd -xd -40); //   Eval�amos el polinomio en la aproximaci�n de la ra�z en doble precisi�n
    return 0;
}
