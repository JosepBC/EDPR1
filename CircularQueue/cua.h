#define SUCCESS 0
#define ERROR_CREAR 1
#define ERROR_DESTRUIR 2
#define CUA_NO_CREADA 3
#define CUA_BUIDA 4
#define CUA_PLENA 5
#define ERROR_INDETERMINAT 6

typedef struct Cua {
	int* queue;
	int size;
	int readIdx;
	int storedElems;
}Cua;

extern int Crear(Cua* ac, int size);
extern int Encuar(Cua* ac, int elem);
extern int Desencuar(Cua* ac);
extern int Cap(Cua c, int* elem);
extern int EsBuida(Cua c, bool* b);
extern int EsPlena(Cua c, bool* b);
extern int Destruir(Cua* ac);
extern void ImprimirCua(Cua c);
