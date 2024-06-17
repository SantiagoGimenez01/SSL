#include <stdio.h>
#include "histograma.h"

int main(){

    int histograma[10] = {0};
    histograma_enum_switch("Hola como andas pepito", histograma);

    for(int i = 0; i < 10; i++)
        printf("%d", histograma);

    return 0;
}