#include "pair.h"
#include <stdlib.h>

struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
	pair_t pnew=NULL;;
	pnew=malloc(sizeof(struct s_pair_t));
	pnew->fst=x;
	pnew->snd=y;

	return pnew;
}

int pair_first(pair_t p){
	return p->fst;
}

int pair_second(pair_t p){
	return p->snd;
}

pair_t pair_swapped(pair_t p){
	pair_t pswap=NULL;
	pswap=malloc(sizeof(struct s_pair_t));
	pswap->fst=p->snd;
	pswap->snd=p->fst;

	return pswap;
}

pair_t pair_destroy(pair_t p){
	free(p);
	p=NULL;
	return p;
}

