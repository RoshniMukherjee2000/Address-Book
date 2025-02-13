/*
DOCUMENTATION
----------------------
1.NAME:Roshni Mukherjee.
2.DATE:10-10-2024
3.DESCRIPTION:ADDRESS BOOK
4.SAMPLE INPUT:
..................
    1.create contact
    2.Edit contact
    3.Delete contact
    4.Remove contact
    5.SAMPLE OUTPUT
    6.List contacts
    7.DOCUMENTATION
*/
#include <stdio.h>
#include "contact.h"
#include<stdlib.h>
int main()// Main function of the Address Book program
{ 
    AddressBook book;
    initialize(&book);// Initialize the address book
    
    //all function calls should be inside the main
  // Variable to store user's menu choice
   
    while(1)
    {
         int choice=0;
          // Display the menu options to the user
        printf("\t\t\t\t\t\t\t\t~::::MENU::::~\t\t\t\t\t\t\t\t\t\t\n\n");
        printf("\t\t1.Create Contacts\n\t\t2.Delete Contacts\n\t\t3.Search Contacts\n\t\t4.Edit Contacts\n\t\t5.List Contacts\n\t\t6.Save Contacts\n\t\t7.Exit\n");
     printf("Enter your choice:");
     scanf("%d", &choice);
     getchar();
        
           //read the choice

        // Execute the corresponding function based on user's choice
        switch(choice)
        { 
            case 1:
                createContact(&book); // Function to create a new contact
                break;
            case 2:
                deleteContact(&book);// Function to delete a contact
                break;
            case 3:
                searchContact(&book);// Function to search for a contact
                break;
            case 4:
                editContact(&book);// Function to edit an existing contact
                break;
            case 5:
                listContacts(&book);// Function to list all contacts
                break;
            case 6:
                save_contact(&book);//function to save all contacts
                break;
             case 7:
		         printf("exit from the program\n");//above program exit from the program
		         return 0;
                         //     default:
        //         printf("Invalid choice. Please try again.\n");//user is choice is wrong is enter invalid please try again
 
        }
       
    } //if choise is 7 then its comeout from the loop

    
}

