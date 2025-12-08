#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

long long int total_points = 0;
long long int points_in_circle = 0;
pthread_mutex_t lock;

void *monte_carlo(void *arg) {
    long long int points = *((long long int*)arg);
    long long int local_points_in_circle = 0;

    srand(time(NULL)); // Seed for random number generation

    for (long long int i = 0; i < points; i++) {
        double x = (double)rand() / RAND_MAX * 2 - 1;
        double y = (double)rand() / RAND_MAX * 2 - 1;

        double distance_squared = x * x + y * y;

        if (distance_squared <= 1) {
            local_points_in_circle++;
        }
    }

    pthread_mutex_lock(&lock);
    points_in_circle += local_points_in_circle;
    total_points += points;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <total_points> <threads>\n", argv[0]);
        return -1;
    }

    long long int total_points = atoll(argv[1]);
    int num_threads = atoi(argv[2]);
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    long long int points_per_thread = total_points / num_threads;

    clock_t start_serial = clock();
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, monte_carlo, &points_per_thread);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    clock_t end_serial = clock();

    double pi_estimate = 4 * (double)points_in_circle / total_points;

    printf("Serial execution time: %f seconds\n", (double)(end_serial - start_serial) / CLOCKS_PER_SEC);
    printf("Estimated value of pi: %f\n", pi_estimate);

    pthread_mutex_destroy(&lock);
    return 0;
}
