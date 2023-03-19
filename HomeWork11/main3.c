#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    int pipefd[2];
    pid_t cpid;

    if (pipe(pipefd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if(cpid == -1)
    {
        exit(-1);
    }
    else if(cpid == 0)
    {
        close(pipefd[1]);
        char ch;
        while ((read(pipefd[0], &ch, sizeof(char))) > 0)
        {
            printf("%c", ch);
        }
        printf("\n");
        close(pipefd[0]);
        exit(0);                
    }
    else
    {
        close(pipefd[0]);
        char* str = "Hello pipe";
        write(pipefd[1], str, strlen(str));
        close(pipefd[1]);
        wait(NULL);
        exit(0);
    }


    //exit(0);

}