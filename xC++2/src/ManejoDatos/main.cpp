//**************************************************************
//  main.cpp
//  HashTable
//
//  Created by Kar Beringer on June 19, 2014.
//  Demonstrate a simple Hash Table in C++.
//  Implements a Linked List class.
//**************************************************************

#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Ficheros.h"

int main()
{

	/*
	void* n = malloc(9);
	void* m = malloc(3);
	void* o = malloc(8);
	void* p = malloc(1);
	void* r = malloc(4);


	HashTable<void*> *table= new HashTable<void*>();

	NodoSimple<void*> * A = new NodoSimple<void*> {"Apple", &n, NULL};
	NodoSimple<void*> * B = new NodoSimple<void*> {"Banana", &m, NULL};
	NodoSimple<void*> * C = new NodoSimple<void*> {"Caterpillar", &o, NULL};
	NodoSimple<void*> * D = new NodoSimple<void*> {"Dog", &p, NULL};
	NodoSimple<void*> * E = new NodoSimple<void*> {"Elephant", &r, NULL};

	table->insertItem(A);
	table->insertItem(B);
	table->insertItem(C);
	table->insertItem(D);
	table->insertItem(E);

	table->printTable();
	table->printHistogram();

	table->removeItem("Apple");

	table->printTable();
	table->printHistogram();

	NodoSimple<void*> * result = table->getItemByKey("Banana");
	cout << result -> val << endl;
	**/

	char st[] = "int y //x include";
	char sd[] = "int y";

	Ficheros m;

	bool c= m.contiene(sd);

	cout << c<<endl;


	return 0;
}
