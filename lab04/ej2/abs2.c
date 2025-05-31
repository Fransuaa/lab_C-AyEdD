#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x>=0){
        *y=x;
    }
    else{
        *y=-x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    a=-10;
    absolute(a, &res);

    printf("%d\n", res);
    

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

/* En esta instancia si se muestra por pantalla el valor correcto, puesto 
    que al trabajar con referencias a valores si se logra modificar la variable 
    'res' dentro de la funcion */

/*
   c) 
    ● ¿El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out?
        - tipo out
    
    ● ¿Qué tipo de parámetros tiene disponibles C para sus funciones?
        - solo parametros de tipo int
*/