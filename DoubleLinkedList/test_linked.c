#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"

void treatReturn(char* str, int n) {
	switch (n) {
	case 0:
		printf("%s Operacio realitzada amb exit!\n\n", str);
		break;
	case 1:
		printf("%s Error al crear la llistaa!\n\n", str);
		break;
	case 2:
		printf("%s Error al destruir la llista!\n\n", str);
		break;
	case 3:
		printf("%s Llista no creada!\n\n", str);
		break;
	case 4:
		printf("%s Llista buida!\n\n", str);
		break;
	case 5:
		printf("%s Element no creat!\n\n", str);
		break;
	case 6:
		printf("%s Memoria insuficient!\n\n", str);
		break;
	case 7:
		printf("%s Operacio no permitida!\n\n", str);
		break;
	default:
		printf("%s Algo ha anat malament!\n\n", str);
		break;
	}
}

int menu() {
	int ret;
	printf("Que vols fer:\n");
	printf("\t0. Sortir\n");
	printf("\t1. Principi\n");
	printf("\t2. Final\n");
	printf("\t3. Avancar\n");
	printf("\t4. Retrocedir\n");
	printf("\t5. EsFinal\n");
	printf("\t6. Actual\n");
	printf("\t7. Inserir\n");
	printf("\t8. Esborrar\n");
	printf("\t9. Longitud\n");
	printf("\t10. Buscar\n");
	printf("\t11. Cost_Buscar\n");
	printf("\t12. Imprimir llista\n");
	scanf("%i", &ret);
	return ret;
}

int main(int argc, char const* argv[]) {
	llista_encadenada llista;
	int ret, option, elem, ins = 0, lon, search, numberOfIterations;
	bool end, found;

	ret = Crear(&llista);
	treatReturn("Crear llista: ", ret);
	Imprimir_Llista(llista);

	option = menu();
	while (option != 0) {
		switch (option) {
		case 1: 
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Principi(&llista);
			treatReturn("Principi: ", ret);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 2:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Final(&llista);
			treatReturn("Final: ", ret);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 3:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Avancar(&llista);
			treatReturn("Avancar: ", ret);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 4:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Retrocedir(&llista);
			treatReturn("Retrocedir: ", ret);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 5:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Es_Final(llista, &end);
			treatReturn("Es_Final: ", ret);
			if (end) printf("El PDI esta al final de la llista\n");
			else printf("El PDI NO esta al final de la llista\n");
			break;
		case 6:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Actual(llista, &elem);
			treatReturn("Actual: ", ret);
			printf("L'element actual es: %i\n", elem);
			break;
		case 7:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Inserir(&llista, ins+=10);
			treatReturn("Inserir: ", ret);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 8:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Esborrar(&llista);
			treatReturn("Esborrar: ", ret);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 9:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			ret = Longitud(llista, &lon);
			printf("Longitud de la llista: %i\n", lon);
			treatReturn("Longitud: ", ret);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 10:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			printf("Quin element vols buscar? ");
			scanf("%i", &search);
			ret = Buscar(llista, search, &found);
			treatReturn("Buscar: ", ret);
			if (found) printf("Element trobat!\n");
			else printf("Element no trobat!\n");
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 11:
			printf("Abans:\n");
			Imprimir_Llista(llista);
			printf("Quin element vols buscar? ");
			scanf("%i", &search);
			ret = Cost_Buscar(llista, search, &numberOfIterations);
			treatReturn("Buscar: ", ret);
			printf("Iteracions: %i\n", numberOfIterations);
			printf("Despres:\n");
			Imprimir_Llista(llista);
			break;
		case 12:
			Imprimir_Llista(llista);
			break;
		default:
			break;
		}
		option = menu();
	}

	ret = Destruir(&llista);
	treatReturn("Destruir llista: ", ret);
}