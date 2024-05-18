## Paso 1: Preprocesador ##
# comandos ejecutados #
- (1.a) Programa hecho
- (1.b) gcc -E hello2.c -o hello2.i
Este comando me genera un archivo hello2.i, este es el archivo fuente hello2.c pasado por el preprocesador y contiene las definiciones de la libreria "stdio.h", es decir la interfaz, tambien se deshace de los comentarios, se puede ver que el comentario que esta entre el int y main no se encuentra en el archivo hello2.i y al final de todo esta el codigo que nosotros escribimos en el archivo fuente. En conclusion en el archivo .i encontramos la inclusion de headers (stdio.h en este caso), la eliminacion de comentarios y el codigo escrito por nosotros.
- (1.c) Programa hecho  
- (1.d) Esta linea lo que hace es definir la funcion printf y los argumentos que esta recibe. Mediante esa linea se puede saber que la funcion devuelve un entero, que se la invoca mediante printf y sus argumentos, y que estos ultimos son un puntero a una cadena de caracteres donde restrict indica que 's' es el unico puntero que se va utilizar para acceder a datos, luego por ultimo, los puntos suspensivos (...) indican que la funcion acepta un variable de argumentos adicionales. En cuestion, esta linea define el tipo de la funcion (int), el nombre (printf) y sus argumentos (const char * restrict s, ...).
- (1.e) gcc -E hello3.c -o hello3.i
Las diferencias entre los archivos .c y .i de hello3 son que el archivo .c tiene unicamente el codigo que nosotros escribimos y el .i ademas de eso tiene directivas del preprocesador (lineas con #), estas lineas son generadas por el preprocesador y permiten entender el contexto y secuencia de inclusion de archivos al compilar. 



