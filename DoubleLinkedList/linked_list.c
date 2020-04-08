#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

int Crear(llista_encadenada* ll) {
	if (ll == NULL) return MEMORIA_INSUFICIENT;
	ll->first = NULL;
	ll->last = NULL;
	ll->elems = 0;
	return SUCCESS;
}

int Destruir(llista_encadenada* ll) {
	//#1: Empty list 
	if (ll->elems == 0) return LLISTA_BUIDA;
	
	//#2: One element in the list
	if (ll->elems == 1) {
		free(ll->first);
		return SUCCESS;
	}

	//#3: If there is +1 element in the list, iterate over it and free the previous
	Node_t *it = ll->first->next;
	for (int i = 0; i < ll->elems - 1; i++) {
		free(it->previous);
		it = it->next;
	}

	free(it);
	free(ll->ghost);
	ll->elems = 0;
	return SUCCESS;
}

int Principi(llista_encadenada* ll) {
	if (ll == NULL) return LLISTA_NO_CREADA;
	ll->pdi = ll->ghost;
	return SUCCESS;
}

int Final(llista_encadenada* ll) {
	if (ll == NULL) return LLISTA_NO_CREADA;
	ll->pdi = ll->last;
	return SUCCESS;
}

int Avancar(llista_encadenada* ll) {
	if (ll == NULL) return LLISTA_NO_CREADA;
	if (ll->pdi->next == NULL) return OPERACIO_NO_PERMITIDA;

	ll->pdi = ll->pdi->next;
	return SUCCESS;
}

int Retrocedir(llista_encadenada* ll) {
	if (ll == NULL) return LLISTA_NO_CREADA;
	if (ll->pdi->previous == NULL) return OPERACIO_NO_PERMITIDA;

	ll->pdi = ll->pdi->previous;
	return SUCCESS;
}

int Es_Final(llista_encadenada ll, bool* esfinal) {
	if(&ll == NULL) return LLISTA_NO_CREADA;

	if (ll.pdi->next == NULL) *(esfinal) = true;
	else *esfinal = false;
	
	return SUCCESS;
}

int Actual(llista_encadenada ll, int* elem) {
	if (&ll == NULL) return LLISTA_NO_CREADA;
	if (ll.pdi == NULL) return ELEMENT_NO_CREAT;
	
	*elem = ll.pdi->elem;
	return SUCCESS;
}

int Inserir(llista_encadenada* ll, int elem) {
	Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
	if (newNode == NULL) return MEMORIA_INSUFICIENT;

	newNode->next = NULL;
	newNode->previous = NULL;
	newNode->elem = elem;

	//The new node goes after the node pointed by pdi, 3 cases
	if (ll->elems == 0) {
		//#1: Empty list, all the elems in the list are the newNode
		ll->first = newNode;
		ll->last = newNode;
		ll->pdi = newNode;

		ll->ghost = (Node_t*)malloc(sizeof(Node_t));
		if (ll->ghost == NULL) return MEMORIA_INSUFICIENT;

		ll->ghost->elem = 0;
		ll->ghost->previous = NULL;
		ll->ghost->next = ll->first;
		ll->first->previous = ll->ghost;
	}
	else if (ll->pdi == ll->last) {
		//#2: the pdi is the last element
		newNode->previous = ll->pdi;
		ll->pdi->next = newNode;
		ll->last = newNode;
	}
	else {
		//#3: Generic case
		if (ll->pdi == ll->ghost) ll->first = newNode;
		newNode->previous = ll->pdi;
		newNode->next = ll->pdi->next;
		ll->pdi->next->previous = newNode;
		ll->pdi->next = newNode;
		
	}

	ll->elems++;
	return SUCCESS;
}

int Esborrar(llista_encadenada* ll) {
	if (ll->elems == 0) return LLISTA_BUIDA;
	//Node_t *pdiCpy = ll->pdi; //Copy of the pdi to free it after all
	Node_t *pdiPrev = ll->pdi->previous; //Previous and next ptr, just to make it easy to read
	Node_t *pdiNext = ll->pdi->next;
	//The  pdi node has to be deleted, 5 cases
	if (ll->elems == 1) {
		//#1: 1 elem in the list
		free(ll->first);
	}
	else if (ll->pdi == ll->first) {
		//#2: the pdi is the first element
		ll->first = pdiNext;
		pdiNext->previous = NULL;
		free(ll->pdi);
		ll->pdi = pdiNext;
	}
	else if (ll->pdi == ll->last) {
		//#3: the pdi is the last element
		ll->last = pdiPrev;
		ll->last->next = NULL;
		free(ll->pdi);
		ll->pdi = ll->first; //The new PDI is the first element, design desicion
	}
	else if (ll->pdi == ll->ghost) {
		//#4: the pdi is the ghost
		return OPERACIO_NO_PERMITIDA;
	}
	else {
		//#5: Generic case
		pdiPrev->next = pdiNext;
		pdiNext->previous = pdiPrev;
		free(ll->pdi);
		ll->pdi = pdiNext;
	}

	ll->elems--;
	return SUCCESS;
}

int Longitud(llista_encadenada ll, int* lon) {
	(*lon) = ll.elems;
	return SUCCESS;
}

int Buscar(llista_encadenada ll, int elem, bool* trobat) {
	if (&ll == NULL) return LLISTA_NO_CREADA;
	Node_t* it = ll.first;
	//Iterate over the list
	for (int i = 0; i < ll.elems; i++) {
		if (it->elem == elem) {
			*(trobat) = true;
			return SUCCESS;
		}
		it = it->next;
	}

	*(trobat) = false;
	return SUCCESS;
}

int Cost_Buscar(llista_encadenada ll, int elem, int* cost) {
	if (&ll == NULL) return LLISTA_NO_CREADA;
	int i;
	Node_t* it = ll.first;
	//Iterate over the list
	for (i = 1; i < ll.elems; i++) {
		if (it->elem == elem) {
			*(cost) = i;
			return SUCCESS;
		}
		it = it->next;
	}

	*(cost) = i;
	return SUCCESS;
}

int Imprimir_Llista(llista_encadenada ll) {
	if (&ll == NULL) return LLISTA_NO_CREADA;
	printf("Numero d'elements: %i\n", ll.elems);
	if (ll.elems > 0) {
		printf("PDI: %i\n", ll.pdi->elem);
		printf("First: %i\n", ll.first->elem);
		printf("Last: %i\n", ll.last->elem);
	}
	if (ll.elems >= 1) {
		Node_t* it = ll.first;
		//Iterate over the list
		for (int i = 0; i < ll.elems; i++) {
			printf("Element numero: %i es: %i\n", i, it->elem);
			it = it->next;
		}
		printf("\nList backwards:\n");
		it = ll.last;
		for (int i = ll.elems - 1; i >= 0; i--) {
			printf("Element numero: %i es: %i\n", i, it->elem);
			it = it->previous;
		}
	}
	printf("\n");
	return SUCCESS;
}
