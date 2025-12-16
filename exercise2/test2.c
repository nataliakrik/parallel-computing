#include"libs/threads_func.h"

long long monotonic_ns() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000000000LL + ts.tv_nsec;
}


int main(){

    // INITIALIZATION
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);
    counter = 0;

    // USING MUTEX LOCKS
    long long t1 = monotonic_ns();
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, increment_mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    long long t2 = monotonic_ns();

    pthread_mutex_destroy(&lock);
    

    counter = 0;
    // USING READ-WRITE
    long long t3 = monotonic_ns();
    pthread_rwlock_init(&rwlock, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, increment_rwlock, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    long long t4 = monotonic_ns();

    pthread_rwlock_destroy(&rwlock);
    

    counter = 0;
    // USING ATOMIC LOCKS
    long long t5 = monotonic_ns();
    for (int i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, increment_atomic, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    long long t6 = monotonic_ns();


    
    printf("\nMUTEX locks:\t\t%lld ns\n", (t2 - t1));
    printf("READ-WRITE LOCKS:\t%lld ns\n", (t4 - t3));
    printf("Atomic Lock:\t\t%lld ns\n", (t6 - t5));
    printf("\n");

    return 0;

}