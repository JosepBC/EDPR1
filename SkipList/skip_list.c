#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "skip_list.h"

int Crear(skip_list *sl) {
	sl->topLeft = (Node_t*)malloc(sizeof(Node_t));
	sl->topLeft->bottom = NULL;
	sl->topLeft->top = NULL;
	sl->topLeft->left = NULL;
	sl->topLeft->right = NULL;
	sl->topLeft->elem = 0;

	sl->elemNumber = 1;
	sl->height = 1;
	return SUCCESS;
}

void freeCol(Node_t *n) {
	while (n->top != NULL) {
		n = n->top;
		free(n->bottom);
	}
	free(n);
}

int Destruir(skip_list *sl) {
	if (sl == NULL) return LLISTA_NO_CREADA;
	if (sl->elemNumber == 0) return LLISTA_BUIDA;

	if (sl->elemNumber == 1) {
		free(sl->topLeft);
		return SUCCESS;
	}

	Node_t *next = sl->topLeft, *act = sl->topLeft;
	while (act->bottom != NULL) act = act->bottom;

	while (next != NULL) {
		next = act->right;
		freeCol(act);
		act = next;
	}

	return SUCCESS;
}

//With this function I get in insPos the node that goes at the left side of the new node and it's in the last layer
Node_t* insertPos(skip_list *sl, int elem) {
	Node_t *insPos;
	insPos = sl->topLeft;
	while (insPos->bottom != NULL) { //Move down
		insPos = insPos->bottom;
		while (insPos->right != NULL && elem > insPos->right->elem) insPos = insPos->right; //Move right
	}

	return insPos;
}

//Inserts newNode after prev
void insertAfter(skip_list *sl, Node_t *newNode, Node_t *prev) {
	//Right and left pointers
	Node_t *prevRight = prev->right;
	Node_t *prevLeft = prev->left;
	if (prevRight != NULL) prevRight->left = newNode;
	newNode->left = prev;
	prev->right = newNode;
	newNode->right = prevRight;
	newNode->top = NULL;
	newNode->bottom = NULL;

	Node_t* prevBot = prev->bottom, *prevElem = prev->bottom;
	if (prevBot != NULL) {
		while (prevElem != NULL) {
			if (prevElem->elem == newNode->elem) break;
			prevElem = prevElem->right;
		}
	}


	//bottom pointer, top MUST be NULL as I am inserting the highest element in the tower
	if (prevBot != NULL && prevBot->right != NULL && prevElem->elem == newNode->elem && prevElem->top == NULL) {
		prevElem->top = newNode;
		newNode->bottom = prevElem;
	}

	sl->elemNumber++;
}

//Creates a new layer under sl->topLeft
int newLayer(skip_list *sl) {
	Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
	if (newNode == NULL) return MEMORIA_INSUFICIENT;

	sl->height++;
	sl->elemNumber++;
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->top = sl->topLeft;
	newNode->bottom = sl->topLeft->bottom;
	newNode->elem = 0;
	if (newNode->bottom != NULL)  newNode->bottom->top = newNode;
	sl->topLeft->bottom = newNode;
	return SUCCESS;
}

int Inserir(skip_list *sl, int elem) {
	if (sl == NULL) return LLISTA_NO_CREADA;
	Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
	if (newNode == NULL) return MEMORIA_INSUFICIENT;
	
	srand(time(NULL));

	newNode->elem = elem;
	newNode->top = NULL;
	newNode->right = NULL;
	newNode->left = NULL;
	newNode->bottom = NULL;

	Node_t *prev = NULL;
	if (sl->elemNumber == 1) {
		newLayer(sl);
		prev = sl->topLeft->bottom;
	}
	else {
		prev = insertPos(sl, elem);
	}

	insertAfter(sl, newNode, prev);
	
	int h = 1;
	while (rand() & 1) {
		h++;
		if (h >= sl->height) {
			newLayer(sl);
		}

		while (prev->top == NULL) {
			prev = prev->left;
		}

		prev = prev->top;
		newNode = (Node_t *)malloc(sizeof(Node_t));
		if (newNode == NULL) return MEMORIA_INSUFICIENT;

		newNode->elem = elem;
		newNode->top = NULL;
		newNode->right = NULL;
		newNode->left = NULL;
		newNode->bottom = NULL;
		insertAfter(sl, newNode, prev);
	}
	
	return SUCCESS;
}

//Deletes the elem passed by parameter, this elem MUST be the highest elem in it's tower
int deleteElem(Node_t *n) {
	if (n->top != NULL) return OPERACIO_NO_PERMITIDA;

	Node_t *nPrev = n->left, *nPost = n->right, *nBot = n->bottom;

	nPrev->right = nPost;
	if (nPost != NULL) nPost->left = nPrev;
	if (nBot != NULL) nBot->top = NULL;
	free(n);
	return SUCCESS;
}

void deleteLayer(Node_t *n) {
	Node_t *nPrev = n->top, *nPost = n->bottom;
	nPrev->bottom = nPost;
	if (nPost != NULL) nPost->top = nPrev;
	free(n);
}

void deleteLayers(skip_list *sl) {
	Node_t *act = sl->topLeft->bottom, *next;
	while (act->right == NULL) {
		next = act->bottom;
		deleteLayer(act);
		act = next;
		sl->height--;
		sl->elemNumber--;
	}
}

int Esborrar(skip_list *sl, int elem) {
	if (sl == NULL) return LLISTA_NO_CREADA;
	if (sl->elemNumber == 0) return LLISTA_BUIDA;

	Node_t *leftElem = sl->topLeft;
	Node_t *act = leftElem;
	Node_t *next = leftElem;
	 
	leftElem = insertPos(sl, elem);
	act = leftElem->right;
	while (act->top != NULL) {
		act = act->top;
	}

	while (next != NULL) {
		next = act->bottom;
		deleteElem(act);
		act = next;
		sl->elemNumber--;
	}

	//Delete unused layers
	deleteLayers(sl);

	return SUCCESS;
}

int Longitud(skip_list sl, int *lon) {
	if (&sl == NULL) return LLISTA_NO_CREADA;

	*lon = sl.elemNumber;
	return SUCCESS;
}


int Buscar(skip_list sl, int elem, bool* trobat) {
	if (&sl == NULL) return LLISTA_NO_CREADA;
	if (sl.elemNumber == 0) return LLISTA_BUIDA;

	*trobat = false;

	Node_t* it = sl.topLeft;
	while (it->bottom != NULL) { //Move down
		it = it->bottom;
		while (elem > it->elem && it->right != NULL) it = it->right; //Move right
		if (elem == it->elem) {
			*trobat = true;
			return SUCCESS;
		}
	}
	return SUCCESS;
}

int Cost_Buscar(skip_list sl, int elem, int *cost) {
	*cost = 0;
	if (&sl == NULL) return LLISTA_NO_CREADA;
	if (sl.elemNumber == 0) return LLISTA_BUIDA;

	Node_t* it = sl.topLeft;
	while (it->bottom != NULL) { //Move down
		it = it->bottom;
		(*cost)++;

		while (elem > it->elem && it->right != NULL) {
			it = it->right; //Move right
			(*cost)++;
		}
		if (elem == it->elem) return SUCCESS;
	}

	return SUCCESS;
}

void Imprimir_Llista(skip_list sl) {
	Node_t *it = sl.topLeft, *line = sl.topLeft->bottom;
	printf("Height: %i\n", sl.height);
	printf("Elems: %i\n", sl.elemNumber);

	printf("%i\n", it->elem);
	while (it->bottom != NULL) {
		it = it->bottom;
		printf("%i ", it->elem);
		line = it;
		while (line->right != NULL) {
			line = line->right;
			printf("%i ", line->elem);
		}
		printf("\n");
	}
	printf("\n");
}