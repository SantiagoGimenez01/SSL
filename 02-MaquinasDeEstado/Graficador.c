#include <stdio.h>
#include "Graficador.h"

void graficador(DataSet* histograma){

    for(int i = 0; i < histograma->dim; i++){
        if(i < histograma->dim - 1)
            printf("Longitud (%d):", i+1);
        else
            printf("Longitud (%d o mas):", histograma->dim);
        for(int j = 0; j <= histograma->longitudes[i]; j++){
            if(j>0)
                printf("|");
        }
        printf("\n");
    }

}