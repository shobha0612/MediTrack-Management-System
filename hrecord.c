#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "health.h"

double viewhealthworker()
{
    int id, searchId;
    char name[50], gender[15],specialization[50],contact[15];
    int found = 0;

    printf("Enter the ID of the healthworker to view: ");
    scanf("%d", &id);

    FILE *file = fopen("health_w.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char headerLine[200];
    fgets(headerLine, sizeof(headerLine), file); 

    char line[200];
    while (fgets(line, sizeof(line), file)) 
    {
        sscanf(line, "%d %s %s %s %s", &searchId, name, gender, specialization, contact);

        if (searchId == id) {
            printf("Healthworker Found!\n");
            printf("ID: %d\n", searchId);
            printf("Name: %s\n", name);
            printf("Gender: %s\n", gender);
            printf("DOB: %s\n", specialization);
            printf("Contact: %s\n", contact);
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("No Healthworker found with ID %d\n", id);
    }

    fclose(file);
    return 0;
}
