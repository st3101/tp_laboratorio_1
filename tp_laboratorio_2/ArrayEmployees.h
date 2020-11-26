#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#include "ArrayEmployees.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param limite int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initEmployees(eEmployee array[],int limite);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list Employee* Pointer to array of employees
 * \param limite int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer or withoutfree space] - (0) if Ok
 */
int addEmployees(eEmployee array[],int limite);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param aux int*
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee array[],int limite,int*aux);
/** \brief edit employees
 *
 * \param list Employee*
 * \param aux int*
 * \return
 *
 */

int editEmplotee(eEmployee array[],int*aux);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param limite int
 * \return 0
 *
 */
int printEmployees(eEmployee array[],int limite);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param limite int
 * \param aux int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee array[],int limite,int*aux);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param limite int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informeEmpoyee(eEmployee array[],int limite);
/** \brief average employees
 *
 * \param list Employee*
 * \param limite int
 * \return 0
 *
 */
int promedioSalary(eEmployee array[],int limite);
/** \brief only allows letters
 *
 * \param list Employee*
 * \return it returns [0] if it works and [1] if it doesn't work
 *
 */
int esSoloLetras(char str[]);
/** \brief
 *
 * \param list Employee*
 * \return it returns [0] if it works and [1] if it doesn't work
 *
 */
int esAlfaNumerico(char str[]);


#endif // ARRAYEMPLOYEES_H_INCLUDED
