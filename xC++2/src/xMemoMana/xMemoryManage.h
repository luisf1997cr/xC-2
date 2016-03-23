/**
 * @file xMemoryManager.h
 * @date 3/3/16
 * @author Jose Eduardo Jimenez A
 * @title xMemoryManager
 * @brief Manejador de memoria para el proyecto xC++2
 */

#ifndef XMEMORYMANAGER_H_
#define XMEMORYMANAGER_H_

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "../Structures/HashTable.h"
#include "../Structures/NodoSimple.h"
#include "../xPointer/xPointer.h"

using namespace std;

class xMemoryManager{
public:
//	/**
//	 * @brief Metodo solicita memoria y devuelve un xPointer inicializado en 0
//	 * @param pNum Numero de elementos a guardar
//	 * @param pSize Tamaño de elementos a guardar
//	 * @return xPointer Puntero en memoria
//	 */
//	xPointer xCalloc(int pNum, int pSize);
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

	static xMemoryManager* Instance();


private:
	HashTable<xPointer> *_Memoria;

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
