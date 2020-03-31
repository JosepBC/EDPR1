#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pila.h"
#include "math.h"

Pila Crear(int size) {
	Pila newStack;
	newStack.size = size;
	newStack.actIdx = -1;
	newStack.stack = (int*)malloc(size * sizeof(int));
	return newStack;
}

int Cim(Pila p) {
	if (&p == NULL || p.actIdx == -1) {
		printf("******No hi ha cim ja que la pila es buida!******\n");
		Destruir(&p);
		exit(EXIT_FAILURE);
	}

	return p.stack[p.actIdx];
}

void Apilar(Pila* ap, int elem) {
	if (ap->actIdx + 1 >= ap->size || ap == NULL) {
		printf("******La pila es plena o no existeix, l'ultima operacio d'apilar no ha tingut efecte!******\n");
		Destruir(ap);
		exit(EXIT_FAILURE);
	}
	ap->actIdx++;
	ap->stack[ap->actIdx] = elem;
}

void Desapilar(Pila* ap) {
	if (ap->actIdx == -1 || ap == NULL) {
		printf("******La pila es buida o no existeix, l'ultima operacio de desapilar no ha tingut efecte!******\n");
		Destruir(ap);
		exit(EXIT_FAILURE);
	}

	ap->stack[ap->actIdx] = 0;
	ap->actIdx--;
}

bool EsBuida(Pila p) {
	if (&p == NULL) {
		printf("******La pila no existeix!******\n");
		Destruir(&p);
		exit(EXIT_FAILURE);
	}

	return p.actIdx == -1;
}

bool EsPlena(Pila p) {
	if (&p == NULL) {
		printf("******La pila no existeix!******\n");
		Destruir(&p);
		exit(EXIT_FAILURE);
	}

	return p.actIdx + 1 == p.size;
}

void Destruir(Pila* ap) {
	if (ap == NULL) {
		printf("******La pila no existeix!******\n");
		Destruir(ap);
		exit(EXIT_FAILURE);
	}

	free(ap->stack);
}

void ImprimirPila(Pila ap) {
	if (&ap == NULL) {
		printf("******La pila no existeix!******\n");
		Destruir(ap);
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i <= ap.actIdx; i++) {
		printf("Idx: %i, Elem: %i\n", i, ap.stack[i]);
	}
	printf("\n");
}

bool Duplicar(Pila* ap) {
	if (ap == NULL || ap->actIdx == -1) return false;
	Apilar(ap, Cim(*ap));
	return true;
}

bool Permutar(Pila* ap) {
	if (ap == NULL || ap->actIdx < 1) return false;
	int a = Cim(*ap);
	Desapilar(ap);

	int b = Cim(*ap);
	Desapilar(ap);

	Apilar(ap, a);
	Apilar(ap, b);

}

bool CicleTres(Pila* ap) {
	if (ap == NULL || ap->actIdx < 2) return false;
	int a = Cim(*ap);
	Desapilar(ap);

	int b = Cim(*ap);
	Desapilar(ap);

	int c = Cim(*ap);
	Desapilar(ap);

	Apilar(ap, a);
	Apilar(ap, b);
	Apilar(ap, c);
}

bool ApilarElemNVegades(Pila* ap, int n, int newval) {
	if (ap == NULL) return false;
	for(int i = 0; i < n; i++)
		Apilar(ap, newval);
	return true;
}
