/*
 * SimpleList.cpp
 *
 *  Created on: 3 de mar. de 2016
 *      Author: gabriel
 */

#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList()
{
	head = tail = NULL;
	size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::insert_front(int value)
{
	Node* temp = new Node(value);

	if (head == NULL)
		head = tail = temp;
	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	size++;
}

void DoublyLinkedList::insert_back(int value)
{
	Node* temp = new Node(value);

	if (tail == NULL)
		head = tail = temp;
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	size++;
}

int DoublyLinkedList::delete_front()
{
	if (!is_empty())
	{
		Node* temp = head;
		if (head == tail)
		{
			tail = NULL;
		}
		int delValue = temp->data;
		head = head->next;

		delete temp;

		size--;

		return delValue;

	}
	return 0;
}

int DoublyLinkedList::delete_back()
{
	if (!is_empty())
	{
		Node* temp = tail;
		if (head == tail)
		{
			head = NULL;
		}
		int delValue = temp->data;
		tail->next = NULL;
		tail = tail->prev;

		delete temp;

		size--;

		return delValue;

	}
	return 0;
}

bool DoublyLinkedList::is_empty()
{
	if (size <= 0)
	{
		return true;
	}

	return false;
}

void DoublyLinkedList::display()
{
	Node* temp = head;

	std::cout << "\n\nDisplay in forward order\n";
	while (temp != NULL)
	{
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
	std::cout << " NULL";
}

int DoublyLinkedList::length()
{
	return size;
}

void DoublyLinkedList::search(int value)
{
	if (!is_empty())
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->data == value)
			{
				std::cout << "YES! got it." << std::endl;
				break;
			}
			temp = temp->next;
		}
	}
	else
	{
		std::cout << "List is empty" << std::endl;
	}
}
