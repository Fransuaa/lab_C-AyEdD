#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    unsigned int i,j,ppiv;

    ppiv=izq;
    i=izq+1;
    j=der;

    while (i<=j){
        if (goes_before(a[i],a[ppiv])){                 //a[i]<=a[ppiv]
            i++;
        }   
        else if (goes_before(a[ppiv],a[j])){            //a[j]>=a[ppiv] 
            j--;
        }
        else if (!(goes_before(a[i],a[ppiv])) && !(goes_before(a[ppiv],a[j])) ){         //a[i]>a[ppiv] && a[ppiv]>a[j]
            swap(a,i,j);
        }
    }

    swap(a,ppiv,j);       // acomodo mi pivot a la posicion definitiva
    ppiv=j;               // .....

    return ppiv;

    /*
     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der, unsigned int length) {
   unsigned int ppiv;

   if (izq<der){

    printf("\n");
    array_dump(a, length);
    printf("izq=%d, der=%d \n\n", izq, der);

    ppiv=partition(a,izq,der);

    array_dump(a, length);
    printf("izq=%d, der=%d \n", izq, der);

    printf("ppiv=%d\n", ppiv);

    if (ppiv != 0){
        quick_sort_rec(a, izq, ppiv-1, length);     // ejecuto quick sort en el segmento a la izquierda del pivot
    }

    quick_sort_rec(a, ppiv+1, der, length);     // ejecuto quick sort en el segmento a la derecha del pivot
   }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1, length);
}

