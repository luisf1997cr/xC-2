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


int main()
{

	void* str = (void *) malloc(4);
	void* str2 = (void *) malloc(4);
	void* str3= (void *) malloc(4);
	void* str4 = (void *) malloc(4);
	void* str5 = (void *) malloc(4);
	void* str6 = (void *) malloc(4);
	void* str7 = (void *) malloc(4);
	void* str8 = (void *) malloc(4);
	void* str9 = (void *) malloc(4);
	void* str0 = (void *) malloc(4);
	void* str12 = (void *) malloc(4);
	void* str123 = (void *) malloc(4);
	void* str1223 = (void *) malloc(4);
	void* str13 = (void *) malloc(4);
	void* str14 = (void *) malloc(4);
	void* str15 = (void *) malloc(4);
	void* str17 = (void *) malloc(4);


    // Create 26 Items to store in the Hash Table.
    NodoSimple * A = new NodoSimple {"Apple",str ,NULL};
    NodoSimple * B = new NodoSimple {"Banana",str3, NULL};
    NodoSimple * C = new NodoSimple {"Caterpillar",str2, NULL};
    NodoSimple * D = new NodoSimple {"Dog",str2, NULL};
    NodoSimple * E = new NodoSimple {"Elephant",str2, NULL};
    NodoSimple * F = new NodoSimple {"Fedora",str2, NULL};
    NodoSimple * G = new NodoSimple {"Goosebumps",str2, NULL};
    NodoSimple * H = new NodoSimple {"House",str2, NULL};
    NodoSimple * I = new NodoSimple {"Insects",str2, NULL};
    NodoSimple * J = new NodoSimple {"Jam",str2, NULL};
    NodoSimple * K = new NodoSimple {"Kite",str2, NULL};
    NodoSimple * L = new NodoSimple {"Limestone",str2, NULL};
    NodoSimple * M = new NodoSimple {"Mountaineering",str2, NULL};
    NodoSimple * N = new NodoSimple {"Night",str2, NULL};
    NodoSimple * O = new NodoSimple {"Open Sesame",str2, NULL};
    NodoSimple * P = new NodoSimple {"Potatoes",str2, NULL};
    NodoSimple * Q = new NodoSimple {"Quantum Mechanics",str2, NULL};
    NodoSimple * R = new NodoSimple {"Rrrrrrrrrrawr",str2, NULL};
    NodoSimple * S = new NodoSimple {"Snakes",str2,NULL};
    NodoSimple * T = new NodoSimple {"Tizzy Tube",str2, NULL};
    NodoSimple * U = new NodoSimple {"Underworld",str2, NULL};
    NodoSimple * V = new NodoSimple {"Volcanic Ash",str2, NULL};
    NodoSimple * W = new NodoSimple {"Who When What Why",str2, NULL};
    NodoSimple * X = new NodoSimple {"XXX",str2, NULL};
    NodoSimple * Y = new NodoSimple {"Yellow",str2, NULL};
    NodoSimple * Z = new NodoSimple {"Zest of Lemon",str2, NULL};

    // Create a Hash Table of 13 Linked List elements.
    HashTable table;

    // Add 3 Items to Hash Table.
    table.insertItem(A);
    table.insertItem(B);
    table.insertItem(C);
    table.printTable();
    table.printHistogram();

    // Remove one item from Hash Table.
    table.removeItem("Apple");
    table.printTable();
    table.printHistogram();


    // Add 23 items to Hash Table.
    table.insertItem(D);
    table.insertItem(E);
    table.insertItem(F);
    table.insertItem(G);
    table.insertItem(H);
    table.insertItem(I);
    table.insertItem(J);
    table.insertItem(K);
    table.insertItem(L);
    table.insertItem(M);
    table.insertItem(N);
    table.insertItem(O);
    table.insertItem(P);
    table.insertItem(Q);
    table.insertItem(R);
    table.insertItem(S);
    table.insertItem(T);
    table.insertItem(U);
    table.insertItem(V);
    table.insertItem(W);
    table.insertItem(X);
    table.insertItem(Y);
    table.insertItem(Z);
    table.printTable();
    table.printHistogram();

    // Look up an item in the hash table
    NodoSimple * result = table.getItemByKey("Snakes");
    cout << result -> val << endl;
    return 0;
}
