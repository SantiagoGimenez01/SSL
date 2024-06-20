#include <stdio.h>
#include "histograma.h"
#include "Graficador.h"

int main(){

    //Inicializo variables
    int histograma[20] = {0};

    //Implementacion 1
    histograma_enum_switch(histograma);
    
    //Muestreo temporal
    graficador(histograma, 20);

    return 0;
}
