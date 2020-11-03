#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

/** \brief Pide un ententero.
 *
 * \param char* mensaje un mensaje a mostrar cuando se pide el entero.
 * \return retorno lo ingresado en teclado.
 */
int getInt (char mensaje[]);

/** \brief Pide un flotante.
 *
 * \param char* mensaje mensaje a mostrar cuando se pide el flotante.
 * \return retorna lo ingresado en teclado
 */
float getFloat (char mensaje[]);

/** \brief Pide un string.
 *
 * \param char* mensaje mensaje a mostrar cuando se pide el string
 * \return retorna lo ingresado en teclado.
 *
 */
char getChar(char mensaje[]);

/** \brief Obtiene un entero entre dos parametros MAX y MIN.
 *
 * \param int min entero minimo.
 * \param int max entero maximo.
 * \param char* pregunta mensaje a mostrar al pedir dato.
 * \return retorna un numero ingresado entre MAX y MIN.
 *
 */
int getIntMinMax(int min,int max,char pregunta[]);

/** \brief Obtiene un flotante entre dos parametros MAX y MIN.
 *
 * \param float min float minimo.
 * \param float max float maximo.
 * \param char* pregunta mensaje a mostrar al pedir dato.
 * \return numero ingresado entre MAX y MIN.
 *
 */
float getFloatMinMax(float min,float max,char pregunta[]);

/** \brief Obtiene un string
 *
 * \param char* mensaje Mensaje a mostrar al pedir dato.
 * \param char* imput string a retornar.
 * \return void.
 *
 */
void getString(char mensaje[], char input[]);

/** \brief Primera Letra despues del espacio con mayusculas
 *
 * \param char* str string a tranformar despues de espacio en mayuculas.
 * \return void.
 *
 */
void stringToUpper(char str[]);

/** \brief valida si posee numero o no
 *
 * \param char* str sring a validar si tiene numeros
 * \return 1 si solo es numerico
 *         0 si no es solo numerico
 */
int esNumerico (char str[]);

/** \brief
 *
 * \param valida si es un numero telefonico.
 * \param char* str string a validar.
 * \return 1 si es un numeor de telefono
 *         0 no es un numero de telefono
 */
int esTelefono (char str[]);

/** \brief valida si es solo letras.
 *
 * \param char* str string a validar.
 * \return 1 si solo son letras.
 *         0 si no son solo letras.
 */
int esSoloLetras (char str[]);

/** \brief valida que sea letras y enteros.
 *
 * \param char* str string a validar.
 * \return 1 si son solo letras y numeros.
 *         0 si no son solo letras y numeros
 */
int esAlfaNumerico (char str[]);

/** \brief valida que sea float
 *
 * \param char* str string a validar que sea float.
 * \return 1 si es solo float.
 *         0 si no es solo float.
 */
int esNumericoFloat(char str[]);

/** \brief pedir y validar que solo sea letras
 *
 * \param char* mensaje mensaje a mostar al pedir dato
 * \param char* inPut ingresado para validar
 * \return 1 si es solo letras.
 *         0 si no es solo letras.
 */
int getStringLetras(char mensaje[], char input[]);

/** \brief Pedir y validar solo entero
 *
 * \param char* mensaje mensaje a mostar al pedir dato
 * \param char* inPut ingresado para validar
 * \return 1 si es solo entero.
 *         0 si no es solo entero.
 */
int getStringNumeros(char mensaje[], char input[]);

/** \brief Pedir y validar solo flotante
 *
 * \param char* mensaje mensaje a mostar al pedir dato
 * \param char* inPut ingresado para validar
 * \return 1 si es solo flotante.
 *         0 si no es solo flotante.
 */
int getStringNumerosFloat(char pregunta[],char input[]);

/** \brief Pedir y validar solo letras y numero
 *
 * \param char* mensaje mensaje a mostar al pedir dato
 * \param char* inPut ingresado para validar
 * \return 1 si es solo letras y numero.
 *         0 si no es solo letras y numero.
 */
int getAlfaNumerico(char mensaje[], char input[]);

/** \brief valida que este entre parametros entero.
 *
 * \param char* str entero a validar
 * \param int max entero maximo.
 * \param int min entero minimo.
 * \return 0 si esta entre los parametros MAX y MIN.
 *         1 si no esta entre los parametros MAX y MIN.
 */
int intMixMan(char str[],int min, int max);

/** \brief valida que este entre parametros de un flotante.
 *
 * \param char* str flotante a validar
 * \param int max flotante maximo.
 * \param int min flotante minimo.
 * \return 0 si esta entre los parametros MAX y MIN.
 *         1 si no esta entre los parametros MAX y MIN.
 */
int floatMinMax(char str[],int min, int max);



#endif // INPUT_H_INCLUDED
