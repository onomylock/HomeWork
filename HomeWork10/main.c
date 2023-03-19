#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex;
int shops_goods[5], flag = 1;
// struct Products
// {
//     int shops_goods[5], buyers_num;
// };


void* shopping(void *arg);
void* loader(void *arg);

int main(void)
{
    //int shops_quantity[5], buyers[3];
    //struct Products products;
    pthread_t buyers_thread[3], loader_thread;
    int status, status_end, index;

    for(int i = 0; i < 5; i++)
    {
        shops_goods[i] = 50 + rand()%100;     
        printf("****SHOP NO.%d. GOODS = %d****\n", i+1, shops_goods[i]);           
    }

    for(int i = 0; i < 3; i++)
    {
        //products.buyers_goods[i] = 50 + rand()%200;
        status = pthread_create(&buyers_thread[i], NULL, shopping, NULL);
        //index++;
        if (status != 0) 
        {
            printf("main error: can't create thread, status = %d\n", status);
            exit(status);
        }
    }
    pthread_create(&loader_thread, NULL, loader, NULL);
    if (status != 0) 
    {
        printf("main error: can't create thread, status = %d\n", status);
        exit(-1);
    }

    for(int i = 0; i < 3; i++)
    {
        status = pthread_join(buyers_thread[i], (void**)&status_end);
        if (status != EXIT_SUCCESS) 
        {
            printf("main error: can't join thread, status = %d\n", status);
            exit(status);
        }
    }
    //flag = 0;
    status = pthread_join(loader_thread, (void**)&status_end);
    if (status != EXIT_SUCCESS) 
    {
        printf("main error: can't join thread, status = %d\n", status);
        exit(status);
    }

    exit(EXIT_SUCCESS);
}

void* shopping(void *arg)
{
    //int *num_customer = (int*) arg;
    int customer_needs = 900 + rand()%200;
    int selected_shop = 0;
    printf("****CUSTOMER NO.%u. NEEDS = %d****\n", (int) pthread_self(), customer_needs);
    while(customer_needs > 0)
    {
        selected_shop = rand()%5;
        pthread_mutex_lock(&mutex);
        if(shops_goods[selected_shop] <= customer_needs)
        {
            customer_needs -= shops_goods[selected_shop];
            shops_goods[selected_shop] = 0;
        }
        else
        {
            shops_goods[selected_shop] -= customer_needs;
            customer_needs = 0;
            
        }
        printf("In shop no.%d goods = %d, cusomer no.%u needs = %d\n", selected_shop + 1, shops_goods[selected_shop], (int) pthread_self(), customer_needs);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }

    return EXIT_SUCCESS;
}

void* loader(void *arg)
{
    int selected_shop = 0;
    while(flag)
    {
        selected_shop = rand()%5;
        pthread_mutex_lock(&mutex);
        shops_goods[selected_shop] += 500;
        printf("Loader added goods in shop no.%d. Total = %d\n", selected_shop + 1, shops_goods[selected_shop]);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return EXIT_SUCCESS;
}
