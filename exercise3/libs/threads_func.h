// This file contains all the definitions for the project
#ifndef THREADS_FUNC_H
#define THREADS_FUNC_H

#include "randNum.h"
#include <pthread.h>

#define NUM_THREADS 4


struct array_stats_s {
    long long int info_array_0;
    //char pad0[56];
    long long int info_array_1;
    //char pad1[56];
    long long int info_array_2;
    //char pad2[56];
    long long int info_array_3;
    //char pad3[56];
}array_stats;

struct array_stats_s *stats;


/**
 * @brief
 * Struct for passing arguments to the thread function
 * @param array
 * Array to analyze
 * @param n
 * Size of array
 * @param info_array
 * A pointer to the info_array data of current thread 
 */
typedef struct {
    int *array;
    int n;
    long long int *info_array
} thread_arg ;


void init_arrays(int n , int **arr0 , int **arr1 ,int **arr2  ,int **arr3);


void* analyze_array(void* arguments);


void analyze_in_sequence(int n , int *arr0 , int *arr1 ,int *arr2  ,int *arr3 );

#endif
