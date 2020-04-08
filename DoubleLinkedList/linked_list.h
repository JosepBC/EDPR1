#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define LLISTA_NO_CREADA 3
#define LLISTA_BUIDA 4
#define ELEMENT_NO_CREAT 5
#define MEMORIA_INSUFICIENT 6
#define OPERACIO_NO_PERMITIDA 7

typedef struct Node_t {
	int elem;
	struct Node_t *next, *previous;
}Node_t;

typedef struct llista_encadenada {
	int elems;
	Node_t *pdi;
	Node_t *first;
	Node_t *last;
	Node_t *ghost;
}llista_encadenada;

extern int Crear(llista_encadenada* ll);
extern int Destruir(llista_encadenada* ll);
extern int Principi(llista_encadenada* ll);
extern int Final(llista_encadenada* ll);
extern int Avancar(llista_encadenada* ll);
extern int Retrocedir(llista_encadenada* ll);
extern int Es_Final(llista_encadenada ll, bool* esfinal);
extern int Actual(llista_encadenada ll, int* elem);
extern int Inserir(llista_encadenada* ll, int elem);
extern int Esborrar(llista_encadenada* ll);
extern int Longitud(llista_encadenada ll, int* lon);
extern int Buscar(llista_encadenada ll, int elem, bool* trobat);
extern int Cost_Buscar(llista_encadenada ll, int elem, int* cost);
extern int Imprimir_Llista(llista_encadenada ll);
