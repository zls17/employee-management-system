#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "options.h"
#define MAX_LINE 2048

void delete()
{
    FILE *file, *temp;
    char buffer[MAX_LINE];
    int delete_emp = 0;
    printf("Enter the employee ID: ");
    scanf("%d", &delete_emp);

    delete_emp++;
    file = fopen("employee.csv", "r");
    temp = fopen("temp_employee.csv", "w");
  

    bool keep_reading = true;
    int current_line = 1;
    do 
    {
        fgets(buffer, MAX_LINE, file);

        if (feof(file))
        {
            keep_reading = false;
        }
        else if (current_line != delete_emp)
        {
            fputs(buffer, temp);
        }
        current_line++;
    } while (keep_reading);

    fclose(file);
    fclose(temp);
    remove("employee.csv");
    rename("temp_employee.csv", "employee.csv");
    printf("\n\nEmployee data deleted Successfully!\n\n");
    options();
}