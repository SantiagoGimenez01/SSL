#include "histograma.h"
#include <stdio.h>

typedef enum{
    IN, //Dentro de la palabra
    OUT, //Fuera de la palabra
    END //Fin
} State;

void getHistograma(DataSet* histograma){
    //Inicializacion de las variables:
    State estado = OUT; //Comenzamos con el estado dentro de la palabra
    int caracter = 0; // Variable para contar caracteres
    char c; //Variable para leer caracteres del texto

    //Algoritmo:
    while((c = getchar()) != EOF){
        switch(estado){ //Verificamos nuestro estado
        //Fuera de la palabra
            case OUT:
                switch(c){
                    case '\n':
                    case '\t':
                    case ' ':
                        //Nada
                    break;
                    case EOF:
                        estado = END;
                    break;
                    default:
                        ++caracter; //Sumo el primer caracter encontrado
                        estado = IN; //Cambio de estado
                }
            break;
        //Dentro de la palabra
            case IN:
                switch(c){
                    case '\n':
                    case '\t':
                    case ' ': 
                        if(caracter <= histograma->dim)
                            histograma->longitudes[caracter - 1]++; //Palabra con largo igual o menor a 23
                        else
                            histograma->longitudes[histograma->dim - 1]++; //Palabra de mas de 23
                            caracter = 0; //Reseteamos contador de caracteres
                            estado = OUT; //Cambio de estado
                    break;
                    case EOF:
                        estado = END;
                    break;
                    default:
                        ++caracter; //Cuento caracteres
                }
            break;
        //Caso EOF
            case END:
                if(caracter <= histograma->dim)
                    histograma->longitudes[caracter - 1]++;
                else
                    histograma->longitudes[histograma->dim - 1]++;
            break;

        }

    }
}