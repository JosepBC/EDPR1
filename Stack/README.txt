Control d'errors a l'implementació de la pila:
    Ja que C no conta amb excepcions he decidit que en el cas de que una operació de les que ja tenim les capcaleres falli es fa un exit(EXIT_FAILURE).
    Operacions suceptibles a fallar i que fan un exit:
        - Cim -> si la pila no existeix o es buida
        - Apilar -> si la pila no existeix o es plena
        - Desapilar -> si la pila no existeix o es buida
        - EsBuida, EsPlena, ImprimirPila -> si la pila no existeix


    Però he fet que les operacions extra retornin true o false depenen si ha completat amb exit la operació o no, ja que així el programa pot seguir amb la seva execució normal.
    Operacions suceptibles a fallar i que retornen false:
        - Duplicar -> si la pila no existeix o es buida
        - Permutar -> si la pila no existeix o no hi ha almenys dos elements
        - CicleTres -> si la pila no existeix o no hi ha almenys tres elements
        ApilarElemNVegades-> si la pila no existeix

Funcions extra a pila:
    - ImprimirPila(Pila p)
        Mostra per pantalla la pila per fer debug

    - Dupilicar(Pila p)
        Duplica el cim de la pila

    - Permutar(Pila p)
        Permuta els dos ultims elements de la pila: Si teniem "x,y" desorés d'aplicar aquesta operació hi ha "y,x"

    - CicleTres(Pila p)
        Si teniem els elements "x, y, z" a la pila, després d'aquesta operació hi ha "z, x, y" 

    - ApilarElemNVegades(Pila p, ent n, ent nouValor)
        Apila l'element passat per paràmetre (nouValor) les vegades que se li passen per un altre paràmetre (n) vegades

Operacions extra a la calculadora:
    - Potència (^)
        Desapila els dos ultims elements de la pila i eleva el segon que trau al primer que trau:
        Ex: "2, 5, ^" -> "32"
    - Factorial (!)
        Fa el factorial (amb una funció recursiva) del valor que hi ha al cim de la pila:
        Ex: "3, !" -> "6"
    - Mòdul(mod)
        Fa el mòdul (divisió entera) dels dos ultims valors de la pila:
        Ex: "4, 3, mod" -> 1 

Coses a destacar sobre la calculadora: 
    En cas de voler afegir una nova operació es tan simple com afegir l'operador a isOperator i crear una nova funció per operate on s'implementi tota la lògica de la operació.
