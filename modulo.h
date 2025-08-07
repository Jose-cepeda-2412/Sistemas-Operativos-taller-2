/************************************************************************
 *              Pontificia Universidad Javeriana
 *          ===========================================
 *  Autor: José Jesús Cepeda Vargas
 *  Materia: Sistemas Operativos
 *  Docente: J.Corredor, PhD
 * 
 *  Objetivo: Punteros en c 
 ************************************************************************/


#ifndef MODULO_H
#define MODULO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaracion de las funciones que se van a utilizar 

void printFunction();
float imcFuncion(float masa, float altura);
void impMatrix(float **mA, int N);
void llenarMatriz(int N, float **mA, float **mB);
float **crearMatriz(int N);
void liberarMatriz(float **mat, int N);
float **matrixMult(int N, float **mA, float **mB);


#endif