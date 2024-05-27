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
  - (i) Al compilar el archivo hello7.c primero me aparece un warning (implicit declaration of function 'printf') y luego otro en el mismo lugar (incompatible implicit declaration of built-in function 'printf').
  - (ii) Un prototipo indica de una funcion que valor retorna, como se llama, cuales son y de que tipo son los parametros que recibe. Se podria decir que es como su "firma" ya que describe todo lo mencionado anteriormente pero no muestra su contenido. Se pueden generar declarandolo arriba de la funcion main o tambien haciendo un archivo header (.h) y declarandolos alli.
  - (iii) Una declaracion implicita ocurre cuando invocas una funcion en el codigo main por ejemplo y la funcion invocada no esta previamente declarada. 
  - (iv) Tengo mis dudas con esta pregunta pero si no entendi mal y por lo que estuve investigando en internet la especificacion indica que las declaraciones implicitas no son una buena practica y que no estan bien vistas en las versiones de c99 en adelante ya que presentan un comportamiento indefinido.
  - (v) Las principales implementaciones permiten este tipo de declaraciones (implicitas) pero como se pudo ver generan warnings respecto a su uso.
  - (vi) Una funcion built-in es una funcion que no tiene la necesidad de ser definida o declarada, viene con el lenguaje o con el compilador ya integrada para poder usarla directamente.
  - (vii) Yo creo que gcc acepta el codigo de hello7.c ya que permite la declaracion implicita de funciones por razones de compatibilidad pero a la vez te notifica este tipo de declaracion a traves de warnings. No me parece que vaya contra la especificacion ya que te avisa sobre las declaraciones implicitas pero las compila ya que por ejemplo si una empresa tiene un codigo desarrollado con una version anterior a c99 y usa declaraciones implicitas no va a poder correrlo con gcc si este no permitiese ese tipo de declaraciones, por lo que me parece correcto que tire los warnings y que a la vez compile por razones de compatibilidad de versiones.

En conclusion, el codigo del archivo hello7.c tiene sus warnings debido a que se usan funciones no declaradas como printf pero en estas se permite usar la declaracion implicita la cual permite usar la funcion sin declararla formalmente gracias a que el compilador la "conoce" y puede asumir que esa funcion existe, si bien es tomado como una mala practica y se dejo de usar a partir de c99, los compiladores permiten este tipo de declaraciones para mantener la compatibilidad pero tambien arrojan los respectivos warnings por el uso de estas declaraciones.

# Paso 6: Compilacion separada: Contratos y Modulos #
## Comandos ejecutados ##
- (6.a) Escribo hello8.c y studio1.c
- (6.b) Luego de investigar, ejecuto el comando gcc -o hello8 studio1.c hello8.c para compilar los archivos y generar el ejecutable. Luego de probarlo, me muestra algunos warnings y me genera la salida: 'La respuesta es 42'.
- (6.c) Si agregamos o eliminamos argumentos en la invocacion de prontf nos saltaria un error ya que prontf esta definida como una funcion que acepta 2 cosas, const char* s y int i. Por lo que si luego la invocamos con un argumento mas o uno menos este no seguiria la misma "formula" con la que declaramos la funcion y no corresponderia a su forma de uso, por lo que logicamente daria un error.
- (6.d) 
- - (i) Escribo contrato studio.h
- - (ii) Escribo hello9.c
- - (iii) Escribo studio2.c
- - (iv) La ventaja de incluir el contrato en los clientes y en el proveedor se da en que hay una relacion entre cliente, proveedor y un contrato en donde el cliente seria hello9.c, el proveedor seria studio2.c y de por medio entre ellos hay un contrato que es studio.h. En archivo del proveedor (studio2.c) se desarrolla la funcion prontf, luego en el contrato se define el prototipo de la funcion y en el cliente (hello9.c) se usa esa funcion prontf. De esta manera cuando se requiere cambiar la implementacion de la funcion se puede cambiar desde studio2.c sin afectar al cliente, es decir, hello9.c que solo utiliza la funcion mediante el contrato studio.h. Esto facilita el desarrollo de codigo ya que cada cosa mantiene su funcionalidad por separado y permite minimizar los errores y en caso de haberlos que se solucionen de una manera mas eficaz y eficiente.

# Credito extra #
Las bibliotecas son archivos que contienen un conjunto de funciones y definiciones, estas pueden ser estaticas, es decir que el codigo de las funciones usadas se copia en el ejecutable durante la fase de vinculacion o dinamicas, es decir que las funciones se cargan en tiempo de ejecucion (En este caso varios programas pueden compartir la misma biblioteca). Estas se pueden distribuir pero se necesita tambien del archivo .h correspondiente que contiene las declaraciones de los prototipos de las funciones de la biblioteca, con estos dos archivos (biblioteca y header) se puede distribuir correctamente la biblioteca para que sea usada en otros archivos. Las bibliotecas en C son portables siempre y cuando se adhieran al estandar de C y no utilicen dependencias especificas del sistema en el que se desarrolla, siguiendo lo mencionado anteriormente se podria utilizar una misma biblioteca en diferentes plataformas. Algunas de sus ventajas son la reutilizacion de codigo ya que si es necesario se pueden usar en varios archivos las funciones que ya estan diseñadas y definidas en las bibliotecas, permite actualizar o corregir codigo de mejor manera debido a que todas las funciones ya estan diseñadas en un mismo archivo y en el caso de que se utilicen bibliotecas dinamicas, al utilizar el codigo de las bibliotecas en el tiempo de ejecucion, hace mas liviano al archivo ejecutable que no tiene la necesidad de copiar en él la biblioteca. Y algunas de sus desventajas son que al usar bibliotecas se requieren de mas dependencias en el entorno para compilar archivos, en el caso de las bibliotecas dinamicas al copiar y pegar cada biblioteca en los ejecutables en el proceso de vinculacion esto hace que el ejecutable quede mas pesado y por otro lado en el caso de las bibliotecas dinamicas, al cargar las bibliotecas en la fase de ejecucion se necesita de un mejor rendimiento y a la vez si se quiere distribuir tambien se necesita que la entidad a la que se la distribuimos tambien posea la biblioteca dinamica para poder ejecutar el programa correctamente (Debe tener todas las respectivas dependencias).
En mi caso voy a desarrollar la biblioteca estatica de studio2.c ya que al no tener una gran cantidad de funciones definidas no me preocupa que el ejecutable quede mas pesado. Creo la libreria estatica con el comando gcc -c studio2.c -o studio2.o para obtener el archivo objeto de la implementacion y luego pongo ar rcs studio2.lib studio2.o para crear la biblioteca. Luego para la compilacion del archivo .c con la biblioteca ejecuto el comando gcc hello9.c studio2.lib -o hello9. Siguiendo los pasos anteriores pude compilar correctamente el ejecutable hello9 que despues de ejecutarlo me tira el mensaje 'La respuesta es 42', por lo que compilo y funciono correctamente.



