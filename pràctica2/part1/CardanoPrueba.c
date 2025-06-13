// Programa de prueba para ver los errores de cada operación usando doble y cuádruple precisión
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main() {
    printf("Doble precision:\n");
    printf("sqrt(32397)/9 = %.16G\n", sqrt(32397)/9);
    printf("20 + sqrt(32397)/9 = %.16G\n", 20 + sqrt(32397)/9);
    printf("(20 + sqrt(32397)/9)^(1/3) = %.16G\n", pow(20 + sqrt(32397)/9, 1./3));
    printf("(20 + sqrt(32397)/9)^(1/3) + (20 - sqrt(32397)/9)^(1/3) = %.16G\n\n", pow(20 + sqrt(32397)/9, 1./3) + pow(20 - sqrt(32397)/9, 1./3));

    printf("Cuadruple precision:\n");
    printf("20 + sqrt(32397)/9 = %Lf\n", sqrtl(32397)/9);
    printf("20 + sqrt(32397)/9 = %Lf\n", 20 + sqrtl(32397)/9);
    printf("(20 + sqrt(32397)/9)^(1/3) = %Lf\n", powl(20+sqrtl(32397)/9, 1L/3));
    printf("(20 + sqrt(32397)/9)^(1/3) + (20 - sqrt(32397)/9)^(1/3) = %Lf\n\n", powl(20 + sqrtl(32397)/9, 1L/3) + powl(20 - sqrtl(32397)/9, 1L/3));

    double x;
    long double y;
    x = sqrt(32397)/9;
    y = sqrtl(32397)/9;
    printf("Perdida de precision raiz cuadrada: %Lf\n", fabsl(x - y));
    x = 20. + sqrt(32397)/9;
    y = 20L + sqrtl(32397)/9;
    printf("Perdida de precision suma: %Lf\n", fabsl(x - y));
    x = pow(20 + sqrt(32397)/9, 1./3);
    y = powl(20+sqrtl(32397)/9, 1L/3);
    printf("Perdida de precision raiz cubica: %Lf\n", fabsl(x - y));
    x = pow(20 + sqrt(32397)/9, 1./3) + pow(20 - sqrt(32397)/9, 1./3);
    y = powl(20 + sqrtl(32397)/9, 1L/3) + powl(20 - sqrtl(32397)/9, 1L/3);
    printf("Perdida general: %Lf\n", fabsl(x - y));
    return 0;
}
