#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *thread_function(void *arg)
{
    int n = 0;
    long int r = random() % 100;
    printf("Start Thread %lu\n", r);
    while (n < 3)
    {
        sleep(1);
        n++;
        printf("inside Thread %lu %d\n", r, n);
    }
    printf("End Thread %lu\n", r);
    return (void *)r;
}

int main()
{
    char line[100];
    int n_threads;
    printf("How many threads: ");
    fgets(line, 100, stdin);
    sscanf(line, "%d", &n_threads);
    pthread_t *thread_id = malloc(sizeof(pthread_t) * n_threads);

    int i = 0;
    while (i < n_threads)
    {
        pthread_create(&thread_id[i], NULL, thread_function, NULL);
        i++;
    };
    for (i = 0; i < n_threads; i++)
        pthread_join(thread_id[i], NULL);
    // printf("Carregue em enter para terminar\n");
    // fgets(line, 100, stdin);
    exit(0);
}