//Programa que calcula, en simple precisión, la suma de los inversos de los cuadrados de los naturales diferentes de 0. Con índice del sumatorio creciente.

#include <stdio.h>
#include <math.h>

int main() {
    int n = 10000;      //Número de sumantes de la suma parcial a retornar
    float sn = 0;       //Vairable, en simple precisión, en la que vamos guardando las sumas parciales
    float a = 0;        //Variable auxiliar

    for (int i=1; i<n; i++) {     //Calculamos la suma
        a++;
        sn += 1/(a*a);
    }
    fprintf(stdout, "Sn = %.8G\n", sn);     //Imprimimos sn por pantalla
    return 0;
}
