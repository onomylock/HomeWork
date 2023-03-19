#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define PATH_MAX 100
#define WORDS_MAX 10



int main(void)
{
    pid_t pid;
    int status, pipefd[2];
    char Str[PATH_MAX], PathName[PATH_MAX];
    char *str = Str, *path;
    path = getcwd(PathName, PATH_MAX);

    if (pipe(pipefd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        
        while ((read(pipefd[1], &ch, sizeof(char))) > 0)
        {
            printf("%c", ch);
        }
        exit(0);
    }
    else
    {
        
        close(pipefd[0]);
        while((*str+=getc (stdin)) != '\n');
        
        wait(NULL);
        exit(0);
    }
    


}