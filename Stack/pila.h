typedef struct Pila {
	int size;
	int actIdx;
	int* stack;
}Pila;

extern Pila Crear(int size);
extern int Cim(Pila p);
extern void Apilar(Pila* ap, int elem);
extern void Desapilar(Pila* ap);
extern bool EsBuida(Pila p);
extern bool EsPlena(Pila p);
extern void Destruir(Pila* ap);
extern void ImprimirPila(Pila ap);
extern bool Duplicar(Pila* ap);
extern bool Permutar(Pila* ap);
extern bool CicleTres(Pila* ap);
extern bool ApilarElemNVegades(Pila* ap, int n, int newval);