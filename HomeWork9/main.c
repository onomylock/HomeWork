#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int num = 0;

void* sum_loop(void *sum)
{
    for(int i = 0; i < 1000000; i++)
    {
        int tmp = num;
        tmp++;
        num = tmp;
    }    
    return NULL;
}

int main(void)
{    
    pthread_t thing[12];

    for(int i = 0; i < 12; i++)
    {
        pthread_create (&thing[i], NULL, sum_loop, NULL);    
    }

    for(int i = 0; i < 12; i++)
    {
        pthread_join (thing[i], NULL);
    }
    
    printf("sum = %d\n", num);

    exit(0);
}