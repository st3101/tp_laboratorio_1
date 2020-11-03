/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

/** \brief Crea un nuevo linkerlis en memoria de manera dinamica.
 *
 * \param void.
 * \return LinkerList* NULL si no hay lugar en memoria
 *         LinkerList* puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void);

/** \brief Retorno cantidad elemento de la lista
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return int cantidad de elementos de la lista.
 *         int -1 si es null.
 */
int ll_len(LinkedList* this);

/** \brief permite realizar un text en la funcion getNode
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param nodeIndex en un int indice del nodo a obtener
 * \return puntero si funciono.
 *         NULL si no funciono.
 */
Node* test_getNode(LinkedList* this, int nodeIndex);

/** \brief Realiza un test a la funcion getNode
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param nodeIndex de un int con la ubicacion donde se agrega el nodo
 * \param puntero de un void* a ser contenido en la nueva ubicacion.
 * \return int 0 si funciono correcto.
 *         int -1 si no funciono.
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief agrega un elemento a la lista.
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param pElemento en un void* con la direccion del elemento
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_add(LinkedList* this, void* pElement);

/** \brief Busca un elemento de la lista.
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista.
 * \param index en un int con ubicacion de elemento a obtener.
 * \return int 0 si funciono
 *         int NULL si no funciona
 */
void* ll_get(LinkedList* this, int index);

/** \brief Remueve un elemento de la lista
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param indes en un int con la ubicacion del elemento
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_remove(LinkedList* this,int index);


/** \brief Elemina todos los elemento de la lista.
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_clear(LinkedList* this);

/** \brief Elemina todos los elemento de la lista y el linkerList.
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_deleteLinkedList(LinkedList* this);


/** \brief Busca el indice del elemento
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param puntero en un void* a buscar
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_indexOf(LinkedList* this, void* pElement);


/** \brief Indica si la lista esta vacia
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return int 1 si no esta vacia
 *         int 0 si esta vacia
 *         int -1 si no funciona o es null
 */
int ll_isEmpty(LinkedList* this);


/** \brief ordena los elemento utilizando otra funcion
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param pFunc en un int con la funcion que indica la diferencia.
 * \param order en un int que indica el tipo de ordenamiento 0 desedente y 1 asendente.
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);


/** \brief pisa un elemento de la lista
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param index en un int en la ubicacion.
 * \param pElement en un void* con la direccion de memoria del elemento.
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_set(LinkedList* this, int index,void* pElement);


/** \brief Inserta un nuevo elemento a lista.
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param index en un int en la ubicacion.
 * \param pElement en un void* con la direccion de memoria del elemento.
 * \return int 0 si funciono
 *         int -1 si no funciona
 */
int ll_push(LinkedList* this, int index, void* pElement);


/** \brief Eleminar un elemento y retornar su puntero.
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param index de un int con la ubicacion
 * \return void* direccion de memoria si funciono.
 *         int NULL si no funciona.
 */
void* ll_pop(LinkedList* this,int index);


/** \brief Determina si hay elemento pasado por parametro
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param pElement de un void* con la direccion de memoria del elemento.
 * \return int 0 si no contiene elementos.
 *         int -1 si es NULL.
 *         int 1 si contiene el elemento.
 */
int ll_contains(LinkedList* this, void* pElement);


/** \brief determina si todos los elemento de lis lista se encuentra en la otra
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return int 0 si no estan contenidos.
 *         int -1 alguno de los elementos es NULL.
 *         int 1 si todos los elementos estan contenidos.
 */
int ll_containsAll(LinkedList* this,LinkedList* this2);


/** \brief Crea y retona una lista con los elementos indicados.
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \param for en un int de donde se copian los elementos
 * \param to en un int hasta que cual copiar.
 * \return LinkerList* si no hay lugar en memoria o from es menor que el len de la lista o el indice es mayor o igual al len
 *         LinkerList* con la direccion de memoria si funciono.
 */
LinkedList* ll_subList(LinkedList* this,int from,int to);

/** \brief Crea y retonar una nueva lista con los elementos de la lista
 *
 * \param this en un LinkedList* con la direccion de memoria de la lista
 * \return LinkerList* NULL si no hay lugar
 *         LinkerList con la direccion de memoria si funciono.
 */
LinkedList* ll_clone(LinkedList* this);


