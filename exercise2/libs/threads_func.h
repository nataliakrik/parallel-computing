// This file contains all the definitions for the project
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <stdatomic.h> 

#define NUM_THREADS 8
#define ITERATIONS 10000000

pthread_mutex_t lock;

pthread_rwlock_t rwlock;

// Global variable
long counter;

/**
 * @brief
 * Lock mutex and increases counter then unlocks
 */
void* increment_mutex(void* arg);

/**
 * @brief
 * writer locks and increases counter then unlocks
 */
void* increment_rwlock(void* arg);


/**
 * @brief
 * atomic locks and increases counter then unlocks
 */
void* increment_atomic(void* arg);