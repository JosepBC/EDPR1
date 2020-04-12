#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define LLISTA_NO_CREADA 3
#define LLISTA_BUIDA 4
#define ELEMENT_NO_CREAT 5
#define MEMORIA_INSUFICIENT 6
#define OPERACIO_NO_PERMITIDA 7
#define ERROR_ESBORRAR 8

typedef struct Node_t {
    int elem;
    struct Node_t *right, *left, *top, *bottom;
}Node_t;

typedef struct skip_list {
    int elemNumber, height;
    Node_t *topLeft;
}skip_list;

extern int Crear(skip_list* sl);
extern int Destruir(skip_list* sl);
extern int Inserir(skip_list* sl, int elem);
extern int Esborrar(skip_list* sl, int elem);
extern int Longitud(skip_list sl, int* lon);
extern int Buscar(skip_list sl, int elem, bool* trobat);
extern int Cost_Buscar(skip_list sl, int elem, int* cost);
