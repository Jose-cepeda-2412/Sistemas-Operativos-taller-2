//implementación de funciones (como funcionan)
/************************************************************************
 *              Pontificia Universidad Javeriana
 *          ===========================================
 *  Autor: José Jesús Cepeda Vargas
 *  Materia: Sistemas Operativos
 *  Docente: J.Corredor, PhD
 * 
 *  Objetivo: Punteros en c 
 ************************************************************************/

#include "modulo.h"

//imprime "Calculadora de masa corporal"
void printFunction(){
    
        printf("**************************************\n");
        printf("*     Calculadora de Masa Corporal    *\n");
        printf("**************************************\n");
        
}

//calcula y devuelve el IMC 
float imcFuncion(float masa, float altura){
        float IMC = masa / (altura * altura);
        return IMC;
}

//imprime una matriz
void impMatrix(float **mA, int N){
        for(int i = 0; i < N; i++){
           for(int j = 0; j < N; j++){
                printf (" %f ", mA[i][j]);
           }
           printf(" \n");
        }
        printf(" \n");
}

//crea una matriz, reserva el espacio para que sea una matriz dinamica
float **crearMatriz(int N) {

    float **Matriz = malloc(N * sizeof(float *));

    for (int i = 0; i < N; i++) {
        Matriz[i] = malloc(N * sizeof(float));   
    }

    return Matriz;
}

//se encarga de liberar la memoria que se uso para las matrices
void liberarMatriz(float **mat, int N){
    for(int i = 0; i < N; i++){
        free(mat[i]);
    }
    free (mat);
}

//llena la matriz a y b con numeros aleatorios
void llenarMatriz(int N, float **mA, float **mB){
    srand(time (NULL));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mA [i][j] = (rand() % 100) * 0.121f; 
            mB [i][j] = rand() % 100; 
        }
    }
}

//multiplica la matriz a y b, guarda el resultado en la matriz c
float **matrixMult(int N, float **mA, float **mB){
    float **mC = crearMatriz(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mC[i][j] = 0.0f;
            for(int k = 0; k < N; k++){
                mC [i][j] += mA[i][k] * mB[k][j];
            }
        }
    }
    return mC;
}