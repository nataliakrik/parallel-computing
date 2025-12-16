// This file contains all the definitions for the project
#include "randNum.h"
#include <pthread.h>

#define NUM_THREADS 8


/**
 * @brief
 * Struct for passing arguments to the thread function
 * @param X
 * Polynomial X
 * @param Y
 * Polynomial Y
 * @param n
 * Polynomial degree
 * @param Result
 * Long int that will store results
 * @param start
 * The lowest degree of the X polynomial that is assigned to the thread
 * @param stop
 * The highest degree of the X polynomial that is assigned to the thread
 */
typedef struct {
    int *X;
    int *Y;
    long int *Result;
    int n;
    int start;
    int stop;
}thread_arg;


/**
 * @brief 
 * It takes 2 pointer of int arrays as an input and returns the multiplying result of the 2 arrays
 * @param argument
 * thread_arg data structure
 */
void* threadsWork(void *argument);



/**
 * @brief
 * Prints the  polynomials
 * @param X
 * Polynomial X
 * @param Y
 * Polynomial Y
 * @param n
 * Polynomial degree
 */
void print_polynomials(int *X , int *Y , int n);

/**
 * @brief
 * The result of multiplying 2 polynomials calculated without threads
 * @param X
 * Polynomial X
 * @param Y
 * Polynomial Y
 * @param C
 * Long int that will store results
 * @param n
 * Degree of polynomials
 */
void polynomial_multiply(int *X, int *Y, long *C, int n);

/**
 * @brief
 * Searches for an error between the 2 arrays
 * @param n
 * Size of arrays
 * @param R1
 * Array 1
 * @param R2
 * Array 2
 * @returns
 * {1-if arrays are not compatible  , 0 - if arrays are the same}
 */
int check_results( int n , long *R1, long *R2);