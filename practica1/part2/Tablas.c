//Fichero Tablas.c
//Programa que calcula, en simple y doble precisión, la suma de los inversos de los cuadrados de los naturales diferentes de 0.
//Lo hace mediante los tres algoritmos descritos en el informe de la segunda parte de la primera práctica de metodos numéricos.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*función que calcula el número de dígitos de un entero*/
static int int_len(int n)
{
    int i = 1;      //va a guardar el número de dígitos
    int pot = 10;   //iremos multiplicando por 10 para obtener las potencias de 10

    //mientras la división entera del entero entre la potencia de diez sea distinta de 0, aún nos faltan dígitos
    while (n / pot != 0)
    {
        pot = 10 * pot;
        i++;
    }
    return (i);
}

/*función que imprime una línea horizontal, de longitud una cantidad calculada según el número de dígitos del entero
más grande de la primera columna, n, más cierto número de guiones pasado como argumento*/
static void    separador(int n, int len)
{
    char    *aux;

    //calculamos la primera cantidad
    aux = malloc(sizeof(char) * int_len(n) + 1);
    if (!aux)
        return;
    sprintf(aux, "%i", n);
    //imprimimos los guiones
    for (long unsigned int i = 0; i < len + strlen(aux); i++)
	    fprintf(stdout, "-");
    //imprimimos un salto de linea
    fprintf(stdout, "\n");
    free(aux);
}

/*función que imprime una línea de la tabla, en precisión doble, pasados los distintos valores calculados en la función doble.
Para que quede bien alineado, pasamos los enteros y flotantes a arrays y añadimos espacios en caso de ser necesario*/
static void    imprimir_linea_doble(int n, int i, double s1, double s2, double s3)
{
    char    *s, *aux;           //arrays utilizados para imprimir el número de sumantes i
    char    *sn1, *sn2, *sn3;   //arrays donde guardamos s1, s2 y s3 en formato array respectivamente
    int		len;                //variable auxiliar donde iremos guardando la longitud de las cadenas mientras añadimos espacios

    //guardamos i en formato char puntero en s
    s = malloc(sizeof(char) * int_len(i) + 1);
    if (!s)
        return;
    sprintf(s, "%i", i);
    //guardamos n en formato char puntero en aux (es el número más grande que vamos a tener que imprimir en la primera columna)
    aux = malloc(sizeof(char) * int_len(n) + 1);
    if (!aux)
        return;
    sprintf(aux, "%i", n);
    //añadimos en s los espacios que sean necesarios
    len = strlen(s);        //vamos a ir modificando la longitud de s en el bucle, necesitamos mantener el valor original
    for (long unsigned int j = 0; j < strlen(aux) - len; j++)
        s = strcat(s, " ");
    free(aux);
    //guardamos s1 en sn1 en formato char puntero
    //la impresión en el formato %.16G no necesita más de 22 caracteres
    sn1 = malloc(sizeof(char) * 23);
    if (!sn1)
        return;
    sprintf(sn1, "%.16G", s1);
    //añadimos en s los espacios que sean necesarios
    len = strlen(sn1);
    for (int j = 0; j < 23 - len; j++)
	    sn1 = strcat(sn1, " ");
    //guardamos s2 en sn2 en formato char puntero
    sn2 = malloc(sizeof(char) * 23);
    if (!sn2)
        return;
    sprintf(sn2, "%.16G", s2);
    //añadimos en s los espacios que sean necesarios
    len = strlen(sn2);
    for (int j = 0; j < 23 - len; j++)
	    sn2 = strcat(sn2, " ");
    //guardamos s3 en sn3 en formato char puntero
    sn3 = malloc(sizeof(char) * 23);
    if (!sn3)
        return;
    sprintf(sn3, "%.16G", s3);
    //añadimos en s los espacios que sean necesarios
    len = strlen(sn3);
    for (int j = 0; j < 23 - len; j++)
        sn3 = strcat(sn3, " ");
    //imprimimos la línea
    fprintf(stdout, "| %s | %s | %s | %s |\n", s, sn1, sn2, sn3);
    separador(n, 82);
    //liberamos el espacio reservado para los arrays
    free(sn1);
    free(sn2);
    free(sn3);
}

/*función que calcula, en precisión doble, las sumas parciales de la serie mediante los tres algoritmos distintos.
Lo hace de bloque en bloque los tres a la vez para poder ir imprimiendo las filas de la tabla.*/
static void    doble(int n, int bloque, double suma, int opcion)
{
    double   s1 = 0, s2, s3;        //variables donde guardamos las sumas parciales de los algoritmos 1, 2 y 3 respectivamente.
    double   a1 = 1, a2, a3;        //variables auxiliares utilizadas para calcular los distintos términos a sumar.

    for (int i = bloque; i <= n; i += bloque)   //Cada iteración del bucle es una suma parcial
    {
        //Calculamos la suma mediante el algoritmo 1 (índice creciente).
        //Podemos reutilizar s1, porque una suma parcial es la anterior más algunos términos
        for (int k = i - bloque; k < i; k++)
        {
            s1 += 1/(a1*a1);
            a1++;
        }
        //Calculamos la suma mediante el algoritmo 2 (índice decreciente)
        //No podemos reutilizar s2, porque el término inicial es distinto en cada caso
        a2 = i;
        s2 = 0;
        for (int j = i; j > 0; j--)
        {
            s2 += 1/(a2*a2);
            a2--;
        }
        //Calculamos la suma mediante el algoritmo 3 (expresión alternativa, índice decreciente)
        //No podemos reutilizar s2, porque el término inicial es distinto en cada caso
        a3 = i;
        s3 = 0;
        for (int l = i; l > 0; l--)
        {
            if (l % 2 == 0)
                s3 += 1/(a3*a3);
            else
                s3 -= 1/(a3*a3);
            a3--;
        }
        //Imprimimos una línea de la tabla
        if (opcion == 0)
            imprimir_linea_doble(n, i, s1, s2, -2 * s3);           //con los valores de las aproximaciones
        else
            imprimir_linea_doble(n, i, suma - s1, suma - s2, suma + 2*s3);      //con los errores absolutos
    }
}

/*función que imprime una línea de la tabla, en precisión simple, pasados los distintos valores calculados en la función simple.
Para que quede bien alineado, pasamos los enteros y flotantes a arrays y añadimos espacios en caso de ser necesario*/
static void    imprimir_linea_simple(int n, int i, float s1, float s2, float s3)
{
    char    *s, *aux;           //arrays utilizados para imprimir el número de sumantes i
    char    *sn1, *sn2, *sn3;   //arrays donde guardamos s1, s2 y s3 en formato array respectivamente
    int		len;                //variable auxiliar donde iremos guardando la longitud de las cadenas mientras añadimos espacios

    //guardamos i en formato char puntero en s
    s = malloc(sizeof(char) * int_len(i) + 1);
    if (!s)
        return;
    sprintf(s, "%i", i);
    //guardamos n en formato char puntero en aux (es el número más grande que vamos a tener que imprimir en la primera columna)
    aux = malloc(sizeof(char) * int_len(n) + 1);
    if (!aux)
        return;
    sprintf(aux, "%i", n);
    //añadimos en s los espacios que sean necesarios
    len = strlen(s);        //vamos a ir modificando la longitud de s en el bucle, necesitamos mantener el valor original
    for (long unsigned int j = 0; j < strlen(aux) - len; j++)
        s = strcat(s, " ");
    free(aux);
    //guardamos s1 en sn1 en formato char puntero
    //la impresión en el formato %.8G no necesita más de 15 caracteres
    sn1 = malloc(sizeof(char) * 15);
    if (!sn1)
        return;
    sprintf(sn1, "%.8G", s1);
    //añadimos los espacios necesarios
    len = strlen(sn1);
    for (int j = 0; j < 15 - len; j++)
	    sn1 = strcat(sn1, " ");
    //guardamos s2 en sn2 en formato char puntero
    sn2 = malloc(sizeof(char) * 15);
    if (!sn2)
        return;
    sprintf(sn2, "%.8G", s2);
    //añadimos los espacios necesarios
    len = strlen(sn2);
    for (int j = 0; j < 15 - len; j++)
	    sn2 = strcat(sn2, " ");
    //guardamos s3 en sn3 en formato char puntero
    sn3 = malloc(sizeof(char) * 15);
    if (!sn3)
        return;
    sprintf(sn3, "%.8G", s3);
    //añadimos los espacios necesarios
    len = strlen(sn3);
    for (int j = 0; j < 15 - len; j++)
        sn3 = strcat(sn3, " ");
    //Imprimimos la línea
    fprintf(stdout, "| %s | %s | %s | %s |\n", s, sn1, sn2, sn3);
    separador(n, 58);
    //liberamos el espacio reservado para los arrays
    free(sn1);
    free(sn2);
    free(sn3);
}

/*función que calcula, en precisión simple, las sumas parciales de la serie mediante los tres algoritmos distintos.
Lo hace de bloque en bloque los tres a la vez para poder ir imprimiendo la tabla.*/
static void    simple(int n, int bloque, float suma, int opcion)
{
    float   s1 = 0, s2, s3;     //variables donde guardamos las sumas parciales de los algoritmos 1, 2 y 3 respectivamente.
    float   a1 = 1, a2, a3;     //variables auxiliares utilizadas para calcular los distintos términos a sumar.

    for (int i = bloque; i <= n; i += bloque)   //Cada iteraación del bucle es una suma parcial
    {
        //Calculamos la suma mediante el algoritmo 1 (íncice creciente).
        //Podemos reutilizar s1, porque una suma parcial es la anterior más algunos términos
        for (int k = i - bloque; k < i; k++)
        {
            s1 += 1/(a1*a1);
            a1++;
        }
        //Calculamos la suma mediante el algoritmo 2 (índice decreciente)
        //No podemos reutilizar s2, porque el término inicial es distinto en cada caso
        a2 = i;
        s2 = 0;
        for (int k = i; k > 0; k--)
        {
            s2 += 1/(a2*a2);
            a2--;
        }
        //Calculamos la suma mediante el algoritmo 3 (expresión alternativa, índice decreciente)
        //No podemos reutilizar s2, porque el término inicial es distinto en cada caso
        a3 = i;
        s3 = 0;
        for (int k = i; k > 0; k--)
        {
            if (k % 2 == 0)
                s3 += 1/(a3*a3);
            else
                s3 -= 1/(a3*a3);
            a3--;
        }
        //Imprimimos una línea de la tabla
        if (opcion == 0)
            imprimir_linea_simple(n, i, s1, s2, -2 * s3);           //con los valores de las aproximaciones
        else
            imprimir_linea_simple(n, i, suma - s1, suma - s2, suma + 2*s3);     //con los errores absolutos
    }
}

int main()
{
    int nf = 7000;          //número de sumantes de la suma parcial a retornar para precisión simple
    int bloquef = 500;      //cantidad de sumantes que se incrementa en cada suma parcial respecto la anterior para precisión simple
    int nd = 50000;         //número de sumantes de la suma parcial a retornar para precisión doble
    int bloqued = 5000;     //cantidad de sumantes que se incrementa en cada suma parcial respecto la anterior para precisión doble
    int opcion = 0;         //auxiliar, sea 0 si se quiere la tabla de las aproximaciones, 1 si se quieren los errores absolutos
    double suma = 1.644934066848226;        //valor considerado el exacto

    //imprimimos la tabla en simple precisión
    if (opcion == 0)        //aproximaciones
        fprintf(stdout, "Tabla que muestra los valores de las sumas parciales en precision simple:\n");
    else        //errores absolutos
        fprintf(stdout, "Tabla que muestra los errores absolutos de las sumas parciales en precision simple:\n");
    fprintf(stdout, "\n  N       Alg 1            Alg 2            Alg 3\n");       //cabecera
    separador(nf, 58);      //línea horizontal
    simple(nf, bloquef, (float)suma, opcion);       //valores
    //imprimimos la tabla en doble precisión
    if (opcion == 0)        //aproximaciones
        fprintf(stdout, "\n\nTabla que muestra los valores de las sumas parciales en precision doble:\n");
    else        //errores absolutos
        fprintf(stdout, "\n\nTabla que muestra los errores absolutos de las sumas parciales en precision doble:\n");
    fprintf(stdout, "\n  N        Alg 1                     Alg 2                     Alg 3\n");       //cabecera
    separador(nd, 82);      //línea horizontal
    doble(nd, bloqued, suma, opcion);       //valores

    return 0;
}
