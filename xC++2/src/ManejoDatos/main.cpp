//**************************************************************
//  main.cpp
//  HashTable
//
//  Created by Kar Beringer on June 19, 2014.
//  Demonstrate a simple Hash Table in C++.
//  Implements a Linked List class.
//**************************************************************

#include "HashTable.h"

int main()
{
    // Create 26 Items to store in the Hash Table.
    NodoSimple * A = new NodoSimple {"Apple", NULL};
    NodoSimple * B = new NodoSimple {"Banana", NULL};
    NodoSimple * C = new NodoSimple {"Caterpillar", NULL};
    NodoSimple * D = new NodoSimple {"Dog", NULL};
    NodoSimple * E = new NodoSimple {"Elephant", NULL};
    NodoSimple * F = new NodoSimple {"Fedora", NULL};
    NodoSimple * G = new NodoSimple {"Goosebumps", NULL};
    NodoSimple * H = new NodoSimple {"House", NULL};
    NodoSimple * I = new NodoSimple {"Insects", NULL};
    NodoSimple * J = new NodoSimple {"Jam", NULL};
    NodoSimple * K = new NodoSimple {"Kite", NULL};
    NodoSimple * L = new NodoSimple {"Limestone", NULL};
    NodoSimple * M = new NodoSimple {"Mountaineering", NULL};
    NodoSimple * N = new NodoSimple {"Night", NULL};
    NodoSimple * O = new NodoSimple {"Open Sesame", NULL};
    NodoSimple * P = new NodoSimple {"Potatoes", NULL};
    NodoSimple * Q = new NodoSimple {"Quantum Mechanics", NULL};
    NodoSimple * R = new NodoSimple {"Rrrrrrrrrrawr", NULL};
    NodoSimple * S = new NodoSimple {"Snakes", NULL};
    NodoSimple * T = new NodoSimple {"Tizzy Tube", NULL};
    NodoSimple * U = new NodoSimple {"Underworld", NULL};
    NodoSimple * V = new NodoSimple {"Volcanic Ash", NULL};
    NodoSimple * W = new NodoSimple {"Who When What Why", NULL};
    NodoSimple * X = new NodoSimple {"XXX", NULL};
    NodoSimple * Y = new NodoSimple {"Yellow", NULL};
    NodoSimple * Z = new NodoSimple {"Zest of Lemon", NULL};

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
    cout << result -> key << endl;
    return 0;
}
