#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int *rand_num_array;

#define LIMIT 100000000

void *n_mult(void *arg)
{
    int n = *(int *)arg;
    // printf("n = %d\n", n);
    int *c = malloc(sizeof(int));
    *c = 0;
    for (int i = 0; i < LIMIT; i++)
    {
        if (rand_num_array[i] % n == 0)
            (*c)++;
    }
    return (void *)c;
}

int main()
{

    rand_num_array = calloc(LIMIT, sizeof(int));
    int n[5] = {2, 3, 5, 7, 11};
    pthread_t tid[5];

    for (int i = 0; i < LIMIT; i++)
    {
        rand_num_array[i] = random();
    }
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        // printf("%d\n", *(n + i));
        pthread_create(&tid[i], NULL, n_mult, (void *)(n + i));
    }

    for (int i = 0; i < 5; i++)
    {
        int *c;
        pthread_join(tid[i], (void *)&c);
        printf("%d ", *(int *)c);
    }
    printf("\n");

    exit(0);
}