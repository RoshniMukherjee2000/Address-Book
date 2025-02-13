#include <stdio.h>
#include "contact.h"
#include <string.h>
void initialize(AddressBook *addressBook) // function definition
{
    FILE *fp = fopen("load.csv", "r");
    // Load contacts from file during initialization
    if (fp == NULL) // file pointer is compare is null
    {               // print results
        printf("File doesn't exist\n");
        return;
    }
    fscanf(fp, "#%d#\n", &addressBook->contactCount);   // it is stored in addressBook->contactCount, which keeps track of how many contacts the file contains.
    for (int i = 0; i < addressBook->contactCount; i++) // counting the contacts
    {                                                   // read the detalis
        fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fp); // close the file
}
void save_contact(AddressBook *addressBook) // to save the contact details after editing or deleteting or by creating the contacts

{
    FILE *fp = fopen("load.csv", "w"); // open the file contact.csv
    if (fp == NULL)                    // file pointer is compare is null
    {
        printf("File doesn't exist\n"); // print results
        return;
    }
    fprintf(fp, "#%d#\n", addressBook->contactCount);   // Inside the loop, the fprintf function writes each contact's information (name, phone number, and email) in CSV format
    for (int i = 0; i < addressBook->contactCount; i++) // using the for loop
    {
        // print the details
        fprintf(fp, "%s,%s,%s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    // close the file
    fclose(fp);
}

void listContacts(AddressBook *addressBook) // function definition
{
    for (int i = 0; i < addressBook->contactCount; i++) // run the loop from zero upto contact count

    {
        printf(".....................................................................................\n");
        printf("name -> %s\n", addressBook->contacts[i].name);   // print the name
        printf("phone -> %s\n", addressBook->contacts[i].phone); // print the phone
        printf("email -> %s\n", addressBook->contacts[i].email); // print the email
        printf("......................................................................................\n");
        printf("\n");
    }
}

void createContact(AddressBook *addressBook) // function definition
{

    char name[50];    // contact name
    char phoneno[50]; // contact phone number
    char emailid[60]; // contact emailid

    printf("Enter name:\n"); // print the name
    scanf(" %[^\n]", name);  // read the name
    getchar();
    strcpy(addressBook->contacts[addressBook->contactCount].name, name);

label:
    printf("Enter phone number:\n");
    scanf(" %[^\n]", phoneno); // read the ph.no

    getchar();

    int i, res;               // integer value i,res
    int length = 0;           // initialize length to zero
    int flag = 0;             // initialize flag to zero
    length = strlen(phoneno); // create len to know the length of phone number

    for (int i = 0; i < length; i++) // only digit use
    {
        if (!(phoneno[i] >= '0' && phoneno[i] <= '9'))
        {
            printf("Please enter digits only\n");
            length--;
            goto label;
        }
    }
    if (length == 10) // check the number is already exit or not
    {
        for (i = 0; i < addressBook->contactCount; i++)
        {
            res = strcmp(addressBook->contacts[i].phone, phoneno);
            if (res == 0)
            {
                flag = 1;
                printf("Phone number already existed\n");
                goto label;
            }
        }
    }
    else if (length != 10) // if its not 10 digits
    {
        printf("Please enter 10 digit phone number\n");
        goto label; // its like a loop
    }
    if (flag == 0)
    {
        strcpy(addressBook->contacts[addressBook->contactCount].phone, phoneno);
    }
label2:
    printf("Enter email:\n");
    scanf(" %[^\n]", emailid); // read the email
    getchar();
    char substring[] = "@gmail.com"; // email should contain @gmail.com

    int valid = 1;
    if (emailid[0] != '@') // run the loop upto @
    {
        char *ptr;
        ptr = strstr(emailid, substring);
        if (ptr == NULL)
        {
            printf("Please include @gmail.com in email\n");
            goto label2;
        }
        flag = 0;
        for (int i = 0; i < addressBook->contactCount; i++)
        {
            if (strcmp(emailid, addressBook->contacts[i].email) == 0)
            {
                flag = 1;
                printf("Email already exists. Try again.\n");
                goto label2;
            }
        }
    }
    else
    {
        goto label2;
    }
    if (flag == 0)
    {
        for (int i = 0; emailid[i] != '\0'; i++)
        {
            if (emailid[i] >= 'A' && emailid[i] <= 'Z')
            {
                valid = 0;
                printf("Please enter email in lowercase\n");
                goto label2;
            }
        }
        if (valid)
        {
            strcpy(addressBook->contacts[addressBook->contactCount].email, emailid);
        }
    }
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) // function defintion
{
    /* Define the logic for search */
    // declaration
    int choice;
    printf("What do u want :\n1.Name\n2.Phone number\n3.Email Id\n"); // print the menu
    printf("Enter the choice:");                                      // Entered your option form menu
    scanf("%d", &choice);                                             // read the choice
    char name[50];
    char phone_no[11];
    char email[50];
    switch (choice) // using switch case stament
    {
    case 1:
    {
        // declaration
        int ret = -1;
        ret = search_name(addressBook); // function call
        if (ret != -1)
        {
            printf("%s %s %s\n", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
        }
        /*
        printf("Enter the name:");//Enter ur had name
        getchar();
        scanf("%[^\n]", name); //read the name
        getchar();
        int i;
        int res, flag = 0;
        for (i = 0; i < addressBook->contactCount; i++)
        {
            res = strcmp(name, addressBook->contacts[i].name);
            if (res == 0) //check the if condition
            {
                flag = 1; //assume flag
                printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                break;
            }
        }
        if (flag == 0) //check the if condition
        {
            printf("invalid\n");
        }
        */
    }
    break;
    case 2:
    {
        int ret = -1;
        ret = search_phone(addressBook); // function call
        break;
        if (ret != -1)
        { // print your choosen results
            printf("%s %s %s\n", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
        }
        /*
        printf("Enter the phone number:");//Enter the your phone number
        getchar();
        scanf("%[^\n]", phone_no);//Read the phone number
        getchar();

        int count = 0,flag = 0,res;
        //using for loop
        for (int i = 0; phone_no[i] != '\0'; i++)
        {
            if (phone_no[i] >= '0' && phone_no[i] <= '9')
            {
                count++;
            }
            else   //else part
            {
                printf("Please enter digits only\n");
                break;
            }
        }
        if (count == 10) //check the if condition
        {
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                res = strcmp(phone_no, addressBook->contacts[i].phone);
                if (res == 0)//check the if condition
                {
                    flag = 1;//assume the flag value one
                    printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email); //print your choosen results
                    break;
                }
            }
        }
        else if (count != 10)
        {
            printf("Please enter 10 digit phone number\n");
        }
        if (flag == 0)//check the if condition
        {
            printf("given phone number is not found\n");
        }
        */
    }
    break;
    case 3:
    {
        int ret = -1;
        ret = search_email(addressBook); // function call
        if (ret != -1)
        {
            printf("%s %s %s\n", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
        }
        /*
        printf("Enter the email id:\n");//enter the from user
        getchar();
        scanf("%[^\n]", email);//read the from user
        getchar();
        char substring[] = "@gmail.com";

        char *ptr;
        ptr = strstr(email, substring);
        if (ptr == NULL) //check the if condition
        {
            printf("Please include @gmail.com in email\n");
            // return 0;
        }
        int flag = 0;
        for (int i = 0; i < addressBook->contactCount; i++)//using the for loop
        {
            int res = strcmp(email, addressBook->contacts[i].email);
            if (res == 0) //check the if condition
            {
                flag = 1;
                printf("%s %s %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                break;
            }
        }
        if (flag == 0) //check the if condition
        {
            printf("Invalid email id\n");
        }
        */
    }
    break;
    }
}
void editContact(AddressBook *addressBook) // function definition
{
    int choice1 = 0, ret = -1;
    printf("Enter the choice:\n1.Name\n2.Phone number\n3.Email Id\n");
    scanf("%d", &choice1); // read the option
    char name[100];         // contact name
    char phone_no[11];      // contact phone number
    char email_id[50];      // contact email.id

    switch (choice1)
    {
    case 1:
    {
        ret = search_name(addressBook); // function call
        if (ret != -1)
        {
            printf("%s %s %s\n", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
            printf("Enter new name:\n"); // entered the new name
            scanf("%[^\n]", name);       // replace the existing name with new name
            strcpy(addressBook->contacts[ret].name, name);
        }
    }
    break;

    case 2:
    {
        int length = 0;
        ret = search_phone(addressBook); // function call

        if (ret != -1)
        {
            printf("%s %s %s\n", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
            printf("Enter new phone no:\n"); // print the new number
            scanf(" %[^\n]", phone_no);      // read the phone number
            // using the for loop
            for (int i = 0; phone_no[i] != '\0'; i++)
            {
                // to check the if condition
                if (!(phone_no[i] >= '0' && phone_no[i] <= '9'))
                {
                    length--;
                    printf("Please enter digits only\n"); // user only enter phone number is digits
                    break;
                }
                else
                {
                    length++; // if length value is increment
                }
            }
            if (length == 10) // length = strlen(phone_no);
            {
                strcpy(addressBook->contacts[ret].phone, phone_no);
            }
            else if (length != 10)
            {
                printf("Please enter 10 digit mobile number\n"); // moblie number is only entering 10 digits
            }
        }
    }
    break;
    case 3:
    {
        char sub[] = "@gmail.com";
        int valid = 1;
        ret = search_email(addressBook);
        if (ret != -1)
        {
            printf("%s %s %s\n", addressBook->contacts[ret].name, addressBook->contacts[ret].phone, addressBook->contacts[ret].email);
            printf("Enter new email Id:\n"); // print the new email id
            scanf(" %[^\n]", email_id);      // read the new email id
    
            char *ptr;
            ptr = strstr(email_id, sub);
            if (ptr == NULL)
            { // must be enter @gmail.com
                valid = 0;
                printf("Please include @gmail.com in email\n");
            }
            // using the for loop
            for (int i = 0; email_id[i] != '\0'; i++)
            { // check the email should be lowercase
                if (email_id[i] >= 'A' && email_id[i] <= 'Z')
                {
                    valid = 0;
                    printf("Please enter email in lowercase\n"); // only lowercase value print
                }
                 if( email_id[i] >= '0' && email_id[i] <= '9')
                     {
                        valid=0;
                        printf("Please enter only alphabet");
                        break;
                    }
              
            }
            if (valid == 1)
            {
                // printf("ret = %d\n", ret);
                strcpy(addressBook ->contacts[ret].email, email_id);
            }
          
        }
    }
    break;
    default :
        printf("Give the correct choice value\n");
    }

 
}

void deleteContact(AddressBook *addressBook) // function definition
{
    printf("choose one of the option:\n");    // print the option
    printf("1.Name\n2.phone no.\n3.email\n"); // print the option name,phone number,email
    int choice, ret;
    scanf("%d", &choice); // read the choice
    switch (choice)
    {
    case 1:
    {

        ret = search_name(addressBook);
        for (int i = ret; i < addressBook->contactCount; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1]; // here the contact of i+1 is moved to i th position as one contact has been deleting
        }
    }
    break;
    case 2:
    {
        ret = search_phone(addressBook);
        for (int i = ret; i < addressBook->contactCount; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
    }
    break;
    case 3:
    {
        ret = search_email(addressBook);
        for (int i = ret; i < addressBook->contactCount; i++)
        {
            addressBook->contacts[i] = addressBook->contacts[i + 1];
        }
    }
    break;
    }
    addressBook->contactCount--; // deacrease the contact count has the contact has been deleted
}
