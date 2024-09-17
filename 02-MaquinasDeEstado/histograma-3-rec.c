#include <stdio.h>
#include "histograma.h"

//Inicializamos variables
int caracter = 0;
char c;

//Prototipos
void espaciosBlancos(DataSet* histograma);
void contarCaracteres(DataSet* histograma);
void fin(DataSet* histograma);

void getHistograma(DataSet* histograma){

    //Algoritmo

    //Comenzamos afuera de la palabra
    espaciosBlancos(histograma);
        
}

void espaciosBlancos(DataSet* histograma){     

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

void contarCaracteres(DataSet* histograma){
    
    switch(c = getchar()){
        //Fuera de la palabra
            case ' ':
            case '\t':
            case '\n':
                if(caracter <= histograma->dim)  //Palabra de largo 1 a 23
                    histograma->longitudes[caracter - 1]++; //Sumo al histograma segun posicion
                else
                    histograma->longitudes[histograma->dim - 1]++; //Sumo en la ultima posicion si la palabra es mayor a 23
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

void fin(DataSet* histograma){
    if(caracter <= histograma->dim) //Sumamos ultima palabra a posicion segun largo
        histograma->longitudes[caracter - 1]++;
    else
        histograma->longitudes[histograma->dim - 1]++;
}