#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "linked_list.h"
#include "random.h"

#define FILE_NAME "searchRawData.csv"

void treatReturn(char* str, int n, bool debug) {
    switch (n) {
    case 0:
        if (debug) printf("%s Operacio realitzada amb exit!\n\n", str);
        break;
    case 1:
        printf("%s Error al crear la llistaa!\n\n", str);
        break;
    case 2:
        printf("%s Error al destruir la llista!\n\n", str);
        break;
    case 3:
        printf("%s Llista no creada!\n\n", str);
        break;
    case 4:
        printf("%s Llista buida!\n\n", str);
        break;
    case 5:
        printf("%s Element no creat!\n\n", str);
        break;
    case 6:
        printf("%s Memoria insuficient!\n\n", str);
        break;
    case 7:
        printf("%s Operacio no permitida!\n\n", str);
        break;
    default:
        printf("%s Algo ha anat malament!\n\n", str);
        break;
    } 
}

int menu() {
    int ret;
    printf("Que vols fer:\n");
    printf("\t0. Sortir\n");
    printf("\t1. Principi\n");
    printf("\t2. Final\n");
    printf("\t3. Avancar\n");
    printf("\t4. Retrocedir\n");
    printf("\t5. EsFinal\n");
    printf("\t6. Actual\n");
    printf("\t7. Inserir\n");
    printf("\t8. Esborrar\n");
    printf("\t9. Longitud\n");
    printf("\t10. Buscar\n");
    printf("\t11. Cost_Buscar\n");
    printf("\t12. Imprimir llista\n");
    scanf("%i", &ret);
    return ret;
}

int globalMenu() {
    int a;
    printf("0. Sortir\n");
    printf("1. Uni test\n");
    printf("2. Search Cost\n");
    scanf("%i", &a);
    return a;
}

void uniTest() {
    llista_encadenada llista;
    int ret, option, elem, ins = 0, lon, search, numberOfIterations;
    bool end, found;

    ret = Crear(&llista);
    treatReturn("Crear llista: ", ret, true);
    Imprimir_Llista(llista);

    option = menu();
    while (option != 0) {
        switch (option) {
        case 1:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Principi(&llista);
            treatReturn("Principi: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 2:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Final(&llista);
            treatReturn("Final: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 3:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Avancar(&llista);
            treatReturn("Avancar: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 4:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Retrocedir(&llista);
            treatReturn("Retrocedir: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 5:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Es_Final(llista, &end);
            treatReturn("Es_Final: ", ret, true);
            if (end) printf("El PDI esta al final de la llista\n");
            else printf("El PDI NO esta al final de la llista\n");
            break;
        case 6:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Actual(llista, &elem);
            treatReturn("Actual: ", ret, true);
            printf("L'element actual es: %i\n", elem);
            break;
        case 7:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Inserir(&llista, ins += 10);
            treatReturn("Inserir: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 8:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Esborrar(&llista);
            treatReturn("Esborrar: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 9:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            ret = Longitud(llista, &lon);
            printf("Longitud de la llista: %i\n", lon);
            treatReturn("Longitud: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 10:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            printf("Quin element vols buscar? ");
            scanf("%i", &search);
            ret = Buscar(llista, search, &found);
            treatReturn("Buscar: ", ret, true);
            if (found) printf("Element trobat!\n");
            else printf("Element no trobat!\n");
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 11:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            printf("Quin element vols buscar? ");
            scanf("%i", &search);
            ret = Cost_Buscar(llista, search, &numberOfIterations);
            treatReturn("Buscar: ", ret, true);
            printf("Iteracions: %i\n", numberOfIterations);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 12:
            Imprimir_Llista(llista);
            break;
        default:
            break;
        }
        option = menu();
    }

    ret = Destruir(&llista);
    treatReturn("Destruir llista: ", ret, true);
}

int average(int* v, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += v[i];
    
    return sum / size;
}

double calculateSD(llista_encadenada *list) {
    double mean, sd = 0.0, sum = 0.0;
    int ret, elem;
    Principi(list);
    for (int i = 0; i < list->elems; i++) {
        ret = Avancar(list);
        treatReturn("Avancar: ", ret, false);

        ret = Actual(*list, &elem);
        treatReturn("Actual: ", ret, false);

        sum += (double)elem;
    }
    mean = sum / list->elems;

    Principi(list);
    for (int i = 0; i < list->elems; i++) {
        ret = Avancar(list);
        treatReturn("Avancar: ", ret, false);

        ret = Actual(*list, &elem);
        treatReturn("Actual: ", ret, false);


        sd += pow(elem - mean, 2);
    }

    return sqrt(sd / list->elems);
}

void algorithmicCost() {
    llista_encadenada list;
    int rnd, iterations, ret, avgIterations;
    long seed1, seed2;
    int iterationsVect[1000];//Stores the number of iterations of each search, to calculate de avg
    double stdev;

    FILE* data = fopen(FILE_NAME, "w");
    if (data == NULL) {
        printf("El fitxer no s'ha pogut obrir, abortant....");
        exit(EXIT_FAILURE);
    }

    fprintf(data, "Dim\tAvg Iterations\tStandard Desviation\n");

    phrtsd("HelloMyNameIsJosep", &seed1, &seed2);
    setall(seed1, seed2);

    for (int size = 1000; size <= 50000; size += 1000) {
        ret = Crear(&list);
        treatReturn("Crear: ", ret, false);

        printf("Starting size %i\n", size);
        //List full of randoms betwen 1 and 2 * size
        for (int i = 0; i < size; i++) {
            rnd = (int)ignuin(1, 2 * size);

            ret = Inserir(&list, rnd);
            treatReturn("Inserir: ", ret, false);

            ret = Final(&list);
            treatReturn("Final: ", ret, false);
        }

        for (int i = 0; i < 1000; i++) {
            //Search 1000 times random numbers, get the iteration number and store it to the vector to calculete de avg after
            rnd = (int)ignuin(1, 2 * size);

            ret = Cost_Buscar(list, rnd, &iterations);
            treatReturn("Cost Buscar: ", ret, false);

            iterationsVect[i] = iterations;
        }

        avgIterations = average(iterationsVect, 1000);
        printf("Average iterations: %i\n", avgIterations);

        stdev = calculateSD(&list);

        fprintf(data, "%i\t%i\t%g\n", size, avgIterations, stdev);

        printf("Size %i DONE!\n\n", size);

        ret = Destruir(&list);
        treatReturn("Destruir", ret, false);
    }

    fclose(data);
}

int main(int argc, char const* argv[]) {
    int option = globalMenu();
    while (option != 0) {
        switch (option) {
        case 1:
            uniTest();
            break;
        case 2:
            algorithmicCost();
            break;
        }
        option = globalMenu();
    }
}