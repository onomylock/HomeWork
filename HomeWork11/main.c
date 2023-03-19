#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define PATH_MAX 100
#define WORDS_MAX 10
// #define STD_IN 0
// #define STD_OUT 1

int main(void)
{
    pid_t pid;
    int status, pipefd[2];        
    char PathName[PATH_MAX], *Text[WORDS_MAX], Str[PATH_MAX];   
    char *ptr, *token;
    ptr = getcwd(PathName, PATH_MAX);    
    
    if (pipe(pipefd) == -1) 
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    //dup2(pipefd[1], STDIN_FILENO);
    //dup2(pipefd[0], STDOUT_FILENO);

    char ch, *str = Str;
    //fgets(Str, 99, stdin);
    
    while((*str+=getc (stdin)) != '\n')
    {
        //write(STDIN_FILENO, str, sizeof(char));        
    }
    *str = '\0';
    close(STDIN_FILENO);
    
    

    // pid = fork ();    
    // if (pid == -1)
    // {
    //     perror ("fork");
    // }            
    // else if (pid == 0)
    // {            
    //     close(pipefd[1]);
    //     char ch;
    //     while ((read(pipefd[0], &ch, sizeof(char))) > 0)
    //     {
    //         printf("%c", ch);
    //     }
    //     printf("\n");
    //     close(pipefd[0]);
    //     exit(0);     
    //     /*if(ptr == NULL)
    //     {
    //         printf("Error PATH\n");
    //         exit(1);
    //     }             
    //     int i = 0;     
    //     close(pipefd[1]);
    //     while(read(pipefd[0], &Str, 1) > 0)
    //     {
    //         write(STDIN_FILENO, &Str, 1);
    //     }

    //     token = strtok(Str, " ");
    //     while(token != NULL)
    //     {            
    //         Text[i] = (char*)malloc(sizeof(char)*(strlen(token + 1))); 
    //         strcpy(Text[i], token);           
    //         token = strtok(NULL, " ");
    //         i++;
    //     }        
    //     Text[i] = (char*)malloc(sizeof(char)*(strlen(PathName + 1)));
    //     strcpy(Text[i], PathName);
    //     for(int j = 0; j <= i; j++)
    //     {
    //         free(Text[j]);
    //     }
    //     char *args[] = {"ls", "-la", PathName, NULL};
    //     execvp("ls", args);
    //     execvp(args);*/
    // }
    // else
    // {   
    //     close(pipefd[0]);
    //     //while(fg)
    //     //fgets(Str, 99, stdin);    
    //     close(pipefd[1]);
    //     wait(NULL);
    //     exit(0);
        // fgets(Str, PATH_MAX, pipefd[1]);
        // fgets(Str, PATH_MAX, stdin);
        // write(pipefd[1], Str, strlen(Str));
        // close(pipefd[1]);
        // close(pipefd[1]);        
        // if(strncmp("exit", Str, 4) == 0) break;
                 
        // wait(&status);*/
    //}
    //exit(0);           
}
            
    
