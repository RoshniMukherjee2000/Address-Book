#ifndef CONTACT_H 
#define CONTACT_H  //define the file
#define MAX_CONTACTS 300 //maximum number of contacts we can store

#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct  // struct includes Name,Phone number and email of each person 
{
    char name[50];// Contact name
    char phone[20];// Contact phone number
    char email[50];// Contact email
} Contact;
// Structure to store the address book information
typedef struct 
{
    Contact contacts[MAX_CONTACTS];//  to the array of contacts
    int contactCount;// Number of contacts in the address book
} AddressBook;

void createContact(AddressBook *addressBook);// Function to create a new contact
void searchContact(AddressBook *addressBook);// Function to search for a contact
void editContact(AddressBook *addressBook); // Function to edit an existing contact
void deleteContact(AddressBook *addressBook);// Function to delete a contact
void listContacts(AddressBook *addressBook);// Function to list all contacts
void initialize(AddressBook *addressBook);// Function to initialize the address book
int search_name(AddressBook *addressBook);
int search_phone(AddressBook *addressBook);
int search_email(AddressBook *addressBook);
void save_contact(AddressBook *AddressBook);//Function to save contacts
#endif
