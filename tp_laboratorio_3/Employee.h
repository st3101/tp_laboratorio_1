#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crear un nuevo empleado.
 *
 * \param void
 * \return Employee* si encuentra lugar en memoria.
 *         NULL si no hay lugar en memoria.
 */
Employee* employee_new();

/** \brief Crea un empleado con datos hardcodeados.
 *
 * \param idStr en un en char* que tiene id.
 * \param nombreStr en un char* que tiene el nombre.
 * \param horasTrabajadasStr en un char* que tiene las horas trabajadas.
 * \param sueldoStr en un char* que tiene el sueldo.
 * \return Employee* si encuentra lugar en memoria.
           NULL si no hay lugar en memoria.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief libera en memoria el empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \return void
 */

void employee_delete(Employee* this);

/** \brief Aplica un id a un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param id en un int que tiene el id
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_setId(Employee* this,int id);

/** \brief Obtiene un id de un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param id en un int* que obtiene el id.
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_getId(Employee* this,int* id);

/** \brief Aplica un nombre a un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param nombre en un char* que tiene el nombre
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene un nombre de un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param nombre en un char* que obtiene el nombre.
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Aplica un horas trabajadas a un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param horasTrabajadas en un int que tiene las horas trabajadas
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene un horas trabajas de un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param horasTrabajadas en un int* que obtiene las horas trabajadas.
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Aplica un sueldo a un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param sueldo en un int que tiene el sueldo.
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene un sueldo de un empleado
 *
 * \param this en un Employee* que tiene un empleado.
 * \param sueldo en un int* que obtiene el sueldo.
 * \return int 0 si funciono.
 *         int -1 si no funciono.
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Compara generico por nombre.
 *
 * \param e1 en un void* generico uno.
 * \param e2 en un void* generico dos.
 * \return int 1 e2 es mayo a e1.
 *         int -1 e2 es menor e1.
 *         int 0 e2 y e1 son iguales
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief Compara generico por id.
 *
 * \param e1 en un void* generico uno.
 * \param e2 en un void* generico dos.
 * \return int 1 e2 es mayo a e1.
 *         int -1 e2 es menor e1.
 *         int 0 e2 y e1 son iguales
 */
int employee_CompareById(void* e1, void* e2);

#endif // employee_H_INCLUDED
