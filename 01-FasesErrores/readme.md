# Paso 1: Preprocesador #
## Comandos ejecutados ##
- (1.a) Programa hecho
- (1.b) gcc -E hello2.c -o hello2.i
Este comando me genera un archivo hello2.i, este es el archivo fuente hello2.c pasado por el preprocesador y contiene las definiciones de la libreria "stdio.h", es decir la interfaz, tambien se deshace de los comentarios, se puede ver que el comentario que esta entre el int y main no se encuentra en el archivo hello2.i y al final de todo esta el codigo que nosotros escribimos en el archivo fuente. En conclusion en el archivo .i encontramos la inclusion de headers (stdio.h en este caso), la eliminacion de comentarios y el codigo escrito por nosotros.
- (1.c) Programa hecho  
- (1.d) Esta linea lo que hace es definir la funcion printf y los argumentos que esta recibe. Mediante esa linea se puede saber que la funcion devuelve un entero, que se la invoca mediante printf y sus argumentos, y que estos ultimos son un puntero a una cadena de caracteres donde restrict indica que 's' es el unico puntero que se va utilizar para acceder a datos, luego por ultimo, los puntos suspensivos (...) indican que la funcion acepta un variable de argumentos adicionales. En cuestion, esta linea define el tipo de la funcion (int), el nombre (printf) y sus argumentos (const char * restrict s, ...).
- (1.e) gcc -E hello3.c -o hello3.i
Las diferencias entre los archivos .c y .i de hello3 son que el archivo .c tiene unicamente el codigo que nosotros escribimos y el .i ademas de eso tiene directivas del preprocesador (lineas con #), estas lineas son generadas por el preprocesador y permiten entender el contexto y secuencia de inclusion de archivos al compilar.

# Paso 2: Compilacion #
## Comandos ejecutados ##
- (2.a) gcc -S hello3.i -o hello3.s
Al ejecutar este comando me genera un error (Expected declaration or statement at end of input) 
- (2.b) Corregi el error descrito en el punto anterior agregandole un retorno a la funcion int main (return 0) y la llave que cierra la funcion main. Ahora si con gcc -S hello4.c -o hello4.s me genero el archivo compilado hello4.s
- (2.c) El lenguaje ensamblador es un lenguaje de programacion de bajo nivel mas cercano al hardware que se escribe a partir de mnemonicos y trabaja con los registros de la cpu, es el paso previo al lenguaje maquina. El objetivo de este codigo es permitir que el codigo fuente (alto nivel) escrito por el programador pueda ser entendido luego por el hardware que trabaja mediante el codigo maquina (ceros y unos), es decir funciona como un intermediario entre lo que escribe el programador y lo que entiende la computadora.
- (2.d) gcc -c hello4.s -o hello4.o
Me genera el archivo objeto

# Paso 3: Vinculacion #
## Comandos ejecutados ##
- (3.a) gcc hello4.o -o hello4
Al ejecutar este comando me tira un error (undefined reference to 'prontf').
- (3.b) Corrijo el archivo hello4.c en hello5.c cambiando la invocacion de la funcion de 'prontf' a 'printf, luego ejecuto el comando gcc hello5.c -o hello5 y me genera el ejecutable
- (3.c) Al ejecutar el codigo me muestra lo siguiente en consola: 'La respuesta es 4200880'. Yo creo que es un bug que surge ya que si bien declaramos la variable i y le asignamos el valor entero 42, cuando usamos el formato %d para imprimir i, nunca la llamamos luego de las comillas para que se asocie el %d con i. Por lo que estuve investigando el resultado que me tira por consola es un resultado impredescible ya que al no pasarle el argumento (i), toma un valor no definido de la pila de argumentos.

# Paso 4: Correccion de bug #
## Comandos ejecutados ##
- (4.a) Corrijo hello5.c en hello6.c y compilo usando el comando gcc hello6.c -o hello6
El codigo funciona como deberia hacerlo, compila correctamente e imprime por pantalla: 'La respuesta es 42'

# Paso 5: Remocion de prototipo #
## Comandos ejecutados ##
- (5.a) Escribo hello7.c
- (5.b)
- - (i) Al compilar el archivo hello7.c primero me aparece un warning (implicit declaration of function 'printf') y luego otro en el mismo lugar (incompatible implicit declaration of built-in function 'printf').
- - (ii) Un prototipo indica de una funcion que valor retorna, como se llama, cuales son y de que tipo son los parametros que recibe. Se podria decir que es como su "firma" ya que describe todo lo mencionado anteriormente pero no muestra su contenido. Se pueden generar declarandolo arriba de la funcion main o tambien haciendo un archivo header (.h) y declarandolos alli.
- - (iii) Una declaracion implicita ocurre cuando invocas una funcion en el codigo main por ejemplo y la funcion invocada no esta previamente declarada. 
- - (iv) Tengo mis dudas con esta pregunta pero si no entendi mal y por lo que estuve investigando en internet la especificacion indica que las declaraciones implicitas no son una buena practica y que no estan bien vistas en las versiones de c99 en adelante ya que presentan un comportamiento indefinido.
- -(v) Las principales implementaciones permiten este tipo de declaraciones (implicitas) pero como se pudo ver generan warnings respecto a su uso.
- -(vi) Una funcion built-in es una funcion que no tiene la necesidad de ser definida o declarada, viene con el lenguaje o con el compilador ya integrada para poder usarla directamente.
- - (vii) Yo creo que gcc acepta el codigo de hello7.c ya que permite la declaracion implicita de funciones por razones de compatibilidad pero a la vez te notifica este tipo de declaracion a traves de warnings. No me parece que vaya contra la especificacion ya que te avisa sobre las declaraciones implicitas pero las compila ya que por ejemplo si una empresa tiene un codigo desarrollado con una version anterior a c99 y usa declaraciones implicitas no va a poder correrlo con gcc si este no permitiese ese tipo de declaraciones, por lo que me parece correcto que tire los warnings y que a la vez compile por razones de compatibilidad de versiones.

En conclusion, el codigo del archivo hello7.c tiene sus warnings debido a que se usan funciones no declaradas como printf pero en estas se permite usar la declaracion implicita la cual permite usar la funcion sin declararla formalmente gracias a que el compilador la "conoce" y puede asumir que esa funcion existe, si bien es tomado como una mala practica y se dejo de usar a partir de c99, los compiladores permiten este tipo de declaraciones para mantener la compatibilidad pero tambien arrojan los respectivos warnings por el uso de estas declaraciones.



