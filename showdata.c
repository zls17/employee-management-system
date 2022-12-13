#include <stdio.h>
#include "options.h"
#include "addemp.h"
#include <string.h>
#include <stdlib.h>
void showdata()
{

	FILE* fp = fopen("employee.csv", "r");

	if (!fp)
		printf("Can't open file\n");

	else {

		char buffer[1024];

		int row = 0;
		int column = 0;

		while (fgets(buffer,
					1024, fp)) {
			column = 0;
			row++;
			if (row == 1)
				continue;
            printf("Record %d", row - 1);
			// Splitting the data
			char* value = strtok(buffer, ", ");
            int i = 1;
			while (value) {
				if (column == 0) {
					printf("\nID : ");
				}
				if (column == 1) {
					printf("Employee's Name : ");
				}
				if (column == 2) {
					printf("Gender : ");
				}
                
                if (column == 3) {
                    printf("Salary : ");
                }
                
                if (column == 4) {
                    printf("Team : ");
                }

				printf("%s\n", value);
				value = strtok(NULL, ", ");
				column++;
                i++;
			}

			printf("\n");
		}
		fclose(fp);
	}
	options();
}
