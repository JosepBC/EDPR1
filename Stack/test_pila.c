#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "pila.h"
#define STACK_SIZE 10
/*
int main(int argc, char const* argv[]) {
	Pila test = Crear(STACK_SIZE);
	int cim;

	//Es buida la pila?
	if (EsBuida(test)) printf("La pila es buida!\n");
	else printf("La pila es plena!\n");

	//Apilant fins plenar la pila
	for (int i = 0; i <= STACK_SIZE - 1; i++) {
		Apilar(&test, i);
		cim = Cim(test);
		printf("El valor del cim de la pila es %i\n", cim);
	}

	cim = Cim(test);
	printf("L'ultim valor de la pila es %i\n", cim);

	//Apilant amb la pila plena
	Apilar(&test, 12);
	cim = Cim(test);
	printf("L'ultim valor de la pila es %i\n", cim);

	//Es plena la pila?
	if (EsPlena(test)) printf("La pila es plena\n");
	else printf("La pila no es plena.\n");

	//Desapilant tots els elements
	for (int i = 0; i <= STACK_SIZE - 1; i++) {
		Desapilar(&test);
		cim = Cim(test);
		printf("El valor del cim de la pila es %i\n", cim);
	}

	//Desapilant amb la pila buida
	Desapilar(&test);
	cim = Cim(test);
	printf("El valor del cim de la pila es %i\n", cim);

	//Destruint la pila...
	Destruir(&test);
	return 0;
}
*/