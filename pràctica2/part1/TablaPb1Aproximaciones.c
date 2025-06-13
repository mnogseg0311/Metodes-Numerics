// Programa que imprime una tabla con las aproximaciones del cero positivo del polinomio del problema 1 de la segunda práctica de Métodos Numéricos
// del curso 2023 para los métodos de bisección, secante y Newton, junto al número de iteraciones

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double f(double x) { //    Función que evalúa el polinomio del enunciado
    return x*x*x - x - 400;
}

double df(double x) { //    Función que evalúa la derivada del polinomio del enunciado
    return 3*x*x - 1;
}

void    imprime_fila(int *CadenasVacias, double aBis, double bBis, double x, double bSec, int n)
{
    char    *aux;       //variable que utilizamos para no imprimir directamente y así poder controlar que quede alineado

    aux = malloc(sizeof(char) * 23);   //reservamos memoria
    if (!aux)
        return ;

    if (*CadenasVacias == 1) { // Si ya hemos acabado dejamos el espacio vacío
        sprintf(aux, "%s", " ");
        for (int i=0; i<21; i++)
            strcat(aux, " ");
        printf("|     %d     | %s | ", n + 1, aux);    //imprimimos espacios en la primera aproximación
    }
    else if (*CadenasVacias == 0) {
        sprintf(aux, "%.16G", (aBis + bBis)/2);     //guardamos en aux la primera aproximación
        for (int len = strlen(aux); len < 22; len++)   //añadimos los espacios necesarios para que quede recto
            strcat(aux, " ");
        if (n+1 < 10)
            printf("|     %d     | %s | ", n + 1, aux);    //imprimimos la primera aproximación
        else
            printf("|     %d    | %s | ", n + 1, aux);    //imprimimos la primera aproximación
    }
    else {
        fprintf(stderr, "Error.\n");
        return;
    }

    if (*(CadenasVacias+1) == 1) { // Si ya hemos acabado dejamos el espacio vacío
        sprintf(aux, "%s", " ");
        for (int i=0; i<21; i++)
            strcat(aux, " ");
        printf("%s | ", aux);    //imprimimos espacios en la segunda aproximación
    }
    else if (*(CadenasVacias+1) == 0) {
        sprintf(aux, "%.16G", x);                      //guardamos en aux la segunda aproximación
        for (int len = strlen(aux); len < 22; len++)   //añadimos los espacios necesarios para que quede recto
            strcat(aux, " ");
        printf("%s | ", aux);                                   //imprimimos el segundo cociente
    }
    else {
        fprintf(stderr, "Error.\n");
        return;
    }

    if (*(CadenasVacias+2) == 1) { // Si ya hemos acabado dejamos el espacio vacío
        sprintf(aux, "%s", " ");
        for (int i=0; i<21; i++)
            strcat(aux, " ");
        printf("%s | \n", aux);    //imprimimos espacios en la tercera aproximación
    }
    else if (*(CadenasVacias+2) == 0) {
        sprintf(aux, "%.16G", bSec);  //guardamos en aux la tercera aproximación
        for (int len = strlen(aux); len < 22; len++)            //añadimos los espacios necesarios para que quede recto
            strcat(aux, " ");
        printf("%s | \n", aux);       //imprimimos la tercera aproximación
    }
    else {
        fprintf(stderr, "Error.\n");
        return;
    }

    for (int i = 0; i < 88; i++)  //imprimimos un separador de filas
        printf("-");
    printf("\n");   //imprimimos un salto de línea
    free(aux);      //liberamos la memoria
    return;
}

int main() {
    double aSec = 2, bSec = 8, auxSec = 0, aBis = 2, bBis = 8, x = 2, auxNew = 0, p = 0;
    int n = 0, nmax = 100;
    int *CadenasVacias; // Vector en el que guardaremos si se debe imprimir algo o se debe dejar vacío el hueco correspondiente

    CadenasVacias = calloc(3, sizeof(char));   //reservamos memoria e inicializamos el vector a 0 posición normal que indica que todo se debe imprimir
    if (!CadenasVacias) {
        fprintf(stderr, "No se ha podido reservar la memoria.\n");
        return 1;
    }

    for (int i = 0; i < 88; i++)                //imprimimos una separación
        printf("-");
    printf("\n");
	printf("| iteracion |        Biseccion       |         Newton         |        Secante         |\n");       //imprimimos las referencias de la tabla

    for (int i = 0; i < 88; i++)                //imprimimos una separación
        printf("-");
    printf("\n");

    while (((8.-2.)/pow(2,n) > 1E-15 || fabs(aSec-bSec) > 1E-15 || fabs(x - auxNew) > 1E-15) && n<nmax) {
        for (int i=0; i<3; i++) // Reiniciamos el vector a 0
            CadenasVacias[i] = 0;

        if ((8.-2.)/pow(2,n) > 1E-15) {
            p = (aBis + bBis)/2;      //    Calculamos el punto medio del intervalo actual
            if (f(aBis)*f(p) <= 0)    //    Veamos en qué subdivisión del intervalo está el cero
                bBis = p;             //    El cero se encuentra a la derecha del punto medio
            else
                aBis = p;             //    El cero se encuentra a la izquierda del punto medio
        }
        else
            CadenasVacias[0] = 1; // Indicamos que no se debe imprimir nada en el hueco de bisección

        if (fabs(x - auxNew) > 1E-15) {
            auxNew = x; //    Guardamos el valor antes de operar
            x -= f(x)/df(x); //    Aplicamos el algoritmo del método de Newton
        }
        else
            CadenasVacias[1] = 1; // Indicamos que no se debe imprimir nada en el hueco de Newton

        if (fabs(aSec-bSec) > 1E-15) {
            aSec = aSec - f(aSec)*(bSec-aSec)/(f(bSec)-f(aSec)); //  Reescribimos la variable a con el nuevo valor de la sucesión, ya que el valor que guardaba ya no lo necesitamos
            auxSec = aSec;
            aSec = bSec; //   Intercambiamos los valores de las variables a y b
            bSec = auxSec;
        }
        else
            CadenasVacias[2] = 1; // Indicamos que no se debe imprimir nada en el hueco de la secante


        imprime_fila(CadenasVacias, aBis, bBis, x, bSec, n);

        n++;
    }
    free(CadenasVacias);
    return 0;
}
