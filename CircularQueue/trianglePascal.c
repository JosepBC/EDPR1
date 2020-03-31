#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cua.h"

void treatReturn(int n) {
	switch (n) {
	case 0:
		break;
	case 1:
		printf("Error al crear la cua!\n\n");
		break;
	case 2:
		printf("Error al destruir la cua!\n\n");
		break;
	case 3:
		printf("Cua no creada!\n\n");
		break;
	case 4:
		printf("Cua buida!\n\n");
		break;
	case 5:
		printf("Cua plena!\n\n");
		break;
	default:
		printf("Algo ha anat malament!\n\n");
		break;
	}
}

void printRow(Cua c) {
	for (int i = 0; i < c.size; i++) {
		printf("%i ", c.queue[i]);
	}
	printf("\n");
}

void pascalTriangle(int n) {
	int ret, a = 0, prev_a = 0;
	bool buida = false;
	Cua c, prevC;

	Cua *c_ptr, *prevC_ptr, *tmp;
	c_ptr = &c;
	prevC_ptr = &prevC;

	//First row of the triangle
	ret = Crear(prevC_ptr, 1);
	treatReturn(ret);
	ret = Encuar(prevC_ptr, 1);
	treatReturn(ret);
	printRow(*prevC_ptr);
	
	//For-each line that should be in the triangle, calculate
	for (int i = 1; i < n; i++) {
		ret = Crear(c_ptr, prevC_ptr->size + 1);
		treatReturn(ret);
		while (!buida) {
			ret = Cap(*prevC_ptr, &a);
			treatReturn(ret);

			ret = Desencuar(prevC_ptr);
			treatReturn(ret);

			ret = Encuar(c_ptr, a + prev_a);
			treatReturn(ret);
			prev_a = a;

			ret = EsBuida(*prevC_ptr, &buida);
			treatReturn(ret);
		}
		ret = Encuar(c_ptr, 1);
		treatReturn(ret);

		tmp = prevC_ptr;
		prevC_ptr = c_ptr;
		c_ptr = tmp;
		a = 0;
		prev_a = 0;
		buida = false;
		printRow(*prevC_ptr);
	}

	Destruir(c_ptr);
	Desencuar(prevC_ptr);
}

int main() {
	int n;
	printf("Introdueix la profunditat del triangle: ");
	scanf("%i", &n);
	pascalTriangle(n);
	return 0;
}
