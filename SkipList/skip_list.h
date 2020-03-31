#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define CUA_NO_CREADA 3
#define CUA_BUIDA 4
#define CUA_PLENA 5
#define ERROR_INDETERMINAT 6

typedef struct skip_list {
	int elem;
}skip_list;

extern int Crear(skip_list* sl);
extern int Destruir(skip_list* sl);
extern int Inserir(skip_list* sl, int elem);
extern int Esborrar(skip_list* sl, int elem);
extern int Longitud(skip_list sl, int* lon);
extern int Buscar(skip_list sl, int elem, bool* trobat);
extern int Cost_Buscar(skip_list sl, int elem, int* cost);