#include <stdio.h>
#include <stdlib.h>

#define N 10
#define BUF 20


struct Person
{
    int Number;
    char FirstName[BUF];
    char LastName[BUF];
};

void AddPerson()
{

}

void RemovePerson()
{

}

void FindPerson()
{

}

void ViewPersons(struct Person *ptr)
{
    for(int i = 0; i < N; i++)
    {
        printf("First Name: %s\t Last Name: %s\t Number: %d\n", ptr->FirstName, ptr->LastName, ptr->Number);
        ptr++;
    }
}

int main(void)
{    
    int menuItem;
    struct Person persons[N];
    struct Person *ptr = &persons[0]; 

    for(int i = 0; i < N; i++)
    {
        // for(int j = 0; j < BUF; j++)
        // {
        //     persons[i].FirstName[j] = '_';
        //     persons[i].LastName[j] = '_';
        // }
        persons[i].FirstName[0] = '_';
        persons[i].LastName[0] = '_';        
        persons[i].Number = -1;
    }       
    //printf("%lu", sizeof(persons[0]));
    while (menuItem != 5)
    {
        printf("__________________MENU__________________\n");
        printf("1) View all person\n");
        printf("2) Add person in telefon book\n");
        printf("3) Remove person from telefon book\n");
        printf("4) Find Person\n");
        printf("5) Exit\n");
        scanf("%d", &menuItem);

        switch (menuItem)
        {
            case 1:
            {
                ViewPersons(ptr);
                break;
            }            
            case 2:
            {
                printf("Item2!\n");
                break;
            }         
            case 3:
            {
                printf("Item3!\n");
                break;
            }
            case 4:
            {
                printf("Item4!\n");
                break;
            }
            case 5:
            {
                printf("Item5!\n");
                break;
            }

            default:
            {
                printf("Wrong Item!\n");
                break;
            }            
        }
        getchar();
    }
}
