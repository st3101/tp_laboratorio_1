/** \brief parsea los datos desde el archivo data.cvs (TEXTO)
 *
 * \param pFile en un FILE* puntero al archivo.
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief parsea los datos desde el archivo data.bin (BINARIO).
 *
 * \param pFile en un FILE* puntero al archivo.
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return int 0 si funciono
 *         int -1 si no funciona
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
