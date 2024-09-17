#include <stdio.h>
#include "DataSet.h"
#include "histograma.h"
#include "Graficador.h"


int main(){

    //Inicializo variables
    //int histograma[23] = {0};
    const int longitudMax = 23;
    DataSet histograma = {{0}, longitudMax};

    //Histograma
    getHistograma(&histograma);

    //Muestreo temporal
     graficador(&histograma);

    return 0;
}
