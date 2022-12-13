#include <stdio.h>
#include "options.h"
#include "addemp.h"
#include "showdata.h"
#include <string.h>
#include <stdbool.h>


void totalrecord()
{
    FILE *fp = fopen("employee.csv", "r");
    int current_line = 0;
    bool keep_reading = true;  
    char buffer[2048];
    do 
    {
        fgets(buffer, 2048, fp);
        if (feof(fp))
        {
            keep_reading = false;
            break;
        }
  
        current_line++;

    } while (keep_reading);

    printf("\nTotal number of records: %d\n", current_line - 1);
    fclose(fp);

    options();
}
