#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

//Tipos de token
enum TokensTypes{
    KEYWORD_CUADRADO,  
    KEYWORD_RECTANGULO,     
    KEYWORD_CIRCULO,       
    KEYWORD_TRIANGULO,
    NUMBER,
    COLOR_BLUE,
    COLOR_YELLOW,
    COLOR_RED,
    COLOR_GREEN,
    KEYWORD_FILL,
    KEYWORD_BORDER,
    KEYWORD_TEXT,
    STRING,
    SEMICOLON,
    ASSIGN,
    STRING_DELIMITER,
    WHITESPACE,
    END
};

//Token
typedef struct{
    enum TokensTypes type;   // Tipo
    char* value;            //valor del token
}Token;

Token getNextToken(); //Formacion y retorno de tokens
Token createToken(enum TokensTypes type, const char* value); //Creacion del token

#endif