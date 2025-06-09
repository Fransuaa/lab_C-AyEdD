#include <stdbool.h>
#include <stdio.h>
#include "cima.h"

#define MAX_LENGTH 10
#define N_TESTCASES_TIENE_CIMA 12
#define N_TESTCASES_CIMA 12

void test_tiene_cima(void);
void test_cima(void);

int main() {
    test_tiene_cima();
    test_cima();

    return 0;
}

void test_tiene_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        bool result;
    };

    struct testcase tests[N_TESTCASES_TIENE_CIMA] = {
      // ARREGLO | LONGITUD | RESULTADO ESPERADO  
      { {8}, 1, true },

      { {8,9,11,14,17}, 5, true },       // siempre creciente 
      { {8,7,3,0,-2}, 5, true },         // siempre decreciente
      { {1,2}, 2, true },                // 2 elementos creciente
      { {2,1}, 2, true },                // 2 elementos decreciente
      { {8,8,7,6,1}, 5, false },         // pico plano siempre decreciente
      { {2,3,4,4,1}, 5, false },         // pico plano
      { {2,2,2}, 3, false },             // todos iguales
      { {1,2,3,4,3,}, 5, true },         // cima 
      { {-122,-18,-30,-57}, 4, true },   // todos negativos
      { {0,0,0,0,0}, 5, false },         // todos 0
      { {1,1,1,2,1}, 5, false }           // todos iguales salvo cima

    };
    bool result;

    printf("\nTESTING tiene_cima\n");

    for (int i=0; i < N_TESTCASES_TIENE_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = tiene_cima(tests[i].a, tests[i].length);

        if (result != tests[i].result) {
            printf("FAILED\n");
        } else {
            printf("OK\n");
        }
    }
}

void test_cima(void) {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {

      // ARREGLO | LONGITUD | RESULTADO ESPERADO  
      { {8}, 1, 8 },

      { {8,9,11,14,17}, 5, 17 },        // siempre creciente 
      { {8,7,3,0,-2}, 5, 8 },           // siempre decreciente
      { {1,2}, 2, 2 },                  // 2 elementos creciente
      { {2,1}, 2, 2 },                  // 2 elementos decreciente
      { {8,8,7,6,1}, 5, -1 },           // pico plano siempre decreciente   | X
      { {2,3,4,4,1}, 5, -1 },           // pico plano                       | X                
      { {2,2,2}, 3, -1 },               // todos iguales                    | X
      { {1,2,3,4,3,}, 5, 4 },           // cima 
      { {-122,-18,-30,-57}, 4, -18 },   // todos negativos
      { {0,0,0,0,0}, 5, -1 },           // todos 0                          | X
      { {1,1,1,2,1}, 5, -1 }             // todos iguales salvo cima        | X 

      /* X: el arreglo no tiene cima */

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }
}
