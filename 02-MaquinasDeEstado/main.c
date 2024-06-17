#include <stdio.h>
#include "histograma.h"

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
    for(int i = 0; i < 10; i++)
        printf("%d", histograma[i]);

    return 0;
}