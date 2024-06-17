#include <stdio.h>
#include "Graficador.h"

void graficador(int longitudes[], int dim){

    for(int i = 0; i < dim; i++){
        printf("Longitud (%d):", i+1);
        for(int j = 0; j <= longitudes[i]; j++){
            if(j>0)
                printf("|");
        }
        printf("\n");
    }

}