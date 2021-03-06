
#include"/Users/amuthanmannan/Documents/collection/Collection-API-in-C copy/collection.h"

Set *set(int (*comp)(void* op1,void* op2)){
	Set* s;
	s=(Set*)malloc(sizeof(Set));
	s->list=linkedlist();
	s->comparator=llist_comparator(comp);
    return s;
}

int set_iscontains(Set* s, void* data){
   	LinkedList* l;
   	l=s->list;
   	Node* n;
   	n=l->head;
   	while(n!=NULL){
   		if(s->comparator->compareTo(n->data,data)==0){
   			return 1;
   		}
   		n=(Node*)n->next;
   	}
   	return 0;
}

int set_add(Set* s,void* data){

	if(set_iscontains(s,data)==0){
		llist_add(s->list,data);
		return 1;
	}

	return 0;
}

void set_addset(Set* s,Set* o){
	LinkedList* l=o->list;
	Node* n=l->head;
	while(n!=NULL){
		set_add(s,n->data);
		n=(Node*)n->next;
	}
}

int set_issubset(Set* s,Set* o){
	LinkedList* l=o->list;
	Node* n=l->head;
	while(n!=NULL){
	    if(set_iscontains(s,n->data)==0){
	       return 0;
	    }
		n=(Node*)n->next;
	}
    return 1;
}
