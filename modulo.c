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

//imprime una matriz, la que se pase por parametro
void impMatrix(float **mA, int N){
    //se recorren filas y columnas para poder imprimir la matriz
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
    //se crea la matriz dinamica
    float **Matriz = malloc(N * sizeof(float *));
    //se inicializa la matriz dinamica
    for (int i = 0; i < N; i++) {
        Matriz[i] = malloc(N * sizeof(float));   
    }
    //se retorna la matriz
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
    //se recorren las filas y columnas para poderlas llenar de forma aleatoria
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mA [i][j] = (rand() % 100) * 0.121f; 
            mB [i][j] = rand() % 100; 
        }
    }
}

//multiplica la matriz a y b, guarda el resultado en la matriz c
float **matrixMult(int N, float **mA, float **mB){
    float **mC = crearMatriz(N);//se crea la matriz c para guardar el resultado
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            mC[i][j] = 0.0f; //se inicializa la matriz c en 0
            for(int k = 0; k < N; k++){
                mC [i][j] += mA[i][k] * mB[k][j];
            }
        }
    }
    return mC;//se retorna la matriz c
}