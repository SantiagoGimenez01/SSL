#include <stdio.h>
#include "histograma.h"
#include "Graficador.h"

int main(){

    //Inicializo variables
    int histograma[10] = {0};
    char texto[100];
    //Ingreso palabras mediante stdin
    printf("Ingrese un texto: \n");
    fgets(texto, sizeof(texto), stdin);
    //Implementacion 1
    histograma_enum_switch(texto, histograma);
    //Muestreo temporal
    graficador(histograma, 10);

    return 0;
}