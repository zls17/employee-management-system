#include <stdio.h>
#include "options.h"
#include "addemp.h"
struct Employee
{
    int empid;
    char empname[100];
    char gender[10];
    int salary;
    char team[100];
};


void addemp()
{
    //line();
    FILE *fp;
    fp = fopen("employee.csv", "a");
    int nemp;
    printf("How many employee's do you want to add: ");
    scanf("%d", &nemp);
    struct Employee emp[nemp];
    int tid, salary;
    char tempname[100], tgender[10], tteam[100];
    for (int i = 0; i < nemp; i++)
    {
        printf("Enter Employee's id: \n");
        scanf("%d", &emp[i].empid);
        printf("Enter employee's name: \n");
        scanf("%s", emp[i].empname);
        printf("Enter employee's gender: \n");
        scanf("%s", emp[i].gender);
        printf("Enter employee's salary: \n");
        scanf("%d", &emp[i].salary);
        printf("Enter employee's team: \n");
        scanf("%s", emp[i].team);
    }

    for (int i = 0; i < nemp; i++)
    {
        fprintf(fp, "\n%d,%s,%s,%d,%s", emp[i].empid, emp[i].empname, emp[i].gender, emp[i].salary, emp[i].team);
    }

    fclose(fp);
    options();
}