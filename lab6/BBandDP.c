#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5
#define N 5


int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full;
pthread_mutex_t mutex;


sem_t forks[N];


void *producer(void *arg)
{
    int item;
    for (int i = 1; i <= 10; i++)
    {
        item = i;

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Produced: %d at %d\n", item, in);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(1);
    }
    return NULL;
}


void *consumer(void *arg)
{
    int item;
    for (int i = 1; i <= 10; i++)
    {

        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("Consumed: %d from %d\n", item, out);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1);
    }
    return NULL;
}


void *philosopher(void *arg)
{
    int id = *(int *)arg;

    while (1)
    {
        printf("Philosopher %d is Thinking\n", id);
        sleep(1);

        sem_wait(&forks[id]);
        sem_wait(&forks[(id + 1) % N]);

        printf("Philosopher %d is Eating\n", id);
        sleep(1);

        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);
    }
    return NULL;
}


int main()
{
    int choice;
    while(1){

    printf("\n1. Bounded Buffer\n2. Dining Philosophers\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        pthread_t p, c;

        sem_init(&empty, 0, SIZE);
        sem_init(&full, 0, 0);
        pthread_mutex_init(&mutex, NULL);

        pthread_create(&p, NULL, producer, NULL);
        pthread_create(&c, NULL, consumer, NULL);

        pthread_join(p, NULL);
        pthread_join(c, NULL);
    }

    else if (choice == 2)
    {
        pthread_t ph[N];
        int id[N];

        for (int i = 0; i < N; i++)
            sem_init(&forks[i], 0, 1);

        for (int i = 0; i < N; i++)
        {
            id[i] = i;
            pthread_create(&ph[i], NULL, philosopher, &id[i]);
        }

        for (int i = 0; i < N; i++)
            pthread_join(ph[i], NULL);
    }

    else
    {
        printf("Invalid choice\n");
    }
    }
    return 0;
}
