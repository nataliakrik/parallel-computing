#include"libs/threads_func.h"

// Used to calculate time
long long monotonic_ns() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000000LL + ts.tv_nsec;
}

int main(int argc, char *argv[]){
    // Get input
    if (argc<2){
        printf("Error wrong input\nTry ./bin/test \"polynomial_degree\"\n");
        exit(0);
    }
    int n=atoi(argv[1]);

    // INITIALIZATION
    int *X , *Y , *arr ;
    long int *Result;
    // number of factors that will be assigned to each thread
    int splits = n / NUM_THREADS;
    // Thread array
    pthread_t *threads;
    // Structure to pass arguments to thread function
    thread_arg *arg;

    // ALLOCATIONS
    X = (int *)malloc(sizeof(int)*n);   // X polynomial
    if (X==NULL){
        printf("X Allocation Failed");
        exit(0);
    }

    Y = (int *)malloc(sizeof(int)*n);   // Y polynomial
    if (Y==NULL){
        printf("Y Allocation Failed");
        exit(0);
    }

    Result = (long int *)malloc(sizeof(long int)*2*n);  // Array to store result
    if (Result==NULL){
        printf("Result Allocation Failed");
        exit(0);
    }

    threads = (pthread_t *)malloc(sizeof(pthread_t)* NUM_THREADS);   // Thread array
    if (threads == NULL){
        printf("threads Allocation Failed");
        exit(0);
    }
    
    arg = (thread_arg *)malloc(sizeof(thread_arg )* NUM_THREADS);   // Thread structure
    if (arg == NULL){
        printf("arg Allocation Failed");
        exit(0);
    }


    long long t1 = monotonic_ns();
    // Fill polynomials with random numbers
    arr=generateNum(2*n);
    for (int i = 0; i < n; i++){
        X[i]=arr[i];
        Y[i]=arr[i+n];
    }
    long long t2 = monotonic_ns();

    
    
    // SEQUENCIAL calculation without threads
    long long t3 = monotonic_ns();
    polynomial_multiply(X , Y , Result , n);
    long long t4 = monotonic_ns();
    
    
    // THREADS Calculation 
    long long t5 = monotonic_ns();
    for (int i = 0; i < NUM_THREADS; i++){
        (arg[i]).X = X;
        (arg[i]).Y = Y;
        (arg[i]).n = n;
        (arg[i]).Result = (long int *)calloc(2*n ,sizeof(long int));
        (arg[i]).start = i * splits;
        (arg[i]).stop = (i+1)* splits;
        if((i == NUM_THREADS-1) ){
            (arg[i]).stop = n;
        }
        pthread_create(&threads[i] , NULL , threadsWork , &(arg[i]));
    }

    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i] , NULL);
    }
    long long t6 = monotonic_ns();


    // MERGE RESULTS from all the threads into the result array of the first thread
    for (int i = 0; i < 2*n-1; i++){
        for (int j = 1; j < NUM_THREADS; j++){
            arg[0].Result[i] += arg[j].Result[i];
        }
    }

    // CHECK RESULTS from both calculations
    int i=check_results(n , Result , arg[0].Result);
    if(i==0)
        printf("\nThe arrays contain the same data\n");
    else
        printf("\nThe arrays are different\n");

    
    printf("Execution Time\nInitialization:   %lld ns\n", (t2 - t1));
    printf("\nSequential:\t%lld ns\n", (t4 - t3));
    printf("Parallel:\t%lld ns\n", (t6 - t5));
    printf("\n");

    // FREE UP allocated space
    for (int j = 0; j < NUM_THREADS; j++){
        free(arg[j].Result);
    }
    free(arg);
    free(threads);
    free(X);
    free(Y);

    return 0;
}