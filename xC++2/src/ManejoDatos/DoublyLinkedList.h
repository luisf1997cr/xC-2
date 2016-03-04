/*
 * SimpleList.h
 *
 *  Created on: 3 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_MANEJODATOS_DOUBLYLINKEDLIST_H_
#define SRC_MANEJODATOS_DOUBLYLINKEDLIST_H_
#include <iostream>

class DoublyLinkedList {

public:
	 DoublyLinkedList();
	~DoublyLinkedList();
	void insert_front(int);
	void insert_back(int);
	int delete_front();
	int delete_back();
	bool is_empty();
	void display();
	int length();
	void search(int);

private:
	Node* head;
	Node* tail;
	int size;
};

#endif /* SRC_MANEJODATOS_DOUBLYLINKEDLIST_H_ */
