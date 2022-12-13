#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "addemp.h"
#include "showdata.h"
#include "editemployee.h"
#include "totalrecord.h"
#include "update.h"
#include "delete.h"
void options()
{
    //line();
    printf("\n1. Add a new Employee\n");
    printf("\n2. Edit details of existing Employee\n");
    printf("\n3. Show Employee's Data\n");
    printf("\n4. Show Total Number of Records\n");
    printf("\n5. Update a record\n");
    printf("\n6. Delete a record\n");
    printf("\n7. Exit\n");
    printf("\nSelect Option: ");
    int option;
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            addemp();
            break;
        case 2:
           editemployee();
           break;
        case 3:
            showdata();
            break;
        case 4:
            totalrecord();
            break;
        case 5:
            update();
            break;
        case 6:
            delete();
            break;
        case 7:
            printf("\n\nLogged Out!\n\n");
            exit(0);
    }
    
}