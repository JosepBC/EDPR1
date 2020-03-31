#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pila.h"

#define FILE_NAME "testfile.txt"
#define STACK_SIZE 10
#define MAX_STRING_READ 100

void add(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);

	int b = Cim(*p);
	Desapilar(p);

	int add = a + b;
	Apilar(p, add);
}

void sub(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);

	int b = Cim(*p);
	Desapilar(p);

	int sub = b - a;
	Apilar(p, sub);
}

void mul(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);

	int b = Cim(*p);
	Desapilar(p);

	int mul = a * b;
	Apilar(p, mul);
}

void divide(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);
	if (a == 0) {
		printf("*****No pots dividir per zero****");
		Destruir(p);
		exit(EXIT_FAILURE);
	}
	int b = Cim(*p);
	Desapilar(p);

	int div = b / a;
	Apilar(p, div);
}

void chs(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);

	int chs = -a;
	Apilar(p, chs);
}

void power(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);

	int b = Cim(*p);
	Desapilar(p);

	int power = (int)pow((double)b, (double)a);
	Apilar(p, power);
}

int factRec(int a) {
	if (a == 0) return 1;
	return a * factRec(a - 1);
}

void fact(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);

	Apilar(p, factRec(a));
}

void mod(Pila* p) {
	int a = Cim(*p);
	Desapilar(p);

	int b = Cim(*p);
	Desapilar(p);

	int mod = b % a;
	Apilar(p, mod);
}

void operate(Pila* p, char *elem) {
	if (strcmp(elem, "+") == 0) add(p);
	else if (strcmp(elem, "-") == 0) sub(p);
	else if (strcmp(elem, "*") == 0) mul(p);
	else if (strcmp(elem, "/") == 0) divide(p);
	else if (strcmp(elem, "^") == 0) power(p);
	else if (strcmp(elem, "chs") == 0) chs(p);
	else if (strcmp(elem, "!") == 0) fact(p);
	else if (strcmp(elem, "mod") == 0) mod(p);
	
}

bool isOperator(char* src) {
	return (strlen(src) == 1 && (src[0] == '+' || src[0] == '-' || src[0] == '*' || src[0] == '/' || src[0] == '^' || src[0] == '!')) || strcmp(src, "chs") == 0 || strcmp(src, "mod") == 0;

}

int parseNumber(char* src) {
	int init = 0, val = 0;

	init = src[0] == '-';

	for (int i = init; src[i] != '\0'; i++) {
		val = val * 10 + (src[i] - '0');
	}

	if (src[0] == '-') val *= -1;
	return val;
}

int main(int argc, char const* argv[]) {
	char str[MAX_STRING_READ];

	Pila p = Crear(STACK_SIZE);
	FILE* f = fopen(FILE_NAME, "r");

	if (f == NULL) {
		printf("*****Fitxer no trobat*****");
		Destruir(&p);
		exit(EXIT_FAILURE);
	}

	fgets(str, MAX_STRING_READ, f);

	char* token = strtok(str, ","); //Primer token

	while (token != NULL) {
		if (isOperator(token))
			operate(&p, token);
		else 
			Apilar(&p, parseNumber(token));

		token = strtok(NULL, ",");//Siguiente token
	}

	if (p.actIdx >= 1) {
		ImprimirPila(p);
		printf("*****Hi ha mes d'un element a la pila!*****");
		Destruir(&p);
		fclose(f);
		exit(EXIT_FAILURE);
	}

	printf("El resultat de l'operacio es: %i", Cim(p));
	Destruir(&p);
	fclose(f);
	return 0;
}
