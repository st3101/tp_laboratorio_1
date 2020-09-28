#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;

int initEmployees(eEmployee list[], int len);
int addEmployees(eEmployee list[],int len);
void printAnEmployees(eEmployee list);
int printfEmployees(eEmployee list[],int len);


#endif // ARRAYEMPLOYEES_H_INCLUDED

