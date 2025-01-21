#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "health.h"

double viewpatient()
{
    int id, searchId;
    char name[50], gender[15], dob[20], contact[15];
    int found = 0;

    printf("Enter the ID of the patient to view: ");
    scanf("%d", &id);

    FILE *file = fopen("patient.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char headerLine[200];
    fgets(headerLine, sizeof(headerLine), file); 

    char line[200];
    while (fgets(line, sizeof(line), file)) 
    {
        sscanf(line, "%d %s %s %s %s", &searchId, name, gender, dob, contact);

        if (searchId == id) {
            printf("Patient Found!\n");
            printf("ID: %d\n", searchId);
            printf("Name: %s\n", name);
            printf("Gender: %s\n", gender);
            printf("DOB: %s\n", dob);
            printf("Contact: %s\n", contact);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("No patient found with ID %d\n", id);
    }

    fclose(file);
    return 0;
}
