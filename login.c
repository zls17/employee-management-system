#include <stdio.h>
#include <string.h>
#include "options.h"
int login()
{
    FILE *fp = fopen("password.txt", "r");
    char pass[100];
    printf("\n************************");
    printf("\nEnter password: ");
    scanf("%s", pass);
    printf("************************\n");
    char fpass[100];

    while (!feof(fp))
    {
        fgets(fpass, 100, fp);
    }

    if (strcmp(pass, fpass) == 0)
    {
        options();
    }
    else
    {
        printf("\nInvalid Password!\n\n");
        return -1;
    }

}