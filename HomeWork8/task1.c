#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;
    pid = fork ();
    if (pid > 0)
    {
        printf ("Я родительский процесс сpid=%d!\n", pid);
        
    }        
    else if (!pid)
        printf ("А я дочерний!\n");
    else if (pid == -1)
        perror ("fork");
    wait(NULL);
    exit(0);

}