#include <stdio.h>
#include <stdbool.h>
#include "cima.h"

/**
 * @brief Indica si el arreglo tiene cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
bool tiene_cima(int a[], int length) {
    bool b=true;
    int i=0;

    while (a[i]<a[i+1] && i!=length-1){
        i=i+1;    
    }
    while (a[i]>a[i+1] && i!=length-1){
        i=i+1;    
    }
    b=i==length-1;

    return b;
}

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima.
 *
 * Un arreglo tiene cima si existe una posición k tal que el arreglo es
 * estrictamente creciente hasta la posición k y estrictamente decreciente
 * desde la posición k.
 * La cima es el elemento que se encuentra en la posición k.
 * PRECONDICION: tiene_cima(a, length)
 *
 * @param a Arreglo.
 * @param length Largo del arreglo.
 */
int cima(int a[], int length) {
    int k=0;
    int i=0;

    while (a[i]<a[i+1] && i!=length-1){
        i=i+1;    
    }
    k=i;
    while (a[i]>a[i+1] && i!=length-1){
        i=i+1;    
    }

    return (i==length-1 ? a[k] : -1);
}
