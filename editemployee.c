#include <stdio.h>
#include "options.h"
#include "addemp.h"
#include "showdata.h"
#include <string.h>
#include <stdbool.h>
#define FILENAME_SIZE 1024
#define MAX_LINE 2048

void editemployee()
{

  FILE *file, *temp;
  
  // buffer will store each line from the original file
  char buffer[MAX_LINE];

  // replace will store the line of replacement text
  char replace[MAX_LINE];

  // replace_line will store the line number we wish to replace
  int replace_line = 0;
  
  // ask the user for the line number to replace, store it into replace_line
  printf("Enter Employee ID that you want to replace: ");
  scanf("%d", &replace_line);
  
  // flush stdin to get the \n char from the last scanf out, otherwise the 
  // below fgets will 'fail' as it will immediately encounter a newline
  fflush(stdin);
  
  // ask the user for the replacement line of text, store it into replace
  printf("Enter the following details:\n1.Employee ID\n2.Name\n3.Gender\n4.Salary\n5.Team\n\n\n(IMP: Please enter the values separated by commas only!\n");
  fgets(replace, MAX_LINE, stdin);
  
  // open the original file for reading, and the temp file for writing
  file = fopen("employee.csv", "r");
  temp = fopen("temp_employee.csv", "w");
  
  // check if either file failed to open, if either did exit with error status
  if (file == NULL || temp == NULL)
  {
    printf("Error opening files(s).\n");
  }
  
  // we'll keep reading the file so long as keep_reading is true
  bool keep_reading = true;

  // will keep track of the current line number we are reading from the file
  int current_line = 1;

  do 
  {
    // read the next line of the file into the buffer
    fgets(buffer, MAX_LINE, file);
    
    // if we've reached the end of the file, stop reading
    if (feof(file))
    {
         keep_reading = false;
    }
    // if the line we've reached is the one we wish to replace, write the 
    // replacement text to this line of the temp file
    else if (current_line == replace_line)
    {
      fputs(replace, temp);
    }
    // otherwise write this line to the temp file
    else 
    {
        fputs(buffer, temp);
    }
    // increment the current line as we will now be reading the next line
    current_line++;

  } while (keep_reading);
  
  fclose(file);
  fclose(temp);
  
  // delete the original file, rename temp file to the original file's name
  remove("employee.csv");
  rename("temp_employee.csv", "employee.csv");
  printf("\n\nNew Employee Added Successfully\n\n");
  options();

}
