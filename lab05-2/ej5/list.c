#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};



// Constructors
/**
 * @brief Creates a new empty list.
 */
list empty(){
    list res=calloc(2, sizeof(struct _list));
    return res;    
}

/**
 * @brief Adds element `e` to the left of list `l`.
 */
list addl(elem e, list l){
    assert(l!=NULL);    
    assert(l->size<MAX_LENGTH);

    for (int i=l->size; i>0; --i){
        l->elems[i]=l->elems[i-1];
    }
    l->elems[0]=e;
    ++l->size;

    return l;
}



// Operations
/**
 * @brief Returns whether the list `l` is empty.
 */
bool is_empty(list l){
    assert(l!=NULL);
    return l->size==0;
}

/**
 * @brief Returns first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
elem head(list l){
    assert(l!=NULL);
    assert(!is_empty(l));

    return l->elems[0];
}

/**
 * @brief Removes in-place the first element of list `l`.
 *
 * PRECONDITION: !is_empty(l)
 */
list tail(list l){
    assert(l!=NULL);
    assert(!is_empty(l));

    for (int i=0; i<l->size; ++i){
        l->elems[i]=l->elems[i+1];
    }
    --l->size;

    return l;
}

/**
 * @brief  Adds in-place element `e` to the right of list `l`.
 */
list addr(list l, elem e){
    assert(l!=NULL);    
    assert(l->size<MAX_LENGTH);

    l->elems[l->size]=e;
    ++l->size;

    return l;
}

/**
 * @brief Return the amount of elements of list `l`.
 */
int length(list l){
    assert(l!=NULL);    

    return l->size;        
}

/**
 * @brief Adds to the end of `l` all elements of `l0`.
 */
list concat(list l, list l0){
    assert(l!=NULL && l0!=NULL);
    assert(l->size+l0->size < MAX_LENGTH);

    int newsize=l->size+l0->size;
    int i;
    int j;

    i=l->size;
    j=0;

    while (i<newsize){
        l->elems[i]=l0->elems[j];   
        ++i; ++j; 
    }
    l->size=newsize;

    return l;
}

/**
 * @brief Return the `n`-th element of `l`.
 *
 * PRECONDITION: n < length(l)
 */
elem index(list l, int n){
    assert(l!=NULL);
    assert(n>=0);
    assert(n < length(l));

    return l->elems[n];
}

/**
 * @brief Takes the first `n` elements of `l` in-place, removing the rest.
 */
list take(list l, int n){
    assert(l!=NULL);
    assert(n>=0);

    if (n<=length(l)){
        l->size=n;
    }

    return l;
}


/**
 * @brief Removes the first `n` elements of `l` in-place.
 */

list drop(list l, int n){
    assert(l!=NULL);
    assert(n>=0);

    int i=0;
    int j=n;

    while (i<=n){
        l->elems[i]=l->elems[j];
        ++i; ++j;        
    }

    if (n>=length(l)){
        l->size=0;
    }
    else{
        l->size-=n;
    }

    return l;    
}


/**
 * @brief  Makes a copy of list `l`. Allocates new memory.
 */
list copy_list(list l){
    assert(l!=NULL);
    
    list lcopy=empty();
    for (int i=0; i<l->size; ++i){
        lcopy->elems[i]=l->elems[i];
    }
    lcopy->size=l->size;

    return lcopy;
}

/**
 * @brief Frees memory for `l`.
 */
void destroy_list(list l){
    free(l);
    l=NULL;
}


/*
int main(){
    list l= empty();
    list laux= empty();

    bool b;
    elem e;

    b=is_empty(l);

    l=addr(l,1);
    l=addr(l,2);
    l=addr(l,3);

    l=drop(l, 1);

    laux=addr(laux,4);
    laux=addr(laux,5);
    laux=addr(laux,6);

    laux=drop(laux, 3);

    laux=addr(laux,4);
    laux=addr(laux,5);
    laux=addr(laux,6);
    laux=addr(laux,7);
    laux=addr(laux,8);
    laux=addr(laux,9);

    laux=drop(laux,4);

    l=copy_list(laux);

    int fst= index(l, 0);
    int snd= index(l, 1);



    fst++;
    snd++;
    b=is_empty(l);
    e=head(l);
    l=tail(l);

    b=b&&false;
    e+=7;


    return 0;  
}
*/