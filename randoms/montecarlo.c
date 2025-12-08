#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define RAND_NUM 7
#define NUM_THREADS 4
pthread_mutex_t lock;

void *monte_carlo(void *arg);

int main() {

    int num_threads = 4;
    pthread_t threads[NUM_THREADS];

    int passing_argument=0;

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, monte_carlo, (void *)&threads[i]);
    }
    /*
    double return_argument;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], (void*)&return_argument);
        printf("random number : %lf  in thread number : %d \n" , return_argument , i+1 );
    }
    */

    pthread_exit(NULL);
    return 0;
}

void *monte_carlo(void *threadid) {
   long tid;
   tid = (long)threadid;
   printf("Hello World! Thread ID, %d\n", tid);
   pthread_exit(NULL);
}
