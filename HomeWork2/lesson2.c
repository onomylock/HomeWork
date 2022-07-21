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
    int flag = 0;
    printf("\nWrite first name:");
    scanf("%s", person1.FirstName);
    printf("\nWrite last name:");
    scanf("%s", person1.LastName);
    printf("\nWrite number:");
    scanf("%d", &person1.Number);

    for(int i = 0; i < N; i++)
    {
        if(ptr->Number == 0)
        {
            for(int j = 0; j < BUF; j++)
            {
                ptr->FirstName[j] = person1.FirstName[j];
                ptr->LastName[j] = person1.LastName[j];
            }                        
            ptr->Number = person1.Number;
            flag = 1;
            break;
        }
        ptr++;
    }
    if(flag == 0) printf("Buffer is over!");
}

void RemovePerson(struct Person *ptr)
{    
    int number;
    int flag = 0;    
    char tmp[BUF] = {0};
    printf("\nWrite person's number:");
    scanf("%d", &number);

    for(int i = 0; i < N; i++)
    {
        if(ptr->Number == number)
        {
            //ptr->FirstName = {0};
            for(int j = 0; j < BUF; j++)
            {                
                ptr->FirstName[j] = tmp[j];
                ptr->LastName[j] = tmp[j];
            } 
                                   
            ptr->Number = 0;
            flag = 1;
            break;
        }
        ptr++;
    }
    if(flag == 0) printf("Number not found");
}

void FindPersonByFirstName(struct Person *ptr)
{
    char firstName[BUF] = {0};
    printf("\nWrite the first name to search:\n");
    scanf("%s", firstName);
    for(int i = 0; i < N; i++)
    {
        if(strcmp(ptr->FirstName, firstName) == 0)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", ptr->FirstName, ptr->LastName, ptr->Number);            
        }
    }    
}

void FindPersonByLastName(struct Person *ptr)
{
    char lastName[BUF] = {0};
    printf("\nWrite the last name to search:\n");
    scanf("%s", lastName);
    for(int i = 0; i < N; i++)
    {
        if(strcmp(ptr->LastName, lastName) == 0)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", ptr->FirstName, ptr->LastName, ptr->Number);            
        }
    }    
}

void FindPersonByNumber(struct Person *ptr)
{
    int number = 0;
    printf("\nWrite the number to search:\n");
    scanf("%d", &number);
    for(int i = 0; i < N; i++)
    {
        if(ptr->Number == number)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", ptr->FirstName, ptr->LastName, ptr->Number);            
        }
        ptr++;
    }    
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
    int findItem;
    char findchars[BUF];
    struct Person persons[N] = {0};
    struct Person *ptr = &persons[0]; 
    
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
                AddPerson(ptr);
                break;
            }         
            case 3:
            {
                RemovePerson(ptr);
                break;
            }
            case 4:
            {
                printf("\n1) By First Name");
                printf("\n2) By Last Name");
                printf("\n3) By Number\n");
                scanf("%d", &findItem);
                switch (findItem)
                {
                case 1:
                {                
                    FindPersonByFirstName(ptr);
                    break;
                }
                case 2:
                {                
                    FindPersonByLastName(ptr);
                    break;
                }
                case 3:
                {                
                    FindPersonByNumber(ptr);
                    break;
                }                   
                default:
                {
                    printf("\nWrong Item!\n");
                    break;
                }                    
                }
                break;
            }
            case 5:
            {
                printf("Good night\n");
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
