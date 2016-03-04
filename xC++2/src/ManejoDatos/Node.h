/*
 * Node.h
 *
 *  Created on: 3 de mar. de 2016
 *      Author: gabriel
 */

#ifndef SRC_MANEJODATOS_NODE_H_
#define SRC_MANEJODATOS_NODE_H_

class Node {
private:
	int data;
	Node *next;
	Node *prev;
public:

	Node(int val, Node *sig, Node *ant);
	virtual ~Node();

	friend class simplelist;
};

#endif /* SRC_MANEJODATOS_NODE_H_ */
