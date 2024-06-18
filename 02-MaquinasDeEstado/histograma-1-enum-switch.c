#include "histograma.h"
#include <stdio.h>

typedef enum{
    IN, //Dentro de la palabra
    OUT //Fuera de la palabra
} State;
void histograma_enum_switch(const char* texto, int histograma[]){
    //Inicializacion de las variables:
    State estado = OUT; //Comenzamos con el estado dentro de la palabra
    int caracter = 0; // Variable para contar caracteres
    char c; //Variable para leer caracteres del texto
    int i = 0;

    //Algoritmo:
    while((c = texto[i]) != '\0'){
        switch(estado){ //Verificamos nuestro estado

            case OUT: //Fuera de la palabra
                caracter = 0; //Se reinicia el contador de caracteres
                if(c != '\n' || c != ' ' || c != '\t'){ //Controla si el caracter es una letra o numero
                    estado = IN; //Cambia de estado
                    caracter = 1; //Suma el caracter leido
                }         
            break;

            case IN: //Dentro de la palabra
                ++caracter; //Suma caracter
                if(c == ' ' || c == '\t'){ //Controla si es un espacio
                    --caracter; //Resta el caracter ' ' del largo de la palabra
                    ++histograma[caracter-1]; // Suma uno en la respectiva posicion segun el largo de la palabra leida 
                    estado = OUT; //Cambia de estado         
                }
                if(texto[i+1] == '\0') //Controla si luego del caracter leido viene un espacio o EOF
                    ++histograma[caracter-1]; // Suma uno en la respectiva posicion segun el largo de la palabra leida 
            break;

        }
        i++; //Cambia de caracter
    }

}