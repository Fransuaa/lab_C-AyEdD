#include <stdbool.h>
#include <stdio.h>
#include "cima_log.h"

#define MAX_LENGTH 10
#define N_TESTCASES_CIMA 7

int main() {
    struct testcase {
        int a[MAX_LENGTH];
        int length;
        int result;
    };

    struct testcase tests[N_TESTCASES_CIMA] = {
        { {8}, 1, 0 },

        { {8,9,10}, 3, 2 },
        { {1,2,3,2,1}, 5, 2 },
        { {10,20,10,9,8,7,6}, 6, 1 },
        { {10,20,25,27,28,29,6}, 7, 5 },
        { {10,20,25,26,27,28}, 6, 5 },
        { {10,20,25,9,8,7,6}, 6, 2 }

        // COMPLETAR!!

    };
    int result;

    printf("TESTING cima\n");

    for (int i=0; i < N_TESTCASES_CIMA; i++) {
        printf("Test case %i: ", i+1);

        result = cima_log(tests[i].a, tests[i].length);

        if (result == tests[i].result) {
            printf("OK\n");
        } else {
            printf("FAILED. got %d expected %d\n", result, tests[i].result);
        }
    }

    return 0;
}
