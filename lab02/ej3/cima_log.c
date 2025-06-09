#include <stdio.h>
#include <stdbool.h>
#include "cima_log.h"

/**
 * @brief Dado un arreglo que tiene cima, devuelve la posición de la cima
 * usando la estrategia divide y venceras.
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
int cima_log(int a[], int length) {
    int lft,rgt,mid;

    lft=0;
    rgt=length-1;
    mid=(lft+rgt)/2;
    
    while (lft!=rgt){

        if (a[mid-1]<a[mid] && a[mid]>a[mid+1]){

        }

        else if (a[mid]<a[mid+1]){
            lft=mid+1;
        }

        else if (a[mid]>a[mid+1]){
            rgt=mid-1;
        }
        mid=(lft+rgt)/2;
    }

    return mid;
}
