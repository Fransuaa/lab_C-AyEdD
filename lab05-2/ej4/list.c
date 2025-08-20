#include "list.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


typedef struct Node{
	elem data;
	struct Node* next;
} Node;

struct _list{
	struct Node* first;
	size_t size;
};


// Constructors
list empty(){
	list res=malloc(sizeof(struct _list));
	if (res!=NULL){
		res->first=NULL;          
		res->size=0;  
	}

	return res;
}

list addl(elem e, list l){
	Node *aux=NULL;
	aux=malloc(sizeof(Node));
	
	aux->data=e;
	aux->next=l->first;
	l->first=aux;
	l->size+=1;
	aux=NULL;

	return l;
}

// Operations
bool is_empty(list l){
	assert(l!=NULL);

	return (l->first==NULL && l->size==0);
}

elem head(list l){
	assert(l!=NULL);
	assert(!is_empty(l));

	return (l->first->data);
}

list tail(list l){
	assert(l!=NULL);
	assert(!is_empty(l));

	Node *aux;
	aux=(l->first)->next;
	free(l->first);
	l->first=aux;
	l->size-=1;
	aux=NULL;

	return l;
}

list addr(list l, elem e){
	assert(l!=NULL);

	Node *p;
	Node *q;
	q = malloc(sizeof(Node));
	q->data=e;
	q->next=NULL;
	p=l->first;	
	if (!is_empty(l)){
		while ((p->next)!=NULL){
			p=p->next;
		}
		p->next=q; 
	}
	else{
		l->first=q;
	}
	l->size+=1;
	p=NULL;
	q=NULL; 

	return l;
}

size_t length(list l){
	assert(l!=NULL);
	return l->size;
}

list concat(list l, list l0){
	assert(l!=NULL && l0!=NULL);
	
	Node *p=NULL;
	p=l->first;
	if (!is_empty(l)){
		while (p->next!=NULL){
			p=p->next;
		}
		p->next=l0->first;
	} else{
		l->first=l0->first;
	}
	p=NULL;
	l->size+=l0->size; 
	
	return l;
}

elem index(list l, int n){
	assert(l!=NULL);
	assert(n>=0);	
	assert(length(l)>n);

	elem elem_n;
	unsigned int i=0;
	Node *p=NULL;
	p=l->first;
	while (i!=n){
		p=p->next;
		++i;
	}	
	elem_n=p->data;
	p=NULL;

	return elem_n;
}

list take(list l, int n){
	assert(l!=NULL);
	assert(n>=0);	

	unsigned int i=1;
	Node *p=NULL;
	p=l->first;
	while (i<n && p->next!=NULL){
		p=p->next;
		++i;
	}
	list k;
	k->first=p->next;
	destroy_list(k);	  //elimino los elementos restantes

	p=NULL;
	l->size =  n<l->size ? n : l->size; 

	return l;
}

list drop(list l, int n){
	assert(l!=NULL);
	assert(n>=0);
	assert(length(l)>n);

	unsigned int i=0;
	Node *p;
	list k=empty();	
	p=l->first;
	k->first=l->first;
	while (i<n && p->next!=NULL){
		p=p->next;
		++i;
	}

	l->first=p->next;
	p->next=NULL;
	destroy_list(k);
	l->size-=n;

	return l;	
}

list copy_list(list l){
	assert(l!=NULL);

	return l;	
}

void destroy_list(list l){
	assert(l!=NULL);

	Node *p, *k;
	p=l->first;
	while (p!=NULL){
		k=p;
		p=p->next;
		free(k);		
	}
	free(l);
	l=NULL;
}
