#include "histograma.h"
#include <stdio.h>
#include "Graficador.h"

typedef enum{
    IN, //Dentro de la palabra
    OUT //Fuera de la palabra
} State;
void histograma_enum_switch(const char* texto, int histograma[]){
    //Inicializacion de las variables:
    State estado = IN; //Comenzamos con el estado dentro de la palabra
    int caracter = 0; // Variable para contar caracteres
    char c; //Variable para leer caracteres del texto
    int i = 0;

    //Algoritmo:
    while((c = texto[i]) != '\0'){
        switch(estado){
            case OUT:
                ++histograma[caracter-1];
                caracter = 0;
                if(c != '\n' || c != ' ' || c != '\t'){
                    estado = IN;
                    ++caracter;
                }
                        
            break;

            case IN:
                ++caracter;
                if(c == '\n' || c == ' ' || c == '\t'){
                    estado = OUT;
                    --caracter;
                }
                if(texto[i+1] == '\0')
                    ++histograma[caracter-1];
            break;
        }
        ++i;
    }

}