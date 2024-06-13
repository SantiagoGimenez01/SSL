#include "histograma.h"


typedef enum{
    IN, //Dentro de la palabra
    OUT //Fuera de la palabra
} State;

int* histograma_enum_switch(const char* texto){
    State estado = OUT; //Comenzamos con el estado fuera de la palabra
    int histograma[10]; // Vector para guardar cantidad de palabras segun largo (max largo = 10)
    int caracter; // Variable para contar caracteres
    char c; //Variable para leer caracteres del texto
    while((c = texto[caracter]) != '\0'){
        switch(estado){
            case OUT:
                caracter = 0;
                if(c != '\n' || c != " " || c != '\t')
                    estado = IN;
                ++caracter;
                break;
        }
    }
    

}