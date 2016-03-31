/**
 * @file xMemoryManager.h
 * @date 3/3/16
 * @author Jose Eduardo Jimenez A
 * @title xMemoryManager
 * @brief Manejador de memoria para el proyecto xC++2
 */

#ifndef XMEMORYMANAGER_H_
#define XMEMORYMANAGER_H_

#include <stdlib.h>		//malloc
#include <iostream>		//cout
#include <sstream>		//stringstream
#include "../Structures/HashTable.h"
#include "../Structures/NodoSimple.h"
#include "../xPointer/xPointer.h"

using namespace std;

class xMemoryManager{
public:
	/**
	 * @brief Metodo solicita memoria y la devuelve un xPointer
	 * @param pSize Tamaño de memoria solicitada
	 * @return xPointer Puntero en memoria
	 */
	xPointer xMalloc(int pSize);
	/**
	 * @brief Metodo libera la memoria en el puntero
	 * @param pXPointer Puntero de la memoria a liberar
	 * @return bool Si se cumple o no la liberacion
	 */
	bool xFree(xPointer pXPointer);
	/**
	 * @brief Metodo define la memoria del xPointer con el objeto
	 * @param pXPointer Puntero
	 * @param pXObject Objeto
	 */
	void xSet(bool type, xPointer pXPointer );

	/**
	 * @brief Metodo devuelve la unica instancia del xMemoryManager
	 * @return xMemoryManager*
	 */
	static xMemoryManager* Instance();

	/**
	 * @brief Metodo devuelve el atributo _FreeMemory
	 * @return long
	 */
	long int getFreeMemory();

	/**
	 * @brief Metodo define el atributo _FreeMemory
	 * @param long
	 */
	void setFreeMemory(long int pFreeMemory);

	/**
	 * @brief Metodo devuelve el atributo _UsedMemory
	 * @return long
	 */
	long int getUsedMemory();

	/**
	 * @brief Metodo define el aributo _UsedMemory
	 */
	void setUsedMemory(long int pUsedMemory);

private:
	HashTable<xPointer> *_Memoria;
	long int _FreeMemory;
	long int _UsedMemory;

protected:
	/**
	 * @brief Metodo Constructor de xMemoryManager
	 */
	xMemoryManager();
	static xMemoryManager* m_pInstance;
	/**
	 * @brief Metodo Destructor de xMemoryManager
	 */
	virtual ~xMemoryManager();

};

#endif /* XMEMORYMANAGER_H_ */
