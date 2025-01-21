#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"health.h"
double addpatients()
{
    int id; 
    char name[50], gender[15], dob[20],contact[15];
    
    FILE *file;
    file = fopen("patient.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0) {
        fprintf(file, "ID Name Gender DoB Contact\n");
        fflush(file);
    }

        printf("ID: ");
        scanf("%d", &id);

        printf("Name: ");
        getchar(); 
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; 

        printf("Gender (Male/Female): ");
        fgets(gender, sizeof(gender), stdin);
        gender[strcspn(gender, "\n")] = '\0'; 

        printf("Date of Birth (MM-DD-YYYY): ");
        fgets(dob, sizeof(dob), stdin);
        dob[strcspn(dob, "\n")] = '\0'; 

        printf("Contact: ");
        fgets(contact, sizeof(contact), stdin);
        contact[strcspn(contact, "\n")] = '\0'; 

        
        printf("\nDEBUG: %d %s %s %s %s\n", id, name, gender, dob, contact);
        
        if (strlen(name) == 0 || strlen(gender) == 0 || strlen(dob) == 0 || strlen(contact) == 0) 
        {
        printf("All fields are required.\n");
        return 1;
        }

        
        printf("Writing to file...\n");
        fprintf(file, "%d %s %s %s %s\n", id, name, gender, dob, contact);
        fflush(file); 
        printf("Write successful.\n");
    

    printf("\nData saved to 'patient.txt' successfully!\n");

    fclose(file);
    return 0;
}
