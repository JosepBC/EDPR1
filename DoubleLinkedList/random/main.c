#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "random.h"

int main()
{
    const long LARGEST = 1000000;
    const long REPETITIONS = 100000;
    long seed1, seed2;
    long i;
    long r, r_max;

    /* Comprovacio mida dels tipus int i long  */
    printf("INT_MAX  = %d\n", INT_MAX);
    printf("LONG_MAX = %d\n\n", LONG_MAX);

    /* Establiment de les llavors del generador */
    phrtsd("Hola", &seed1, &seed2);
    setall(seed1, seed2);

    /* Generar molts nombres per a veure si arriben als valors desitjats */
    r_max = 0.0;
    for (i = 1; i <= REPETITIONS; i++) {
        r = ignuin(1, LARGEST);
        if (r > r_max) {
            r_max = r;
        }
    }
    printf("r_max = %d\n", r_max);
}
