#include <stdio.h>
#include "fun.h"

void menuPrint()
{
    printf("__________________MENU__________________\n");
    printf("1) Write nums\n");
    printf("2) multiplication\n");
    printf("3) division\n");
    printf("4) Addition\n");
    printf("5) Subtraction\n");
    printf("6) Exit\n");
}

int main(void)
{
    int a, b, result;
    int menuItem = 0;    

    menuPrint();
    


    while(menuItem != 6)
    {
        scanf("%d", &menuItem);
        switch (menuItem)
        {
        case 1:
        {          
            printf("Write num a: ");  
            scanf("%d", &a);
            printf("Write num b: ");
            scanf("%d", &b);
            printf("Choose action\n");
            break;
        }
        case 2:
        {
            result = mult_fun(a, b);
            printf("result of multyply = %d\n", result);
            printf("write new nums\n");
            break;
        }
        case 3:
        {
            result = div_fun(a, b);
            printf("result of division = %d\n", result);
            printf("write new nums\n");
            break;
        }
        case 4:
        {
            result = add_fun(a, b);
            printf("result of addition = %d\n", result);
            printf("write new nums\n");
            break;
        }
        case 5:
        {
            result = sub_fun(a, b);
            printf("result of subtraction = %d\n", result);
            printf("write new nums\n");
            break;
        }        
        default:
            break;
        }
    }

}