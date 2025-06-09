#ifndef _LIST_H
#define _LIST_H
#include <stdbool.h>


typedef struct Node * list;
typedef int list_elem;


//constructores
list empty();
/* crea una lista vacia */

list addl(list l, list_elem e);
/* agrega el elemento e al comienzo de la lista l */

//destructor
void destroy(list l);
/* libera memoria en caso de ser necesario */


//operaciones
bool is_empty(list l);
/* devuelve True si la lista l es vacia */

list_elem head(list l);
/*	devuelve el primer elemento de lista l
	PRE: !is_empty(l)
*/

list tail(list l);
/*	elimina el primer elemento de lista l
	PRE: !is_empty(l)
*/

list addr(list l, list_elem e);
/* agrega el elemento e al final de la lista l */

unsigned int length(list l);
/* devuelve la cantidad de elementos de la lista l */

list concat(list l0, list l1);
/* devuelve la concatenacion de la lista l0 con l1 con el mismo orden de elementos */

list_elem index(list l, unsigned int n);
/*	devuelve el n-esimo elemento de la lista l 
	PRE: !is_empty(l) && length(l)>n
*/

list take(list l, unsigned int n);
/* devuelve la lista l solo con los primeros n elementos 
	PRE: length(l)>n
*/

list drop(list l, unsigned int n);
/* devuelve la lista l sin los primeros n elementos 
	PRE: length(l)>n
*/

list copy_list(list l);
/* devuelve la lista l */

#endif