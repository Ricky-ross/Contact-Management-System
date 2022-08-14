// Contact management system

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#include<process.h>
#include<dos.h>

void addContact();
void viewContact();
void editContact();
void searchContact();
void deleteContact();
FILE *fp, *ft;

struct myContacts
{
	char name[20];
	char email[30];
	char ph[10];

}contact;

int main()
{
	int choice;
	system("cls");
	printf("\n\n\t--------------------Contact Management System------------------\t\n\n");
	printf("\n\n\t Main Menu \t\n");
	printf("\n\t[1] Add Contact");
	printf("\n\t[2] View Contact");
	printf("\n\t[3] Search Contact");
	printf("\n\t[4] Edit Contact");
	printf("\n\t[5] Delete Contact");
	printf("\n\t[6] Exit");

	printf("\n\n\t Enter your choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
				addContact();
				break;

		case 2:
				viewContact();
				break;

		case 3:
				searchContact();
				break;

		case 4:
				editContact();
				break;

		case 5:
				deleteContact();
				break;

		case 6:
				exit(1);
				break;

		default:
				printf("Enter valid choice");
				main();
	}

}

void addContact()
{
	system("cls");
	printf("Enter Name: ");
	scanf("%s",contact.name);
    fflush(stdin);
	printf("Enter email id:");
	gets(contact.email);
	fflush(stdin);
	printf("Enter Phone Number:");
    gets(contact.ph);
    
	if(strlen(contact.ph)==10)
	{
fp=fopen("contact.txt","a");
		fwrite(&contact,sizeof(contact),1,fp);
		printf("\n\n\t Contact Saved Succesfully!\n");
		getch();
fclose(fp);

	
	}

	else
	{
		printf("Please Enter 10 Digit Phone Number!");
		getch();
	}
	main();
}

void viewContact()
{
system("cls");
int i;
	printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\n=================================================================\n\n");
	for(i=97; i<=122; i++)
     {


	fp=fopen("contact.txt","r");
            fflush(stdin);
            int found=0;
            while(fread(&contact,sizeof(contact),1,fp)==1)
            {
                if(contact.name[0]==i || contact.name[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %s \nEmail\t: %s\n",contact.name,contact.ph,contact.email);

                    found++;
                }
            }
            if(found!=0)
            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);
                
            }
            fclose(fp);
        }
        getch();

	main();
}
void searchContact(){
	system("cls");

            int i,found=0;
	char query[30];
            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");
            fflush(stdin);
            gets(query);
            int l=strlen(query);

	int ch;
            fp=fopen("contact.txt","r");
            system("cls");
            printf("\n\n..::Search result for '%s' \n===================================================\n",query);
            while(fread(&contact,sizeof(contact),1,fp)==1)
            {   char name[100];
                for(i=0; i<=l; i++)
                name[i]= contact.name[i];
                name[l]='\0';
                if(strcmp(name,query)==0)
                {
                    printf("\n..::Name\t: %s\n..::Phone\t: %s \n..::Email\t: %s\n", contact.name, contact.ph , contact.email);
                    
                    found++;
                    
                }
            }
            if(found==0)
                printf("\n..::No match found!");
            else
                printf("\n..::%d match(s) found!",found);
            fclose(fp);

getch();
        main();

}
void editContact()
{
system("cls");

           fp=fopen("contact.txt","r");
           ft=fopen("temp.dat","a");
           fflush(stdin);
        	char name[30];
        printf("..::Edit contact\n===\n\n\t..::Enter the name of contact to edit :");
        gets(name);
    while(fread(&contact,sizeof (contact),1,fp)==1)
{
            if(stricmp(name,contact.name)!=0)
            fwrite(&contact,sizeof(contact),1,ft);
}
   fflush(stdin);
   printf("\n\n..::Editing '%s'\n\n",name);
   printf("..::Enter name :");
   scanf("%s",contact.name);
   fflush(stdin);
   printf("..::Enter phone number :");
   gets(contact.ph);
   fflush(stdin);
   printf("..::Enter email address :");
   gets(contact.email);
   printf("\n");
   fwrite(&contact,sizeof(contact),1,ft);
   fclose(fp);
   fclose(ft);
   remove("contact.txt");
   rename("temp.dat","contact.txt");
   main();
}
void deleteContact(){
system("cls");
fflush(stdin);
printf("\n\n\t..::Delete a contact\n\t..::Enter the name of contact to delete:");
char query[30];
gets(query);
fflush(stdin);

fp=fopen("contact.txt ","r");
ft=fopen("temp.dat","a");
while(fread(&contact , sizeof (contact),1,fp)!=0)
{
    if ( stricmp  (query , contact.name)!=0)
         {
		   fwrite(&contact,sizeof (contact),1,ft); 
		   
	}
}
printf("Deleted  contact successfully!!");
	 getch();
fclose(fp);
fclose(ft);
remove("contact.txt");
rename("temp.dat","contact.txt");
main();

}
