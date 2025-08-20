#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};


//
// Constructors
//

/**
 * @brief Creates a new empty list.
 */
list empty();

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l){
    assert(l!=NULL);
    assert(l->size < MAX_LENGTH);
}


//
// Operations
//

/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l){
    assert(l!=NULL);
    return l->size == 0;
}

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l){
    assert(l!=NULL);
    assert(!is_empty(l));

    return l->a[l->start];    
}

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l){

}

/**
 * @brief  Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e);

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l);

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0);

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n);

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n);

/**
 * @brief Removes the first `n` elements of `l` in-place.
 */
list drop(list l, int n);



/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l);






/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l);
