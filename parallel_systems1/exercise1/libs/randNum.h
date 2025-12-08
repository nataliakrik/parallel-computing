#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declares the range of the generated numbers 
#define MIN 1
#define MAX 9

/**
 * @brief
 * Generates random numbers to the range {MIN , MAX} using time as a seed for the rand function
 * @param n
 * Defines how many numbers should be generated
 * @returns arr
 * Returns an integer array-size of n integers
 */
int *generateNum(int n);