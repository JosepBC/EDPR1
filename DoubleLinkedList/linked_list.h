#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define CUA_NO_CREADA 3
#define CUA_BUIDA 4
#define CUA_PLENA 5
#define ERROR_INDETERMINAT 6

typedef struct llista_encadenada {
	int pdi, elems;
	Node_t first;
	Node_t last;
}llista_encadenada;

typedef struct Node_t {
	int elem;
	Node_t *next, *previous;
}Node_t;

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
