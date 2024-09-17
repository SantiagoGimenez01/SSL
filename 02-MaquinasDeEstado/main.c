#include <stdio.h>
#include "DataSet.h"
#include "histograma.h"
#include "Graficador.h"


int main(){

    //Inicializo variables
    //int histograma[23] = {0};
    const int longitudMax = 23;
    DataSet histograma = {{0}, longitudMax};

    //Implementacion 1
    //histograma_enum_switch(&histograma);
    
    //Implementacion 2
    //histograma_goto(&histograma);

    //Implementacion 3
    histograma_recursividad(&histograma);

    //Muestreo temporal
     graficador(&histograma);

    return 0;
}
