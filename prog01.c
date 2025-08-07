//programa principal main y llamado a funciones, incluir modulo.h
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

 int main(int argc, char* argv[]){

    //verifica que se pasen la cantidad de datos necesarias para que funcione el programa
    if(argc < 4){
        printf("$./programa valor1(altura/m) valor2(masa/kg) valor3(tam matriz)\n");
        exit(0);
        }
    //inmprime la funcion de calculadora de IMC
    printFunction();
    
    //se hace la conversion de los datos
    float altura = (float)atof(argv[1]);
    float masacorporal = (float)atof(argv[2]);
    int N = (int)atof(argv[3]);
    //se calcula el IMC
    float valorIMC = imcFuncion(masacorporal, altura);
    //se muestra el indice de masa corporal
    printf("El indice de masa corporal es %f\n", valorIMC);
    //se imprime el mensaje matrices para empezar la logica de la parte de las matrices
    printf("***********************************\n\n\n");
    printf("***********************************\n");
    printf("*             Matrices          *\n");
    printf("***********************************\n");
    //se crean las matrices mA y mB
   float **mA = crearMatriz(N);
   float **mB = crearMatriz(N);
   //se llama la funcion llenarMatriz y se pasa por parametos el tamaño y las dos matrices
   //para llenarlas 
   llenarMatriz(N, mA, mB);
    //se muestra la matriz a
   printf("Matriz a: \n");
   impMatrix(mA, N);
    //se muestra la matriz b
   printf("Matriz b: \n");
   impMatrix(mB, N);

    //se calcula la multiplicacion de la matriz a y b, el resultado se guarda en la matriz c 
   float **mC = matrixMult(N, mA, mB);
   printf("Matriz multiplicada: \n");
   impMatrix(mC, N);

   //se libera la memoria reservada para las 3 matrices dinamicas
   liberarMatriz(mA, N);
   liberarMatriz(mB, N);
   liberarMatriz(mC, N);
    
    return 0;
 }