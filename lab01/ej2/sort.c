#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {

   unsigned int ppiv;

   if (izq<der){

      ppiv=partition(a,izq,der);

      if (ppiv != 0){
         quick_sort_rec(a, izq, ppiv-1);     // ejecuto quick sort en el segmento a la izquierda del pivot
      }

      quick_sort_rec(a, ppiv+1, der);     // ejecuto quick sort en el segmento a la derecha del pivot

   }
    /* no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
    */
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);   // quick_sort_rec(arreglo,primer posicion,ultima posicion), 
                                                            // si el arreglo es vacio le pasa (a,0,0), 
}                                                           // si no, le pasa (a,0,length-1), ya que indexa desde 0.

