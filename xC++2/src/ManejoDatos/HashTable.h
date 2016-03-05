//*****************************************************************
//  HashTable.h
//  HashTable
//
//  Created by Karlina Beringer on June 18, 2014.
//
//  This header file contains the Hash Table class declaration.
//  Hash Table array elements consist of Linked List objects.
//*****************************************************************

#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

//*****************************************************************
// Hash Table objects store a fixed number of Linked Lists.
//*****************************************************************
template<class AnyType>
class HashTable
{
private:

    // Array is a reference to an array of Linked Lists.
    LinkedList<AnyType> * array;

    // Length is the size of the Hash Table array.
    int length;

    // Returns an array location for a given item key.
    int hash( string itemKey );

public:

    // Constructs the empty Hash Table object.
    // Array length is set to 13 by default.
    HashTable( int tableLength = 13 );

    // Adds an item to the Hash Table.
    void insertItem( NodoSimple<AnyType> * newItem );

    /**
     * @brief Metodo inserta el dato segun el item
     * @param pItem Item a ingresar
     */
    void insertItem(AnyType* pItem);

    // Deletes an Item by key from the Hash Table.
    // Returns true if the operation is successful.
    bool removeItem( string itemKey );

    // Returns an item from the Hash Table by key.
    // If the item isn't found, a null pointer is returned.
    NodoSimple<AnyType> * getItemByKey( string itemKey );

    /**
     * @brief Metodo devuelve el dato
     * @param pItemKey
     * @return <class AnyType>
     */
    AnyType* getDataByKey(string pItemKey);

    // Display the contents of the Hash Table to console window.
    void printTable();

    // Prints a histogram illustrating the Item distribution.
    void printHistogram();

    // Returns the number of locations in the Hash Table.
    int getLength();

    // Returns the number of Items in the Hash Table.
    int getNumberOfItems();

    // De-allocates all memory used for the Hash Table.
    ~HashTable();
};


// Constructs the empty Hash Table object.
// Array length is set to 13 by default.
template<class AnyType>
HashTable<AnyType>::HashTable( int tableLength )
{
    if (tableLength <= 0) tableLength = 13;
    array = new LinkedList<AnyType>[ tableLength ];
    length = tableLength;
}

// Returns an array location for a given item key.
template<class AnyType>
int HashTable<AnyType>::hash( string itemKey )
{
    int value = 0;
    for ( int i = 0; i < itemKey.length(); i++ )
        value += itemKey[i];
    return (value * itemKey.length() ) % length;
}

// Adds an item to the Hash Table.
template<class AnyType>
void HashTable<AnyType>::insertItem( NodoSimple<AnyType> * newItem )
{
    int index = hash( newItem -> key );
    array[ index ].insertItem( newItem );
}

template<class AnyType>
void HashTable<AnyType>::insertItem(AnyType* pItem){
	NodoSimple<AnyType> *nodo = new NodoSimple<AnyType>{"c", pItem, NULL};
	this->insertItem(nodo);
}

// Deletes an Item by key from the Hash Table.
// Returns true if the operation is successful.
template<class AnyType>
bool HashTable<AnyType>::removeItem( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].removeItem( itemKey );
}

// Returns an item from the Hash Table by key.
// If the item isn't found, a null pointer is returned.
template<class AnyType>
NodoSimple<AnyType> * HashTable<AnyType>::getItemByKey( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].getItem( itemKey );
}

template<class AnyType>
AnyType* HashTable<AnyType>::getDataByKey(string pItemKey){
	NodoSimple<AnyType> *nodo = getItemByKey(pItemKey);
	return nodo->val;
}

// Display the contents of the Hash Table to console window.
template<class AnyType>
void HashTable<AnyType>::printTable()
{
    cout << "\n\nHash Table:\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << "Bucket " << i + 1 << ": ";
        array[i].printList();
    }
}

// Prints a histogram illustrating the Item distribution.
template<class AnyType>
void HashTable<AnyType>::printHistogram()
{
    cout << "\n\nHash Table Contains ";
    cout << getNumberOfItems() << " Items total\n";
    for ( int i = 0; i < length; i++ )
    {
        cout << i + 1 << ":\t";
        for ( int j = 0; j < array[i].getLength(); j++ )
            cout << " X";
        cout << "\n";
    }
}

// Returns the number of locations in the Hash Table.
template<class AnyType>
int HashTable<AnyType>::getLength()
{
    return length;
}

// Returns the number of Items in the Hash Table.
template<class AnyType>
int HashTable<AnyType>::getNumberOfItems()
{
    int itemCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        itemCount += array[i].getLength();
    }
    return itemCount;
}

// De-allocates all memory used for the Hash Table.
template<class AnyType>
HashTable<AnyType>::~HashTable()
{
    delete [] array;
}

#endif

//*****************************************************************
// End of File
//*****************************************************************
