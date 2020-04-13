#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "random.h"
#include "skip_list.h"

#define FILE_NAME "searchRawData.csv"

void treatReturn(char *str, int n, bool debug) {
    switch (n) {
    case 0:
        if (debug) printf("%s Operacio realitzada amb exit!\n\n", str);
        break;
    case 1:
        printf("%s Error al crear la llista!\n\n", str);
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
    case 8:
        printf("%s Error al esborrar!\n\n", str);
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
    printf("\t1. Inserir\n");
    printf("\t2. Esborrar\n");
    printf("\t3. Longitud\n");
    printf("\t4. Buscar\n");
    printf("\t5. Cost_Buscar\n");
    printf("\t6. Imprimir llista\n");
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
    skip_list llista;
    int ret, option, elem, ins = 0, search, numberOfIterations, lon;
    bool found;

    ret = Crear(&llista);
    treatReturn("Crear llista: ", ret, true);
    Imprimir_Llista(llista);

    option = menu();

    while (option != 0) {
        switch (option) {
        case 1:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            printf("Quin element vols inserir?");
            scanf("%i", &ins);
            ret = Inserir(&llista, ins);
            treatReturn("Inserir: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 2:
            printf("Abans:\n");
            Imprimir_Llista(llista);
            printf("Quin element vols eliminar? ");
            scanf("%i", &elem);
            ret = Esborrar(&llista, elem);
            treatReturn("Esborrar: ", ret, true);
            printf("Despres:\n");
            Imprimir_Llista(llista);
            break;
        case 3:
            ret = Longitud(llista, &lon);
            treatReturn("Longitud: ", ret, true);
            printf("La longitud de la llista es: %i", lon);
            break;
        case 4:
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
        case 5:
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
        case 6:
            Imprimir_Llista(llista);
            break;
        }
        option = menu();
    }

    ret = Destruir(&llista);
    treatReturn("Destruir: ", ret, true);
}

int average(int *v, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += v[i];

    return sum / size;
}

double calculateSD(int *data, int dataSize) {
    double sum = 0.0, mean, SD = 0.0;
    for (int i = 0; i < dataSize; ++i) {
        sum += (double)data[i];
    }

    mean = sum / dataSize;

    for (int i = 0; i < dataSize; ++i)
        SD += pow((double)data[i] - mean, 2);

    return sqrt(SD / dataSize - 1);
}

void algorithmicCost() {
    skip_list list;
    int rnd, iterations, ret, avgIterations;
    long seed1, seed2;
    int iterationsVect[1000];//Stores the number of iterations of each search, to calculate de avg
    double stdev;

    FILE *data = fopen(FILE_NAME, "w");
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

        stdev = calculateSD(iterationsVect, 1000);

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