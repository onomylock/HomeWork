#include <stdio.h>
#include <stdlib.h>

#define N 15


void array_print(int Arr[N][N])
{
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            printf("%d\t", Arr[i][j]);
        }
        printf("\n");
    }
    printf("**********************\n");
}

void first()
{
    int Arr[N][N];
    int counter = 1;
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            Arr[i][j] = counter;
            counter += 1;
        }
    }
    array_print(Arr);
}

void second()
{
    int Arr[N];
    int tmp = 0;
    for(int i = 0; i < N; i++)
    {
        Arr[i] = i + 1;
    }

    printf("\nInput array: \n");

    for(int i = 0; i < N; i++)
    {
        printf("%d ", Arr[i]);
    }
    printf("\n");
    
    for(int i = 0; i <= N/2; i++)
    {
        tmp = Arr[i];
        Arr[i] = Arr[N - 1 - i];
        Arr[N - 1 - i] = tmp;
    }

    printf("\nOutput array: \n");

    for(int i = 0; i < N; i++)
    {
        printf("%d ", Arr[i]);
    }

    printf("\n");
}

void third()
{
    int Arr[N][N];
    int counter = 0;
    for(int i = N - 1; i >= 0; i--, counter++)
    {
        for(int j = N - 1; j >= counter; j--)
        {
            Arr[i][j] = 1;
        }
        for(int j = 0; j < counter; j++)
        {
            Arr[i][j] = 0;
        }
    }

    array_print(Arr);
}

void fourth()
{
    int Arr[N][N];
    int counter = 1, line = 0;
    for(int k = N - 2; k >= 1; k -=2, line++)
    {
        for(int i = line, j = N - line - 1; i < N - line; i++, j--)
        {
            Arr[line][i] = counter;
            Arr[N - 1 - line][j] = counter + 2 * k + 2;
            counter++;
        }
        for(int i = line + 1, j = k + line; i <= k + line; i++, j--)
        {
            Arr[i][N - line - 1] = counter;
            Arr[j][line] = counter + 2 * k + 2;
            counter++;
        }
        counter += 2 * k + 2;
    }

    Arr[N / 2][N / 2] = counter;
    array_print(Arr);
}

int main()
{
    printf("First exercise:\n");
    first();
    printf("Second exercise:\n");
    second();
    printf("Third exercise:\n");
    third();
    printf("Fourth exercise:\n");
    if (N%2 != 0)
    {
        fourth();
    }
    else
    {
        printf("\nnumber must be odd\n");
    }
    return 0;
}
