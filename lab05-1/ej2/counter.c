#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};


// CONSTRUCTORS
counter counter_init(void) {
    counter c;

    c=malloc(sizeof(struct _counter));
    c->count=0u;

    return c;   
}

void counter_inc(counter c) {
    c->count++;
}


// OPERATIONS
bool counter_is_init(counter c) {
    return (c->count == counter_init()->count); 
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count--;
}

counter counter_copy(counter c) {
    counter copy;
    copy=malloc(sizeof(struct _counter));
    copy->count=c->count;

    return copy;
}

void counter_destroy(counter c) {
    free(c);
    c=NULL;    //PREGUNTAR
}