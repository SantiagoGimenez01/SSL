#include "histograma.h"
#include <stdio.h>

typedef enum{
    IN, //Dentro de la palabra
    OUT //Fuera de la palabra
} State;

void histograma_enum_switch(int histograma[]){
    //Inicializacion de las variables:
    State estado = OUT; //Comenzamos con el estado dentro de la palabra
    int caracter = 0; // Variable para contar caracteres
    char c; //Variable para leer caracteres del texto
    int ultimo; // Variable para contar ultima palabra

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

                    default:
                        ++caracter; //Sumo el primer caracter encontrado
                        estado = IN; //Cambio de estado
                }
            break;
        //Dentro de la palabra
            case IN:
                switch(c){
                    case '\n': //Salto de linea
                    case '\t': //Tabulador
                    case ' ': //Espacio
                        if(caracter < 21)
                            histograma[caracter - 1]++; //Palabra con largo igual o menor a 20
                        else
                            histograma[19]++; //Palabra de 20 o mas
                            caracter = 0; //Reseteamos contador de caracteres
                            estado = OUT; //Cambio de estado
                    break;

                    default:
                        ++caracter; //Cuento caracteres
                }
            break;

        }

    }
    if(caracter > 0) //Controlo si quedo alguna palabra sin contar
        histograma[caracter - 1]++; //Ultima palabra (por si el prox caracter es '\0')
}