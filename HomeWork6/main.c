#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include "fun.h"
#define FUN_NUM 4


int main(void)
{
    void *handle[FUN_NUM];
    int (*func)(int, int), menuItem = -1, a, b;
    char funName[FUN_NUM][6]={"addFun", "subFun", "divFun", "mltFun"};
    char *error;


    handle[0] = dlopen("libadd.so", RTLD_LAZY);
    handle[1] = dlopen("libsub.so", RTLD_LAZY);
    handle[2] = dlopen("libdiv.so", RTLD_LAZY);
    handle[3] = dlopen("libmlt.so", RTLD_LAZY);

    for (int i = 0; i < FUN_NUM; i++)
    {
        if(handle[i])
        {
            printf("%d) ", i+1);
            for(int j = 0; j < 6; j++)
            {
                printf("%c", funName[i][j]);
            }
            printf("\n");
        }
    }
    
    while(menuItem != 0)
    {
        scanf("%d", &menuItem);

        printf("Write num a: ");  
        scanf("%d", &a);
        printf("Write num b: ");
        scanf("%d", &b);

        if (menuItem > 0 && menuItem < FUN_NUM)
        {
            // if (handle[menuItem])
            //     switch (menuItem)
            //     {
            //     case /* constant-expression */:
            //         /* code */
            //         break;
                
            //     default:
            //         break;
            //     }

            

            func = dlsym(handle[menuItem], funName[menuItem]);
            if ((error = dlerror()) != NULL)  
            {
                fputs(error, stderr);
                exit(1);
            }
            printf("result = %d", func(a, b));
            //printf("%s",funName[i]);
        }    
    }

}

//
//int main(void)
//{
//    int a, b, result;
//    int menuItem = 0;            
//    void *handle[4];
//    int (*func[4])(int, int);
//    char *error;
//   
//    char const funName[4][9]={"libadd.so", "libsub.so", "libdiv.so", "libmlt.so"};
//    //char *ptrfun = &funName[0][0];
//        
//    printf("__________________MENU__________________\n");
//
//    for(int i = 0; i < 4; i++)
//    {        
//        handle[i] = dlopen(funName[i], RTLD_LAZY);
//        if(!handle[i])
//        {
//            fputs (dlerror(), stderr);
//            exit(1);
//        }
//        else
//        {
//            char strtmp[6];
//            char *ptrstr = &strtmp[0];
//            for(int j = 0; j < 3; j++)
//            {
//                strtmp[j] = funName[i][j + 3];
//            }
//
//            func[i] = dlsym(handle[i], strcat(ptrstr, "Fun"));
//            if ((error = dlerror()) != NULL)  
//            {
//                fputs(error, stderr);
//                exit(1);
//            }
//            printf("%s",funName[i]);
//        }
//    }
//    
//   
//
//}
//