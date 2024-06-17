#include "histograma.h"


typedef enum{
    IN, //Dentro de la palabra
    OUT //Fuera de la palabra
} State;

int* histograma_enum_switch(const char* texto, int histograma[]){
    //Inicializacion de las variables:
    State estado = OUT; //Comenzamos con el estado fuera de la palabra
    int caracter; // Variable para contar caracteres
    char c; //Variable para leer caracteres del texto

    //Algoritmo:
    while((c = getchar()) != '\0'){
        switch(estado){
            case OUT:
                caracter = 0;
                if(c != '\n' || c != " " || c != '\t'){
                    estado = IN;
                    ++caracter;
                }         
            break;

            case IN:
                if(c == '\n' || c == " " || c == '\t'){
                    estado = OUT;
                    --caracter;
                }
                ++caracter;
                histograma[caracter]++;
            break;
        }
    }
    

}