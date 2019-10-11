#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *thread1(void *arg)
{
    while (1) {
    
    }
}

void *thread2(void *arg)
{
    while (1) {
    
    }
}

int main()
{
    pthread_t pid1, pid2;
    pthread_create(&pid1, NULL, thread1, NULL);
    pthread_create(&pid2, NULL, thread2, NULL);
    while (1) {
    
    }

    return 0;
}
