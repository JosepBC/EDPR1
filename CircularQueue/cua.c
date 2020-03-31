#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cua.h"

int Crear(Cua* ac, int size) {
	ac->size = size;
	ac->queue = (int*)malloc(sizeof(int) * size);
	if (ac->queue == NULL)
		return ERROR_CREAR;
	ac->readIdx = 0;
	ac->storedElems = 0;
	return SUCCESS;
}


int Encuar(Cua* ac, int elem) {
	if (ac->queue == NULL)
		return CUA_NO_CREADA;
	if (ac->storedElems == ac->size)
		return CUA_PLENA;

	int insIdx = (ac->readIdx + ac->storedElems) % ac->size;
	ac->queue[insIdx] = elem;
	ac->storedElems++;

	return SUCCESS;
}

int Desencuar(Cua* ac) {
	if (ac->storedElems == 0)
		return CUA_BUIDA;
	else if (ac->queue == NULL)
		return CUA_NO_CREADA;

	ac->readIdx++;
	ac->readIdx %= ac->size;
	ac->storedElems--;

	return SUCCESS;
}

int Cap(Cua c, int* elem) {
	if (c.storedElems == 0)
		return CUA_BUIDA;
	else if (c.queue == NULL)
		return CUA_NO_CREADA;
	(*elem) = c.queue[c.readIdx];
	return SUCCESS;
}

int EsBuida(Cua c, bool* b) {
	*b = false;
	if (c.storedElems == 0) {
		*b = true;
		return SUCCESS;
	}
	else if (c.storedElems > 0)
		return SUCCESS;
	else if (c.queue == NULL)
		return CUA_NO_CREADA;
	
	return ERROR_INDETERMINAT;
}

int EsPlena(Cua c, bool* b) {
	*b = false;
	if (c.storedElems == c.size) {
		*b = true;
		return SUCCESS;
	}
	else if (c.queue == NULL)
		return CUA_NO_CREADA;

	return ERROR_INDETERMINAT;
}

int Destruir(Cua* ac) {
	if (ac->queue == NULL)
		return CUA_NO_CREADA;

	free(ac->queue);
	ac->queue = NULL;
	ac->readIdx = -1;
	ac->size = -1;
	ac->storedElems = -1;
	return SUCCESS;
}

void ImprimirCua(Cua c) {
	printf("--------------------\n");
	printf("Queue:\n");
	printf("\tNumber of stored elems: %i\n", c.storedElems);
	printf("\tRead idx: %i\n", c.readIdx);
	printf("\tSize: %i\n", c.size);
	for (int i = 0; i < c.size; i++) {
		printf("\tElem number %i is: %i\n", i, c.queue[i]);
	}
	printf("--------------------\n\n");

}
