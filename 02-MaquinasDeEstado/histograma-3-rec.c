#include <stdio.h>
#include "histograma.h"

#define MAX_CARACTERES 23

//Inicializamos variables
int caracter = 0;
char c;

//Prototipos
void espaciosBlancos(int histograma[]);
void contadorCaracteres(int histograma[]);
void fin(int histograma[]);

void histograma_recursividad(int histograma[]){

    //Algoritmo

    //Comenzamos afuera de la palabra
    espaciosBlancos(histograma);
        
}

void espaciosBlancos(int histograma[]){     

        switch(c = getchar()){
        //Fuera de la palabra
            case ' ':
            case '\t':
            case '\n':
                espaciosBlancos(histograma); //Sigo en el mismo estado
            break;

        //Fin de palabra
            case EOF:
                fin(histograma); //Fin de palabra
            break;

        //Dentro de la palabra
            default:
                ++caracter; //Sumo primer caracter encontrado
                contarCaracteres(histograma); //Cambio de estado
        }
}

void contarCaracteres(int histograma[]){
    
    switch(c = getchar()){
        //Fuera de la palabra
            case ' ':
            case '\t':
            case '\n':
                if(caracter <= MAX_CARACTERES)  //Palabra de largo 1 a 23
                    histograma[caracter - 1]++; //Sumo al histograma segun posicion
                else
                    histograma[MAX_CARACTERES - 1]++; //Sumo en la ultima posicion si la palabra es mayor a 23
                caracter = 0; // Reseteamos caracteres
                espaciosBlancos(histograma); //Cambio de estado
            break;

        //Fin de palabra
            case EOF:
                fin(histograma); //Fin de palabra
            break;

        //Dentro de la palabra
            default:
                ++caracter; //Sumo caracter
                contarCaracteres(histograma); //Sigo en el mismo estado
        }
}

void fin(int histograma[]){
    if(caracter <= MAX_CARACTERES) //Sumamos ultima palabra a posicion segun largo
        histograma[caracter - 1]++;
    else
        histograma[MAX_CARACTERES - 1]++;
}