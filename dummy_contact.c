#include<stdio.h>
#include "contact.h"
#include <string.h>
// Dummy contact data
Contact dummyContacts[] = 
{
    {"John Doe", "1234567890", "john@gmail.com"},
    {"Alice Smith", "0987654321", "alice@gmail.com"},
    {"Bob Johnson", "1112223333", "bob@gmail.com"},
    {"Carol White", "4445556666", "carol@gmail.com"},
    {"David Brown", "7778889999", "david@gmail.com"},
    {"Eve Davis", "6665554444", "eve@gmail.com"},
    {"Frank Miller", "3334445555", "frank@gmail.com"},
    {"Grace Wilson", "2223334444", "grace@gmail.com"},
    {"Hannah Clark", "5556667777", "hannah@gmail.com"},
    {"Ian Lewis", "8889990000", "ian@gmail.com"}
    };

// void initialize(AddressBook *addressBook)
// {
//     int size = sizeof(dummyContacts) / sizeof(dummyContacts[0]);
//     for (int i = 0; i < size; i++)
//     {
//         addressBook->contacts[i] = dummyContacts[i];
//     }
//     addressBook->contactCount = size;
// }
int search_name(AddressBook *addressBook)
{
    char name[50];
    printf("Enter the name:");//enter the name user
    getchar();
    scanf("%[^\n]", name);//read the from user name
    getchar();
    int i, flag = 0;
    for (i = 0; i < addressBook->contactCount; i++)
    {     //print the results
        if ((strcmp(addressBook->contacts[i].name, name)) == 0)
        {
            flag = 1;
            //printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
            return i;
            printf("\n");
        }
    }
    if (flag != 1)//valid or invalid condition check
    {
        printf("invalid\n");
        return -1 ;
    }
}
int search_phone(AddressBook *addressBook)
{
    char phone_no[11];
    printf("Enter the phone number:");//enter from the  user
    getchar();
    scanf("%[^\n]", phone_no); //read the number
    getchar();

    int i, res;//integer i,res
    int length = 0; //integer length
    int flag = 0;  //integer flag
    length = strlen(phone_no); //find the length of digits

    for (int i = 0; i < length; i++)
    {
        if (!(phone_no[i] >= '0' && phone_no[i] <= '9'))
        {  
            printf("Please enter digits only\n");
            break;
        }
    }
    if (length == 10)
    {      //len1 is equal to 10
        for (i = 0; i < addressBook->contactCount; i++)
        {
            res = strcmp(addressBook->contacts[i].phone, phone_no);
            if (res == 0)
            {
                flag = 1;
                //printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                return i;
                // break;
            }
        }
    }
    else if (length != 10) //to check the else if part
    {
        printf("Please enter 10 digit phone number\n");
        // goto label;
    }
    if (flag == 0)//check the condition phone number is found or not found
    {
        printf("given phone number is not found\n");
        return -1;
    }
}

int search_email(AddressBook *addressBook)   //function definition
{
    char email[100];
    printf("Enter the email id:\n"); //to search the email
    getchar();
    scanf("%[^\n]", email);//read the email
    getchar();
    char substring[] = "@gmail.com";

    char *ptr;
    ptr = strstr(email, substring); // printf("before condition ptr -> %s\n",ptr);
    if (ptr == NULL)
    {
        printf("Please include @gmail.com in email\n");//print the email properly
        // return 0;
    }
    int flag = 0;
    for (int i = 0; i < addressBook->contactCount; i++)
    {     //print the results
        int res = strcmp(email, addressBook->contacts[i].email);
        if (res == 0)
        {
            flag = 1;
            return i;
        }
    }
    if (flag == 0)//valid or invalid condition check
    {
        printf("Invalid email id\n");
        return-1;
    }
}
