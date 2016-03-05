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

//*****************************************************************
// List items are keys with pointers to the next item.
//*****************************************************************
/*
 * struct NodoSimple
{
    string key;
    NodoSimple * next;
};
**/
//*****************************************************************
// Linked lists store a variable number of items.
//*****************************************************************
template<class AnyType>
class LinkedList
{
private:
    // Head is a reference to a list of data nodes.
    NodoSimple<AnyType> * head;

    // Length is the number of data nodes.
    int length;

public:
    // Constructs the empty linked list object.
    // Creates the head node and sets length to zero.
    LinkedList();

    // Inserts an item at the end of the list.
    void insertItem( NodoSimple<AnyType> * newItem);

    /**
     * @breif Metodo inserta el dato a la lista
     * @param pItem Item a ingresar
     */
    void insertItem(AnyType* pItem);

    // Removes an item from the list by item key.
    // Returns true if the operation is successful.
    bool removeItem( string itemKey );

    // Searches for an item by its key.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    NodoSimple<AnyType> * getItem( string itemKey );

    /**
     * @brief Metodo devuelve el dato segun la clave
     * @param pItemKey Clave con la que se encuentra guardada
     * @return <class AnyType> Dato de la lista
     */
    AnyType* getDataItem(string pItemKey);

    // Displays list contents to the console window.
    void printList();

    // Returns the length of the list.
    int getLength();

    // De-allocates list memory when the program terminates.
    ~LinkedList();
};


// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
template<class AnyType>
LinkedList<AnyType>::LinkedList()
{
    head = new NodoSimple<AnyType>{"c", NULL, NULL};
    head -> next = NULL;
    length = 0;
}

// Inserts an item at the end of the list.
template <class AnyType>
void LinkedList<AnyType>::insertItem( NodoSimple<AnyType> * newItem )
{
    if (!head -> next)
    {
        head -> next = newItem;
        length++;
        return;
    }
    NodoSimple<AnyType> * p = head;
    NodoSimple<AnyType> * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newItem;

    newItem -> next = NULL;
    length++;
}

template<class AnyType>
void LinkedList<AnyType>::insertItem(AnyType* pItem){
	NodoSimple<AnyType> *nodo = new NodoSimple<AnyType>{"c", pItem, NULL};
	insertItem(nodo);
}

// Removes an item from the list by item key.
// Returns true if the operation is successful.
template<class AnyType>
bool LinkedList<AnyType>::removeItem( string itemKey )
{
    if (!head -> next) return false;
    NodoSimple<AnyType> * p = head;
    NodoSimple<AnyType> * q = head;
    while (q)
    {
        if (q -> key == itemKey)
        {
            p -> next = q -> next;
            free (q);
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

// Searches for an item by its key.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
template<class AnyType>
NodoSimple<AnyType> * LinkedList<AnyType>::getItem( string itemKey )
{
    NodoSimple<AnyType> * p = head;
    NodoSimple<AnyType> * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p -> key == itemKey))
            return p;
        q = p -> next;
    }
    return NULL;
}

template<class AnyType>
AnyType* LinkedList<AnyType>::getDataItem(string pItemKey){
	NodoSimple<AnyType>* nodo = getItem(pItemKey);
	return nodo->val;
}

// Displays list contents to the console window.
template<class AnyType>
void LinkedList<AnyType>::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    NodoSimple<AnyType> * p = head;
    NodoSimple<AnyType> * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p -> val; //AQUI CAMBIE KEY POR VAL
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
template<class AnyType>
int LinkedList<AnyType>::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
template<class AnyType>
LinkedList<AnyType>::~LinkedList()
{
    NodoSimple<AnyType> * p = head;
    NodoSimple<AnyType> * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

#endif

//*****************************************************************
// End of File
//*****************************************************************
