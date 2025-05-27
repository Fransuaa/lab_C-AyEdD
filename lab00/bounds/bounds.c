#include <stdio.h>
#include <stdbool.h>



struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};	


struct bound_data check_bound(int value, int arr[], unsigned int length){
	
	struct bound_data check;

	check.is_upperbound=true;	
	check.is_lowerbound=true;
	check.exists=false;
	check.where=0;

	for (unsigned int i=0; i<length; i++){

		check.is_upperbound = check.is_upperbound && value>=arr[i];
		check.is_lowerbound = check.is_lowerbound && value<=arr[i];

		if (arr[i]==value){
			check.exists=true; 
			check.where=i;
		}
	} 	

	return check; 
}


int main(){

	unsigned int len;
	printf("Ingrese la longitud del arreglo=");
	scanf("%u", &len);

	int a[len];
	int v;

	for (unsigned int i=0; i<len; i++){
		printf("Ingrese a[%d]=",i);
		scanf("%d", &a[i]);
	}

	printf("Ingrese un valor para verificar con 'check_bound'=");
	scanf("%d", &v);

	struct bound_data result = check_bound(v, a, len);


	if (result.is_upperbound){
		if (result.exists){
			printf("El valor '%d' ingresado por el usuario se encuentra en el arreglo en la posicion %d y es maximo", v, result.where);
		}
		else{
			printf("El valor '%d' ingresado por el usuario es cota superior del arreglo", v);
		}
	}

	else if (result.is_lowerbound){
		if (result.exists){
			printf("El valor '%d' ingresado por el usuario se encuentra en el arreglo en la posicion %d y es minimo", v, result.where);		
		}
		else{
			printf("El valor '%d' ingresado por el usuario es cota inferior del arreglo", v);			
		}
	}

	return 0;
}