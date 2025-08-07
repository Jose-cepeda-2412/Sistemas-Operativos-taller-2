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

    if(argc < 4){
        printf("$./programa valor1(altura/m) valor2(masa/kg) valor3(tam matriz)\n");
        exit(0);
        }
    
    printFunction();
    
    //se hace la conversion de los datos
    float altura = (float)atof(argv[1]);
    float masacorporal = (float)atof(argv[2]);
    int N = (int)atof(argv[3]);
    
    float valorIMC = imcFuncion(masacorporal, altura);

    printf("El indice de masa corporal es %f\n", valorIMC);
    printf("***********************************\n\n\n");
    printf("***********************************\n");
    printf("*             Matrices          *\n");
    printf("                                 \n");
    printf("***********************************\n");
    
   float **mA = crearMatriz(N);
   float **mB = crearMatriz(N);

   llenarMatriz(N, mA, mB);

   printf("Matriz a: \n");
   impMatrix(mA, N);

   printf("Matriz b: \n");
   impMatrix(mB, N);


   float **mC = matrixMult(N, mA, mB);
   printf("Matriz multiplicada: \n");
   impMatrix(mC, N);

   liberarMatriz(mA, N);
   liberarMatriz(mB, N);
   liberarMatriz(mC, N);
    
    return 0;
 }
