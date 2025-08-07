#/************************************************************************
#*              Pontificia Universidad Javeriana
#*          ===========================================
#*  Autor: José Jesús Cepeda Vargas
#*  Materia: Sistemas Operativos
#*  Docente: J.Corredor, PhD
#* 
#*  Objetivo: Punteros en c 
#************************************************************************/

# Variables
CC = gcc #definir el compilador
CFLAGS = -Wall -std=c11 #indica que se usara c11
OBJ = prog01.o modulo.o #lista de archivos que se necesitan para construir el programa

#para escribir solo make
all: programa

#crea ejecutable programa
programa: $(OBJ)
	$(CC) $(CFLAGS) -o programa $(OBJ)

#para compilar prog01.c a prog01.o
prog01.o: prog01.c modulo.h
	$(CC) $(CFLAGS) -c prog01.c

#para compilar modulo.o
modulo.o: modulo.c modulo.h
	$(CC) $(CFLAGS) -c modulo.c

# borra los archivos generados 
.PHONY: clean
clean:
	rm -f *.o programa
