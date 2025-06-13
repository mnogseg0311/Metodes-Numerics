// Programa que calcula un cero del polinomio x^3-x-40 utilizando la fórmula de Cardano
#include <stdio.h>
#include <math.h>

int main() {
    float xf = powf(20 + sqrtf(32397)/9, (float)1/3) + powf(20 - sqrtf(32397)/9, (float)1/3); //    Aproximación de la raíz en simple precisión
    double xd = pow(20 + sqrt(32397)/9, 1./3) + pow(20 - sqrt(32397)/9, 1./3); //   Aproximación de la raíz en doble precisión

    fprintf(stdout, "xf = %.8G \n", xf); //     Imprimimos la aproximación en simple precisión
    fprintf(stdout, "xd = %.16G \n", xd); //    Imprimimos la aproximación en doble precisión

    fprintf(stdout, "p(alfa) = %.8G\n", xf*xf*xf -xf -40); //   Evalúamos el polinomio en la aproximación de la raíz en simple precisión
    fprintf(stdout, "p(alfa) = %.16G\n", xd*xd*xd -xd -40); //   Evalúamos el polinomio en la aproximación de la raíz en doble precisión
    return 0;
}
