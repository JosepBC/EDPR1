#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cua.h"

/*
void treatReturn(char* str, int n) {
	switch (n) {
	case 0:
		printf("%s Operacio realitzada amb exit!\n\n", str);
		break;
	case 1:
		printf("%s Error al crear la cua!\n\n", str);
		break;
	case 2:
		printf("%s Error al destruir la cua!\n\n", str);
		break;
	case 3:
		printf("%s Cua no creada!\n\n", str);
		break;
	case 4:
		printf("%s Cua buida!\n\n", str);
		break;
	case 5:
		printf("%s Cua plena!\n\n", str);
		break;
	default:
		printf("%s Algo ha anat malament!\n\n", str);
		break;
	}
}

int main(int argc, char const* argv[]) {
	Cua test;
	int head = -1;
	int elem = -1;
	bool full = false, empty = false;
	
	//Creo cua de dim 2
	printf("*****************************************************\n");
	treatReturn("Crear: ", Crear(&test, 2));
	printf("-----------------------------------------------------\n");
	
	//Miro si la cua es buida
	printf("*****************************************************\n");
	treatReturn("Es buida", EsBuida(test, &empty));
	if (empty) printf("La cua es buida\n");
	else printf("La cua no es buida\n");
	printf("-----------------------------------------------------\n");
	
	//Encuo 3 elements i vaig concultant el cap
	printf("*****************************************************\n");
	for (int i = 1; i <= 3; i++) {
		treatReturn("Encuant element: ", Encuar(&test, i * 10));
		treatReturn("Obtenint el cap, resultat: ", Cap(test, &head));
		printf("El cap de la cua es: %i \n", head);
		ImprimirCua(test);
	}
	printf("-----------------------------------------------------\n");
	
	//Es buida la cua?
	printf("*****************************************************\n");
	treatReturn("Es buida: ", EsBuida(test, &empty));
	if (empty) printf("La cua es buida!\n");
	else printf("La cua no es buida!\n");
	printf("-----------------------------------------------------\n");
	
	//Es plena la cua?
	printf("*****************************************************\n");
	treatReturn("Es plena: ", EsPlena(test, &full));
	if (full) printf("Cua plena!\n");
	else printf("Cua no plena!\n");
	printf("-----------------------------------------------------\n");
	
	//Desencuo un element
	printf("*****************************************************\n");
	treatReturn("Desencuar: ", Desencuar(&test));
	treatReturn("Obtenint el cap, resultat: ", Cap(test, &head));
	printf("El cap de la cua es: %i \n", head);
	ImprimirCua(test);
	printf("-----------------------------------------------------\n");
	
	//Encuo un element
	printf("*****************************************************\n");
	treatReturn("Encuant element: ", Encuar(&test, 30));
	treatReturn("Obtenint el cap, resultat: ", Cap(test, &head));
	printf("El cap de la cua es: %i \n", head);
	ImprimirCua(test);
	printf("-----------------------------------------------------\n");
	
	//Elimino la cua
	printf("*****************************************************\n");
	treatReturn("Destruir: ", Destruir(&test));
	printf("-----------------------------------------------------\n");
	return 1;
}
*/