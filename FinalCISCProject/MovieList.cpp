/*
 * MovieList.cpp
 *
 *  Created on: Dec 8, 2016
 *      Author: Frank Hulmes and Alvie Hossain
 */

#include "Node.hpp"
#include "MovieList.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
using namespace std;

MovieList::MovieList(){
	first = NULL;
	last = NULL;
	size = 0;
	moviearr = NULL;
}
MovieList::~MovieList() {
	Node *tmp = first;
	for(int i = 0; i < size; i++) {
		tmp = first->next;
		delete first;
		first = tmp;
	}
}
void MovieList::createList(){
	// Creates the master list using a text file containing the title, genre and
	// rating of each movie, and puts them into a linked list
	std::ifstream infile("movieList.txt");
	string str;
	bool comma1, comma2, comma3 = false;
	string t, g, r = "";
	while(std::getline(infile, str, ',')){
		if (comma1 == false){
			t = str;
			comma1 = true;
		}
		else if (comma1 == true && comma2 == false){
			g = str;
			comma2 = true;
		}
		else if (comma1 == true && comma2 == true &&
				comma3 == false){
			r = str;
			comma3 = true;
		}
		if (comma1 && comma2 && comma3 == true){
			comma1 = false;
			comma2 = false;
			comma3 = false;
			int rating = atoi(r.c_str());
			insertUnique(t, g, rating);
		}

	}
}

void MovieList::printLL() {
	// Prints the linked list
	Node *tmp = first;
	while (tmp != NULL) {
		tmp->printNode();
		tmp = tmp->next;
	}
}

void MovieList::addFirst(string t, string g, int r) {
	// adds the first node of the list
	first = new Node(t, g, r);
	last = first;
	size = 1;
}

void MovieList::insertUnique(string t, string g, int r) {
	//inserts a node into the list
	Node *tmp = first;
	if (tmp == NULL) {
		addFirst(t, g, r);
	}
	else {
		while (tmp->next != NULL)  {
			tmp = tmp->next;
		}
		Node *tmp2 = new Node(t, g, r);
		tmp->next = tmp2;
		tmp2->prev = tmp;
		last = tmp2;
		size++;
	}
}

Node *MovieList::convertToArray() {
	Node *retmoviearr = new Node[size];
	Node *focusNode = first;
	for(int i = 0; i<size; i++){
		retmoviearr[i] = *focusNode;
		focusNode = focusNode->next;
	}
	return retmoviearr;
}

void MovieList::makeHeap() {
	// Makes the array into a heap, make it ready to be heapsorted
	moviearr = convertToArray();
	 int heapsize;
	  heapsize = size - 1;
	  for(int i=(size/2); i >= 0; i--)
	  {
	    heapify(i, heapsize);
	  }
	  return;
}

void MovieList::heapSort() {
	//Performs a heapsort based on the rating, with the highest rating getting
	// the highest priority
	int heapsize, i;
	Node *temp;
	  heapsize = size - 1;
	  for( i= heapsize; i >= 0; i--)
	  {
	    temp = &moviearr[0];
	    moviearr[0] = moviearr[heapsize];
	    moviearr[heapsize] = *temp;
	    heapsize--;
	    heapify(0, heapsize);
	  }
}
void MovieList::heapify( int i, int heapsize)
{
  int l, r, largest;
  Node *temp;
  l = 2*i;
  r = 2*i + 1;
  if(l <= heapsize && moviearr[l].rating > moviearr[i].rating)
  {
    largest = l;
  }
  else
  {
    largest = i;
  }
  if( r <= heapsize && moviearr[r].rating > moviearr[largest].rating)
  {
    largest = r;
  }
  if(largest != i)
  {
    temp = &moviearr[i];
    moviearr[i] = moviearr[largest];
    moviearr[largest] = *temp;
    heapify(largest, heapsize);
  }
}

//
