/** \brief Carga a los empleados del archivo data.csv (TEXTO).
 *
 * \param path en un char* con el nombre del archivo.
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga a los empleados del archivo data.bin (BINARIO).
 *
 * \param path en un char* con el nombre del archivo.
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Agrega al linkerlis un empleado.
 *
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.

 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Edita los campos de la estructura empleados
 *
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief quita un elemento de la estructura empleados.
 *
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Lista empleados.
 *
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordena empleados
 *
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de empleados en un archivo data.csv (TEXTO).
 *
 * \param path en un char* con el nombre del archivo.
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Guarda los datos de empleados en un archivo data.bin (BINARIO).
 *
 * \param path en un char* con el nombre del archivo.
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si funciono.
 *         int 1 si no funciono.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Busca que existencia del id en empleados
 *
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si no lo encontro.
 *         int 1 si lo encontro.
 */
int controller_buscarExistenciaId(LinkedList* pArrayListEmployee,char* id);

/** \brief Libera de memoria ram linkerlist y empleados
 *
 * \param pArrayListEmployee en un LinkedList* con la dirrecion de memoria de la lista.
 * \return int 0 si libero.
 *         int 1 si no habia nada que liberar.
 */
int controller_liberar(LinkedList* pArrayListEmployee);

