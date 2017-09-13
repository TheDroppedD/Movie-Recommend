/*
 * Node.hpp
 *
 *  Created on: Dec 7, 2016
 *      Author: Frank
 */

#ifndef NODE_HPP_
#define NODE_HPP_

#include <iostream>
#include <string>
using namespace std;

class Node {
	friend class movieList;
public:
	Node *next;
	Node *prev;
	Node *left;
	Node *right;
	Node *parent;
	string title;
	string genre;
	int rating;
	Node(string t, string g, int r);
	Node();
	void printNode();
};



#endif /* NODE_HPP_ */
