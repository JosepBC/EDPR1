Sobre l'implementació de la llista cal destacar:
- Utilitzo una estructura Node a la que guardo l'element d'aquella posició i punters al element anterior i següent.
- A l'estructura de la llista, "llista_encadenada" guardo:
	- elems: Nombre d'elements que conte aquesta, així el cost de longitud es constant, i puc utilitzar aquest valor per tractar els casos en que tinc 0, 1 o +1 element de forma diferent fàcilment.

	- pdi: Punter al punt d'interès demanat a l'enunciat de la pràctica.

	- ghost: A causa d'implementar la llista amb un pdi es útil l'us d'un element fantasma per tal de poder inserir en la primera posició de la llista. El punter next apuntara sempre a first, i el punter previous sempre a nul.

	- first: Punter al primer element de la llista, el punter a la seva esquerra (previous) es sempre ghost. Aquest punter es el que utilitzo per anar iterant sobre la llista.

	- last: Punter al ultim element de la llista, el punter a la seva dreta (next) es sempre nul. Tot i que en aquest cas no es crític, ja que l'insercio es fa sempre al pdi, no al final de la llista, he decidit guardar aquest punter ja que així puc moure el pdi al final amb un cost constant. A més a més l'utilitzo per saber si estic al final de la llista, això també es podria fer mirant si el punter next es nul, però així queda el codi mes comprensible.

- Codis d'error:
	- SUCCESS 0
	- ERROR_CREAR 1
	- ERROR_DESTRUIR 2
	- LLISTA_NO_CREADA 3
	- LLISTA_BUIDA 4
	- ELEMENT_NO_CREAT 5
	- MEMORIA_INSUFICIENT 6
	- OPERACIO_NO_PERMITIDA 7

- Destruir(llista_encadenada)
	Aquesta funció comença al segon element, si existeix, i va fent un free de l'anterior sempre.

- Inserir(llista_encadenada, elem)
	Insereix l'element passat per paràmetre a la dreta del pdi, es per això que tinc l'element fantasma al principi de la llista.

- Esborrar(llista_encadenada)
	Esborra l'element apuntat pel pdi, però si aquest es el fantasma retorna un codi d'error (OPERACIO_NO_PERMITIDA)

- Funcions extra:
	- Imprimir_Llista(llista_encadenada ll)
		Mostra per pantalla tota la informació de la llista i la llista començant desde first fins last i desde last fins first.

