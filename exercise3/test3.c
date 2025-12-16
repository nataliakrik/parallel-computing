#include"libs/threads_func.h"


long long monotonic_ns() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000000LL + ts.tv_nsec;
}


int main(int argc , char *argv[]){
    // INPUT
    if (argc<2){
        printf("Error wrong input\nTry ./bin/test \"size_of_array\"\n");
        exit(0);
    }
    int n=atoi(argv[1]);

    // INITIALIZATION
    int *arr0=NULL , *arr1=NULL , *arr2=NULL  , *arr3=NULL;
    pthread_t threads[NUM_THREADS];
    thread_arg arguments[NUM_THREADS];
    //pthread_mutex_init(&lock, NULL);
    
    stats = malloc(sizeof(array_stats));
    if (!stats) {
        exit(1);
    }
    stats->info_array_0 = 0;
    stats->info_array_1 = 0;
    stats->info_array_2 = 0;
    stats->info_array_3 = 0;

    
    // INITIALIZATION of the arrays
    long long t1 = monotonic_ns();
    init_arrays(n ,&arr0 ,&arr1 , &arr2 , &arr3);
    long long t2 = monotonic_ns();


    // CALCULATION WITH THREADS
    long long t3 = monotonic_ns();
    // THREAD 0
    arguments[0].array = arr0;
    arguments[0].n = n;
    arguments[0].info_array = &(stats->info_array_0);
    pthread_create(&threads[0] , NULL , analyze_array , &(arguments[0]));

    // THREAD 1
    arguments[1].array = arr1;
    arguments[1].n = n;
    arguments[1].info_array = &(stats->info_array_1);
    pthread_create(&threads[1] , NULL , analyze_array , &(arguments[1]));
    
    // THREAD 2
    arguments[2].array = arr2;
    arguments[2].n = n;
    arguments[2].info_array = &(stats->info_array_2);
    pthread_create(&threads[2] , NULL , analyze_array , &(arguments[2]));
    
    // THREAD 3
    arguments[3].array = arr3;
    arguments[3].n = n;
    arguments[3].info_array = &(stats->info_array_3);
    pthread_create(&threads[3] , NULL , analyze_array , &(arguments[3]));

    for (int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i] , NULL);
    }
    long long t4 = monotonic_ns();
    

    // CALCULATION IN A SEQUENCE WITHOUT THREADS
    long long t5 = monotonic_ns();
    analyze_in_sequence(n ,arr0 ,arr1 , arr2 , arr3);
    long long t6 = monotonic_ns();

    
    printf("\nInitialization:\t%lld ns\n", (t2 - t1));
    printf("Parallel:\t%lld ns\n", (t4 - t3));
    printf("Sequential:\t%lld ns\n", (t6 - t5));
    printf("\n");

    // FREE UP ALLOCATED SPACE
    free(stats);
    free(arr0);
    free(arr1);
    free(arr2);
    free(arr3);
    return 0;

}



///// print arrays //
/*

    printf("Count of : %lld\n" , stats->info_array_0);
    printf("Count of : %lld\n" , stats->info_array_1);
    printf("Count of : %lld\n" , stats->info_array_2);
    printf("Count of : %lld\n" , stats->info_array_3);


    for (int i = 0; i < NUM_THREADS; i++)
    {
        printf("Count of : %lld\n" , *(arguments[i].info_array));
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d  " , arr0[i]);
    }

    printf("\n\n");
    for (int i = 0; i < n; i++){
        printf("%d  " , arr1[i]);
    }

    printf("\n\n");
    for (int i = 0; i < n; i++){
        printf("%d  " , arr2[i]);
    }

    printf("\n\n");
    for (int i = 0; i < n; i++){
        printf("%d  " , arr3[i]);
    }
*/