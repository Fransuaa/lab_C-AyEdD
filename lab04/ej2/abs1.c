#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x>=0){
        y=x;
    }
    else{
        y=-x;
    }
}

int main(void) {
    int a=-10, res=0;
        
    absolute(a, res);

    printf("%d\n", res);

    return EXIT_SUCCESS;
}


/* El valor mostrado por pantalla es el que tenga ´res´, no coincide con el 
    programa en el lenguaje del teorico/practico. La variable ´res´ no se modifica
    dentro de nuestra funcion */