#include "pair.h"

pair_t pair_new(int x, int y){
	pair_t pnew;
	
	pnew.values[0]=x;
	pnew.values[1]=y;

	return pnew;
}

int pair_first(pair_t p){
	return p.values[0];
}

int pair_second(pair_t p){
	return p.values[1];
}

pair_t pair_swapped(pair_t p){
	pair_t pswap;

	pswap.values[0]=p.values[1];
	pswap.values[1]=p.values[0];

	return pswap;
}

pair_t pair_destroy(pair_t p){
	return p;
}