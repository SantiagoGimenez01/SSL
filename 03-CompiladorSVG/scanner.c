#include "scanner.h"
#include <stdio.h>
#include <ctype.h>

typedef enum{
    INICIAL,
    ESPACIO,
    KEYWORD, 
    NUMERO, 
    SIMBOLO, 
    CADENA, 
    ERROR, 
    FIN
}State;

int getNextToken(){
    char c;
    char token[100];
    int i = 0;
    State estado = INICIAL;

    while((c = getchar()) != EOF){
        switch(estado){
            case INICIAL:
                if(isspace(c))
                    estado = ESPACIO;
                else if(isalpha(c))
                    estado = KEYWORD;
                else if(isdigit(c))
                    estado = NUMBER;
                else if(c == '\'')
                    estado = CADENA;
                else if(c == ';' || c == '=')
                    estado = SIMBOLO;
                else 
                    estado = ERROR;
            break;
            case KEYWORD:
                i = 0;
                while(isalpha(c)){
                    token[i++] = c;
                    c = getchar();
                }
                token[i] = '\0';
                if(strcmp(token, "cuad") == 0)
                    return KEYWORD_CUADRADO;
                else if(strcmp(token, "rect") == 0)
                    return KEYWORD_RECTANGULO;
                else if(strcmp(token, "tri") == 0)
                    return KEYWORD_TRIANGULO;
                else if(strcmp(token, "circ") == 0)
                    return KEYWORD_CIRCULO;
                else if(strcmp(token, "blue") == 0)
                    return COLOR_BLUE;
                else if(strcmp(token, "yellow") == 0)
                    return COLOR_YELLOW;
                else if(strcmp(token, "red") == 0)
                    return COLOR_RED;
                else if(strcmp(token, "green") == 0)
                    return COLOR_GREEN;
                else if(strcmp(token, "fill") == 0)
                    return KEYWORD_FILL;
                else if(strcmp(token, "border") == 0)
                    return KEYWORD_BORDER;
                else if(strcmp(token, "text") == 0)
                    return KEYWORD_TEXT;
                else
                    estado = ERROR;
            break;
            case ESPACIO:
            break;
            case NUMERO:
            break;
            case SIMBOLO:
            break;
            case CADENA:
            break;
            case ERROR:
            break;
            case FIN:
            break;
        }
    }

}