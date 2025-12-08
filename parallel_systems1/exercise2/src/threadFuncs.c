
#include"../libs/threads_func.h"


void* increment_mutex(void* arg) {
    // To avoid the warning
    (void)arg; 
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}



void* increment_rwlock(void* arg) {
    (void)arg; 
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_rwlock_wrlock(&rwlock);
        counter++;
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}



void* increment_atomic(void *arg){
    (void)arg; 
    for (int i = 0; i < ITERATIONS; i++) {
        __atomic_add_fetch(&counter, 1, __ATOMIC_SEQ_CST);
    }
    return NULL;

}