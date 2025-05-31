#include <stdio.h>

void swap (int *a, int *b){
	int aux;
	aux=*a;

	*a=*b;
	*b=aux;
}	

int main (){
	int x,y;
	x=6, x=4;

	printf("x=%d, y=%d\n", x,y);
	swap(&x,&y);
	printf("'swapeo' \n");
	printf("x=%d, y=%d", x,y);

	return 0;
}