#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node {
	list_elem data;
	struct Node* next;
} Node;


//constructores
list empty(){
	return NULL;
}

list addl(list l, list_elem e){
	Node* p = malloc(sizeof(Node));
	p->data = e;
	p->next = l;
	l=p;
	p=NULL;

	return l;   
}

//destructor
void destroy(list l){
	free(l);
	l=NULL;
}


//operaciones
bool is_empty(list l){
	return l==empty();
}

list_elem head(list l){
	assert(!is_empty(l));

	return l->data;
}

list tail(list l){
	assert(!is_empty(l));
	l=l->next;

	return l;
}


list addr(list l, list_elem e){
	Node *p;
	Node *q;

	q = malloc(sizeof(Node));
	q->data=e;
	q->next=NULL;
	
	if (!is_empty(l)){
		p=l;
		while (p->next!=NULL){
			p=p->next;
		}
		p->next=q;
	}
	else{
		l=q;
	}
	p=NULL;
	q=NULL; 

	return l;
}


unsigned int length(list l){
	unsigned int i=0;
	Node *p=NULL;
	p=l;
	while (p!=NULL){
		p=p->next;
		i++;
	}
	free(p);

	return i;
}

list concat(list l0, list l1){
	Node *p=NULL;
	p=l0;

	if (!is_empty(l0)){
		while (p->next!=NULL){
			p=p->next;
		}
		p->next=l1;
	} else{
		l0=l1;
	}
	p=NULL; 
	
	return l0;
}


list_elem index(list l, unsigned int n){
	assert(!is_empty(l));
	assert(length(l)>n);

	list_elem elem_n;
	unsigned int i=0;
	Node *p=NULL;
	p=l;
	while (i!=n){
		p=p->next;
		++i;
	}	
	elem_n=p->data;
	p=NULL;

	return elem_n;
}

list take(list l, unsigned int n){
	assert(length(l)>n);

	unsigned int i=0;
	Node *p=NULL;
	p=l;
	while (i!=n){
		p=p->next;
		++i;
	}
	free(p->next);
	p->next=NULL;
	p=NULL;

	return l;
}

list drop(list l, unsigned int n){
	assert(length(l)>n);

	unsigned int i=0;
	Node *p, *q;
	q=l;
	p=l;
	while (i!=n){
		p=p->next;
		++i;
	}
	l=p->next;
	free(q);

	return l;
}

list copy_list(list l){
	return l;
}
