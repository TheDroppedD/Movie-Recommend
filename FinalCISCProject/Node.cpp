/*
 * Node.cpp
 *
 *  Created on: Dec 7, 2016
 *      Author: Frank
 */

#include "Node.hpp"
#include <iostream>
#include <string>
using namespace std;

Node::Node(string t, string g, int r) {
	title = t;
	genre = g;
	rating = r;
	next = NULL;
	prev = NULL;
	left = NULL;
	right = NULL;
	parent = NULL;
}
Node::Node() {
	title = "";
	genre = "";
	rating = -1;
	next = NULL;
	prev = NULL;
	left = NULL;
	right = NULL;
	parent = NULL;
}
void Node::printNode(){
	cout<<title<<", "<<genre<< "  Rating: "<<rating<<endl;
	return;
}


