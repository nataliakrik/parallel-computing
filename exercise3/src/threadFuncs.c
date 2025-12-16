
#include"../libs/threads_func.h"



void init_arrays(int n , int **arr0 , int **arr1 ,int **arr2  ,int **arr3) {

    int * arr;
    *arr0 = malloc(sizeof(int)*n);
    *arr1 = malloc(sizeof(int)*n);
    *arr2 = malloc(sizeof(int)*n);
    *arr3 = malloc(sizeof(int)*n);

    if (!*arr0 || !*arr1 || !*arr2 || !*arr3) {
        printf("Allocation failed\n");
        exit(1);
    }
    arr=generateNum(4*n);
    
    for (int i = 0; i < n; i++){
        (*arr0)[i] = arr[i];
        (*arr1)[i] = arr[i+n];
        (*arr2)[i] = arr[i+(2*n)];
        (*arr3)[i] = arr[i+(3*n)];
    }
}


void* analyze_array(void* arguments) {

    thread_arg *arg = (thread_arg *)arguments;
    for (int i = 0; i < (arg->n) ; i++){
        if ((arg->array)[i] != 0){
            (*(arg->info_array))++;
        }
        
    }
    return NULL;
}

void analyze_in_sequence(int n , int *arr0 , int *arr1 ,int *arr2  ,int *arr3 ) {

    stats->info_array_0 = 0;
    stats->info_array_1 = 0;
    stats->info_array_2 = 0;
    stats->info_array_3 = 0;
    
    for (int i = 0; i < n; i++){
        if(arr0[i] != 0){
            (stats->info_array_0)++;
        }
    }
    for (int i = 0; i < n; i++){
        if(arr1[i] != 0){
            (stats->info_array_1)++;
        }
    }
    for (int i = 0; i < n; i++){
        if(arr2[i] != 0){
            (stats->info_array_2)++;
        }
    }
    for (int i = 0; i < n; i++){
        if(arr3[i] != 0){
            (stats->info_array_3)++;
        }
    }
    return ;
}