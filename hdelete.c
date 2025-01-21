#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "health.h"

double hdeleterecord() 
{
    int d_id, found = 0;
    FILE *file, *tempfile;
    char line[256];

    printf("Enter the ID of the Healthworker to delete: ");
    scanf("%d", &d_id);

    file = fopen("health_w.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    tempfile = fopen("temp.txt", "w");
    if (tempfile == NULL) {
        printf("Error: Could not create temporary file.\n");
        fclose(file);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) 
    {
        if (strstr(line, "ID") != NULL) {
            fputs(line, tempfile);
            continue;
        }

        int id;
        sscanf(line, "%d", &id);

        if (id == d_id) 
        {
            found = 1;
            continue;
        }

        fputs(line, tempfile);
    }

    fclose(file);
    fclose(tempfile);

    if (found)
    {
       
        remove("health_w.txt");
        rename("temp.txt", "health_w.txt");
        printf("Record with ID %d has been deleted successfully.\n", d_id);
    } 
    else 
    {
        printf("No record found with ID %d.\n", d_id);
        remove("temp.txt"); 
    }

    return 0;
}
