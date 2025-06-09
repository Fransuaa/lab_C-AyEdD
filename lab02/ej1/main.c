#include <stdio.h>
#include <stdlib.h>
#include "k_esimo.h"

int main(void) {
    int a[] = {8,-2,9,0,13};
    int length = 5;
    int k = 2;
    int result;

    result = k_esimo(a, length, k);
    printf("Resultado: %i\n", result);

    return EXIT_SUCCESS;
}