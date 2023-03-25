//Programa que calcula, en simple precisi�n, menos dos veces el sumatorio alternado de los inversos de los naturales al cuadrado.
//Con �ndice del sumatorio decreciente.

#include <stdio.h>
#include <math.h>

int main() {
    int n = 50000;      //N�mero de sumantes de la suma parcial a retornar
    float sn = 0;       //Vairable, en simple precisi�n, en la que vamos guardando las sumas parciales
    float a = n;        //Variable auxiliar

    for (int i=n; i>=1; i--) {     //Calculamos el sumatorio
        if (i % 2 == 0)
            sn += 1/(a*a);         //-1 elevado a un n�mero par es 1
        else
            sn -= 1/(a*a);         //-1 elevado a un n�mero impar es -1
        a--;
    }
    sn = -2 * sn;
    fprintf(stdout, "Sn = %.8G\n", sn);     //Imprimimos sn por pantalla
    return 0;
}
