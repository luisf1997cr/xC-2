/**
 * @file LinkedList.h
 * @date 4/3/16
 * @title LinkedList
 * @brief Abstracion de una lista simple para el proyecto xC++2
 */

//*****************************************************************
//  LinkedList.h
//  HashTable
//
//  Created by Karlina Beringer on June 16, 2014.
//
//  This header file contains the Linked List class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;

#include "NodoSimple.h"

template<class AnyType>
class LinkedList
{
private:
    NodoSimple<AnyType> * _Head;
    int _Length;

public:
    /**
     * @brief Metodo constructor de LinkedList
     */
    LinkedList();

    /**
     * @brief Metodo inserta un nodo en la lista
     * @param NodoSimple<AnyType>* pNewItem
     */
    void insertItem( NodoSimple<AnyType> * pNewItem);

    /**
     * @breif Metodo inserta un elemento a la lista
     * @param AnyType* pItem
     */
    void insertItem(AnyType* pItem);

    /**
     * @brief Metodo elimina el elemento de la lista que contenga el mismo pItemKey
     * @param string pItemKey
     */
    bool removeItem( string pItemKey );

    /**
     * @brief Metodo obtiene el elemento que contiene el mismo pItemKey
     * @param string pItemKey
     * @return NodoSimple<AnyType>*
     */
    NodoSimple<AnyType> * getItem( string pItemKey );

    /**
     * @brief Metodo devuelve el nodo en la posicion
     * @param int pPosition
     * @return NodoSimple<AnyType>*
     */
    NodoSimple<AnyType> * getItemByPosition(int pPosition);

    /**
     * @brief Metodo devuelve el dato segun la clave
     * @param string pItemKey
     * @return AnyType*
     */
    AnyType* getDataItem(string pItemKey);

    /**
     * @brief Metodo imprime la lista
     */
    void printList();

    /**
     * @brief Metodo devuelve el atributo _Lenght
     * @return int
     */
    int getLength();

    /**
     * @brief Metodo destructor de LinkedList
     */
    ~LinkedList();
};


template<class AnyType>
LinkedList<AnyType>::LinkedList()
{
    this->_Head = new NodoSimple<AnyType>{"c",NULL,NULL};
    this->_Length = 0;
}

template <class AnyType>
void LinkedList<AnyType>::insertItem( NodoSimple<AnyType> * newItem )
{
    if (!_Head->getNext())
    {
        _Head->setNext(newItem);
        this->_Length++;
        return;
    }
    NodoSimple<AnyType> * p = this->_Head;
    NodoSimple<AnyType> * q = this->_Head;
    while (q)
    {
        p = q;
        q = p->getNext();
    }
    p->setNext(newItem);

    newItem->setNext(NULL);
    this->_Length++;
}

template<class AnyType>
void LinkedList<AnyType>::insertItem(AnyType* pItem){
	NodoSimple<AnyType> *nodo = new NodoSimple<AnyType>{"c", pItem, NULL};
	insertItem(nodo);
}

template<class AnyType>
bool LinkedList<AnyType>::removeItem( string itemKey )
{
    if (!_Head->getNext()) return false;
    NodoSimple<AnyType> * p = this->_Head;
    NodoSimple<AnyType> * q = this->_Head;
    while (q)
    {
        if (q->getKey() == itemKey)
        {
            p->setNext(q->getNext);
            free (q);
            this->_Length--;
            return true;
        }
        p = q;
        q = p->getNext();
    }
    return false;
}

template<class AnyType>
NodoSimple<AnyType> * LinkedList<AnyType>::getItem( string itemKey )
{
    NodoSimple<AnyType> * p = this->_Head;
    NodoSimple<AnyType> * q = this->_Head;
    while (q)
    {
        p = q;
        if ((p != this->_Head) && (p->getKey() == itemKey))
            return p;
        q = p->getNext();
    }
    return NULL;
}

template<class AnyType>
NodoSimple<AnyType>* LinkedList<AnyType>::getItemByPosition(int pPosition){
	NodoSimple<AnyType>* nodo = this->_Head;
	for(int index = 1; index < pPosition+1; index++){
		nodo = nodo->getNext();
	}
	return nodo;
}

template<class AnyType>
AnyType* LinkedList<AnyType>::getDataItem(string pItemKey){
	NodoSimple<AnyType>* nodo = getItem(pItemKey);
	return nodo->getVal();
}

template<class AnyType>
void LinkedList<AnyType>::printList()
{
    if (this->_Length == 0)
    {
        cout << "\n{ }\n";
       return;
    }
    NodoSimple<AnyType> * p = this->_Head;
    NodoSimple<AnyType> * q = this->_Head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != this->_Head)
        {
            cout << (void*)p->getVal() << ":"<< p->getKey(); //AQUI CAMBIE KEY POR VAL
            if (p->getNext()) cout << ", ";
            else cout << " ";
        }
        q = p->getNext();
    }
    cout << "}\n";
}

template<class AnyType>
int LinkedList<AnyType>::getLength()
{
    return this->_Length;
}

template<class AnyType>
LinkedList<AnyType>::~LinkedList()
{
    NodoSimple<AnyType> * p = this->_Head;
    NodoSimple<AnyType> * q = this->_Head;
    while (q)
    {
        p = q;
        q = p->getNext();
        if (q) delete p;
    }
}

#endif
