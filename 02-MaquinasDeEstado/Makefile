# Makefile TP13

main: main.o histograma-1-enum-switch.o Graficador.o
	gcc main.o histograma-1-enum-switch.o Graficador.o -o main

main.o: main.c histograma.h Graficador.h
	gcc -c main.c -o main.o

histograma-1-enum-switch.o: histograma-1-enum-switch.c histograma.h
	gcc -c histograma-1-enum-switch.c -o histograma-1-enum-switch.o

Graficador.o: Graficador.c Graficador.h
	gcc -c Graficador.c -o Graficador.o

# Regla para limpiar los archivos generados
.PHONY: clean
clean:
	rm -f histograma-1-enum-switch.o Graficador.o main.o main.exe