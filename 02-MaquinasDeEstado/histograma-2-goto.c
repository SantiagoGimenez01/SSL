#include <stdio.h>
#include "histograma.h"

void getHistograma(DataSet* histograma){
    int caracter = 0;
    goto Out;

    Out: // Fuera de la palabra
        switch(getchar()){
            case ' ':
            case '\t':
            case '\n':
                goto Out;
            case EOF:
                break;
            default:
                ++caracter;
                goto In;
        }

    In: //Dentro de la palabra
        switch(getchar()){
            case ' ':
            case '\t':
            case '\n':
                histograma->longitudes[caracter - 1]++;
                caracter = 0;
                goto Out;
            case EOF:
                if(caracter > 0)
                    histograma->longitudes[caracter - 1]++;
                break;
            default:
                ++caracter;
                goto In;
        }

}