/* File:     randNum.c
 *
 * Purpose:  C program for generating n random numbers in a given range.
 *
 * Compile: gcc randNum.c  "along with the other files"
 *
 * Library: randNum.h 
 * local file should be included in the source file
 */
#include "../libs/randNum.h"

int *generateNum(int n) {
    srand(time(NULL));
    int num , *arr ;

    arr = (int *)malloc(n * sizeof(int));
    if (arr==NULL){
        printf("Allocation Failed");
        exit(0);
    }

    // Loop that generate random numbers
    for (int i = 0; i < n; i++) {
        num = rand() % (MAX - MIN + 1) + MIN;
        arr[i]= num;
        //printf("%d * %d ",sign , num);
    }
    printf("\n");
    return arr;
}