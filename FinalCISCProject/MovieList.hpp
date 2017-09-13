/*
 * MovieList.hpp

 *
 *  Created on: Dec 8, 2016
 *      Author: Frank Hulmes and Alvie Hossain
 */

#ifndef MOVIELIST_HPP_
#define MOVIELIST_HPP_
#include "Node.hpp"
#include <string>

class MovieList{
	friend class Recommend;
	int size;
	Node *first;
	Node *last;
	Node *moviearr;

public:
	MovieList();
	~MovieList();
	void printLL();
	void addFirst(string t, string g, int r);
	void addAtFirst(string t, string g, int r);
	void insertUnique(string t, string g, int r);
	Node *convertToArray();
	void createList();
	void makeHeap();
	void heapSort();
	void recommend();
	void findRecBest();
	void findRecSim();
	void heapify(int i, int heapsize);
	Node *deleteMovie(string k);
};




#endif /* MOVIELIST_HPP_ */
