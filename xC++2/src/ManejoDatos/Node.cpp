/*
 * Node.cpp
 *
 *  Created on: 3 de mar. de 2016
 *      Author: gabriel
 */

#include "Node.h"

Node::Node(int val, Node *sig, Node *ant) {
	data = val;
	next = *sig;
	prev = *ant;

}

Node::~Node() {
	delete data;
	delete next;
	delete prev;
}

