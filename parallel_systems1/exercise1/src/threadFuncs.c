
#include"../libs/threads_func.h"


void* threadsWork(void *argument) {

    thread_arg *arg = (thread_arg * )argument;
    
    for (int i = arg->start; i < arg->stop; i++){
        for (int j = 0; j < arg->n; j++) {            
            (arg->Result)[i + j] += (long)(arg->X)[i] * (long)(arg->Y)[j];
        }
    }
    return NULL;
}


void polynomial_multiply(int *X, int *Y, long *C, int n) {

    for (int i = 0; i < 2*n; i++)
        C[i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i + j] += (long)X[i] * (long)Y[j];
        }
    }
}


void print_polynomials(int *X , int *Y , int n){
    
    printf("\n| X :");
    for (int i = 0; i < n; i++){
        printf("\tX%d:%d |",i , X[i]);
    }

    printf("\n| Y :");
    for (int i = 0; i < n; i++){
        printf("\tY%d:%d |",i , Y[i]);
    }
    printf("\n");

}


int check_results( int n , long *R1, long *R2) {
    int true = 0;
    for (int i = 0; i < 2 *n; i++) {
        if(R1[i] != R2[i]){
            true = 1;
            return true;
        }
    }
    return true;
}