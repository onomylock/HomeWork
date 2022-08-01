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

struct PhoneBook
{
    struct Person *Persons;
    int Size;
    int Capacity;
};

void CheckFull(struct PhoneBook* phoneBook)
{
    if(phoneBook->Size == phoneBook->Capacity)
    {
        struct Person *tmp = (struct Person*)realloc(phoneBook->Persons, sizeof(struct Person)*(phoneBook->Capacity + 1));
        if(tmp != NULL)
        {
            phoneBook->Persons = tmp;
            phoneBook->Capacity = phoneBook->Capacity + 1;            
        }
        else
        {
            printf("Error realloc");
            exit(1);
        }
    }
}

void AddPerson(struct PhoneBook *phoneBook)
{
    CheckFull(phoneBook);    
    printf("\nWrite first name:");
    scanf("%s", phoneBook->Persons[phoneBook->Size].FirstName);
    printf("\nWrite last name:");
    scanf("%s", phoneBook->Persons[phoneBook->Size].LastName);
    printf("\nWrite number:");
    scanf("%d", &phoneBook->Persons[phoneBook->Size].Number);
    phoneBook->Size++;    
}

void RemovePerson(struct PhoneBook *phoneBook)
{    
    int number;
    int flag = 0;    
    char tmp[BUF] = {0};
    printf("\nWrite person's number:");
    scanf("%d", &number);

    for(int i = 0; i < phoneBook->Size; i++)
    {
        if(phoneBook->Persons[i].Number == number)
        {            
            for(int j = i; j < phoneBook->Size; j++)
            {
                if(j < (phoneBook->Size - 1))
                {
                    phoneBook->Persons[j] = phoneBook->Persons[j + 1];
                }
            }
            flag = 1;
            phoneBook->Size--;
        }        
    }
    if(flag == 0) printf("Number not found");
}

void FindPersonByFirstName(struct PhoneBook *phoneBook)
{
    char firstName[BUF] = {0};
    printf("\nWrite the first name to search:\n");
    scanf("%s", firstName);
    for(int i = 0; i < phoneBook->Size; i++)
    {
        if(strcmp(phoneBook->Persons[i].FirstName, firstName) == 0)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", phoneBook->Persons[i].FirstName, phoneBook->Persons[i].LastName, phoneBook->Persons[i].Number);            
        }
    }    
}

void FindPersonByLastName(struct PhoneBook *phoneBook)
{
    char lastName[BUF] = {0};
    printf("\nWrite the last name to search:\n");
    scanf("%s", lastName);
    for(int i = 0; i < phoneBook->Size; i++)
    {
        if(strcmp(phoneBook->Persons[i].LastName, lastName) == 0)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", phoneBook->Persons[i].FirstName, phoneBook->Persons[i].LastName, phoneBook->Persons[i].Number);            
        }
    }    
}

void FindPersonByNumber(struct PhoneBook *phoneBook)
{
    int number = 0;
    printf("\nWrite the number to search:\n");
    scanf("%d", &number);
    for(int i = 0; i < phoneBook->Size; i++)
    {
        if(phoneBook->Persons[i].Number == number)
        {
            printf("First Name: %s\t Last Name: %s\t Number: %d\n", phoneBook->Persons[i].FirstName, phoneBook->Persons[i].LastName, phoneBook->Persons[i].Number);            
        }        
    }    
}

void ViewPersons(struct PhoneBook *phoneBook)
{
    for(int i = 0; i < phoneBook->Size; i++)
    {
        printf("First Name: %s\t Last Name: %s\t Number: %d\n", phoneBook->Persons[i].FirstName, phoneBook->Persons[i].LastName, phoneBook->Persons[i].Number);                
    }
}

void InitPerson(struct PhoneBook* phoneBook)
{
    phoneBook->Size = 0;
	phoneBook->Persons = (struct Person *)malloc(sizeof(struct Person));
	phoneBook->Capacity = 1;
}

int main(void)
{    
    int menuItem;
    int findItem;
    char findchars[BUF];
    char menuItemChar[BUF];
    struct PhoneBook *phoneBook = (struct PhoneBook*)malloc(sizeof(struct PhoneBook));    
    InitPerson(phoneBook);

    while (menuItem != 5)
    {
        printf("__________________MENU__________________\n");
        printf("1) View all person\n");
        printf("2) Add person in telefon book\n");
        printf("3) Remove person from telefon book\n");
        printf("4) Find Person\n");
        printf("5) Exit\n");
        scanf("%d", &menuItem);
        //gets(menuItemChar);
        //menuItem = atoi(menuItemChar);

        switch (menuItem)
        {
            case 1:
            {
                ViewPersons(phoneBook);
                break;
            }            
            case 2:
            {
                AddPerson(phoneBook);
                break;
            }         
            case 3:
            {
                RemovePerson(phoneBook);
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
                    FindPersonByFirstName(phoneBook);
                    break;
                }
                case 2:
                {                
                    FindPersonByLastName(phoneBook);
                    break;
                }
                case 3:
                {                
                    FindPersonByNumber(phoneBook);
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
        //getchar();
    }

    free(phoneBook->Persons);
    free(phoneBook);
}
