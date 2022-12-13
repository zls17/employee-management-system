#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "addemp.h"
#include "login.h"

void line()
{
    printf("\n\n");
}

int main()
{
    int loginstatus;
    line();
    printf("\n********************************\n");
    printf("\n*  Employee Management System  *\n");
    printf("\n********************************\n");
    line();
    loginstatus = login();
    if (loginstatus == -1)
    {
        exit(1);
    }
    line();
    options();
}