#include "pair.h"
#include <stdlib.h>
#include <assert.h>


struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
	pair_t pnew=NULL;
	pnew=malloc(sizeof(struct s_pair_t));

	if (pnew!=NULL){
		pnew->fst=x;
		pnew->snd=y;
	}

	return pnew;
}

elem pair_first(pair_t p){
	assert(p!=NULL);
	return p->fst;
}

elem pair_second(pair_t p){
	assert(p!=NULL);
	return p->snd;
}

pair_t pair_swapped(pair_t p){
	assert(p!=NULL);
	pair_t pswap=NULL;
	pswap=pair_new(p->snd, p->fst);

	return pswap;
}

pair_t pair_destroy(pair_t p){
	free(p);
	return NULL;
}

