#include <stdio.h>
#include "Graficador.h"

#include <stdio.h>
#include "Graficador.h"

const int dim = 23;

void graficador(int longitudes[]){

    for(int i = 0; i < dim; i++){
        if(i < dim - 1)
            printf("Longitud (%d):", i+1);
        else
            printf("Longitud (%d o mas):", dim);
        for(int j = 0; j <= longitudes[i]; j++){
            if(j>0)
                printf("|");
        }
        printf("\n");
    }

}