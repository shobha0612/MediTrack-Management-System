#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"health.h"
double addhealthworker()
{
    int id; 
    char name[50], gender[15],specialization[50],contact[15];
    
    FILE *H_file;
    H_file = fopen("health_w.txt", "w+");
    if (H_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fseek(H_file, 0, SEEK_END);
    if (ftell(H_file) == 0) {
        fprintf(H_file, "ID Name Gender Specialization Contact\n");
        fflush(H_file);
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

        printf("Specialization: ");
        fgets(specialization, sizeof(specialization), stdin);
        specialization[strcspn(specialization, "\n")] = '\0'; 

        printf("Contact: ");
        fgets(contact, sizeof(contact), stdin);
        contact[strcspn(contact, "\n")] = '\0'; 

        
        printf("\nDEBUG: %d %s %s %s %s\n", id, name, gender,specialization,contact);

         if (strlen(name) == 0 || strlen(gender) == 0 || strlen(specialization) == 0 || strlen(contact) == 0) 
        {
        printf("All fields are required.\n");
        return 1;
        }

        printf("Writing to file...\n");
        fprintf(H_file, "%d %s %s %s %s\n", id, name, gender,specialization,contact);
        fflush(H_file); 
        printf("Write successful.\n");
    

    printf("\nData saved to 'health_w.txt' successfully!\n");

    fclose(H_file);
    return 0;
}
