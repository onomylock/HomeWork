#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define PATH_MAX 100

int main(int argc, char **argv)
{
    pid_t pid;
    int status;
    if(argc != 3)
    {
        printf("Error:%d\n", argc);
        exit(1);
    }
    char PathName[PATH_MAX];   
    char *ptr;

    ptr = getcwd(PathName, PATH_MAX);
   
    pid = fork ();

    if (!pid)
        {
            //char *programName = "ls";
            if(ptr == NULL)
            {
                printf("Error PATH\n");
                exit(1);
            }                   
            char *args[] = {argv[1], argv[2], PathName, NULL};
            execvp(argv[1], args);
        }
    else if(pid > 0)
    {
        wait(&status);
    }
    else if (pid == -1)
        perror ("fork");

    exit(0);
}