#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define BUF 20


struct Person
{
    int Number;
    char FirstName[BUF];
    char LastName[BUF];
};

void AddPerson(struct Person *ptr)
{
    struct Person person1;

    printf("\nWrite first name:%s", person1.FirstName);
    printf("\nWrite last name:%s", person1.LastName);
    printf("\nWrite first name:%d", person1.Number);

    // for(int i = 0; i < N; i++)
    // {

    // }
}

void RemovePerson()
{

}

int FindPersonByFirstName(struct Person *ptr)
{
    char firstName[BUF] = {0};
    printf("\nWrite the first name to search:\n");
    scanf("%s", firstName);
    for(int i = 0; i < N; i++)
    {
        if(strcmp(ptr->FirstName, firstName) == 0)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", ptr->FirstName, ptr->LastName, ptr->Number);
            return i;
        }
    }
    return -1;
}

int FindPersonByLastName(struct Person *ptr)
{
    char lastName[BUF] = {0};
    printf("\nWrite the last name to search:\n");
    scanf("%s", lastName);
    for(int i = 0; i < N; i++)
    {
        if(strcmp(ptr->LastName, lastName) == 0)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", ptr->FirstName, ptr->LastName, ptr->Number);
            return i;
        }
    }
    return -1;
}

int FindPersonByNumber(struct Person *ptr)
{
    int number = 0;
    printf("\nWrite the number to search:\n");
    scanf("%d", &number);
    for(int i = 0; i < N; i++)
    {
        if(ptr->Number = number)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", ptr->FirstName, ptr->LastName, ptr->Number);
            return i;
        }
    }
    return -1;
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
    struct Person persons[N] = {0};
    struct Person *ptr = &persons[0]; 

    // for(int i = 0; i < N; i++)
    // {
    //     // for(int j = 0; j < BUF; j++)
    //     // {
    //     //     persons[i].FirstName[j] = '_';
    //     //     persons[i].LastName[j] = '_';
    //     // }
    //     persons[i].FirstName[0] = '_';
    //     persons[i].LastName[0] = '_';        
    //     persons[i].Number = -1;
    // }       
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
