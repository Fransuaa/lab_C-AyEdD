#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), sizeof(messi));


    printf("\nname-addres  : %p \n"
           "age-addres   : %p \n"
           "height-addres: %p \n"
           "data_t-addres: %p \n", (void *) &messi.name, (void *) &messi.age, (void *) &messi.height, (void *) &messi);
    

    // Ej. 3
    data_t *p=NULL;
    p = malloc(sizeof(data_t));

    strcpy(p->name, messi.name);
    p->age=messi.age;
    p->height=messi.height;

    printf("\n==== STRUCT EN HEAP ==== \n"
            "name-addres  : %p \n"
            "age-addres   : %p \n"
            "height-addres: %p \n"
            "data_t-addres: %p \n\n", (void *) &p->name, (void *) &p->age, (void *) &p->height, (void *) p);
    print_data(*p);

    free(p);
    p=NULL;

    return EXIT_SUCCESS;
}
