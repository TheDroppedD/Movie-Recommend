/*
 * Recommend.cpp

 *
 *  Created on: Dec 9, 2016
 *      Author: Frank Hulmes and Alvie Hossain
 */

#include "Node.hpp"
#include "MovieList.hpp"
#include "Recommend.hpp"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <sstream>
using namespace std;

Recommend::Recommend(){
	masterlist = new MovieList();
	masterlist->createList();
	comedy = makeGenre("comedy");
	action = makeGenre("action");
	adventure = makeGenre("adventure");
	horror = makeGenre("horror");
	family = makeGenre("family");
	isSorted = false;
}

MovieList *Recommend::makeGenre(string g){
	MovieList *list = new MovieList();
	Node *tmp = masterlist->first;
	while(tmp != NULL){
		if(tmp->genre == g){
			list->insertUnique(tmp->title, tmp->genre, tmp->rating);
		}
		tmp= tmp->next;
	}
	return list;
}

void Recommend::rec(){
	if(isSorted == false){
		comedy->makeHeap();
		comedy->heapSort();
		action->makeHeap();
		action->heapSort();
		adventure->makeHeap();
		adventure->heapSort();
		horror->makeHeap();
		horror->heapSort();
		family->makeHeap();
		family->heapSort();
		isSorted = true;
	}
	char response1;
	cout<<"Recommend by Genre or Movie Title (g/m)";
	cin>>response1;
	bool flag = true;
	while(flag){
		if(response1 == 'g'){
			int resG;
			cout<< "Pick a Genre!"<<endl;
			cout<< "1. Comedy "<< endl;
			cout<< "2. Action "<< endl;
			cout<< "3. Adventure "<< endl;
			cout<< "4. Horror "<< endl;
			cout<< "5. Family "<< endl;
			cout<<""<<endl;
			cout<< "Enter a Number (1-5):__"<< endl;
			cin>>resG;
			recBest(resG);
			flag = false;
		}
		else if (response1 == 'm'){
			string resM;
			cout<<"Enter the Movie Title: "<<endl;
			cin>>resM;
			recSim(resM);
			flag = false;
		}
		else{
			cout<<"Invalid Response, please enter a valid response"<<endl;
			rec();
		}
	}
}

void Recommend::recBest(int resG){
	if (resG == 1){
		cout<<"Our Recommendations! "<<endl;
		cout<<"-------------------------"<<endl;
		comedy->moviearr[0].printNode();
		comedy->moviearr[1].printNode();
		comedy->moviearr[2].printNode();
	}
	else if (resG == 2){
		cout<<"Our Recommendations! "<<endl;
		action->moviearr[0].printNode();
		action->moviearr[1].printNode();
		action->moviearr[2].printNode();
	}
	else if (resG == 3){
		cout<<"Our Recommendations! "<<endl;
		adventure->moviearr[0].printNode();
		adventure->moviearr[1].printNode();
		adventure->moviearr[2].printNode();
	}
	else if (resG == 4){
		cout<<"Our Recommendations! "<<endl;
		horror->moviearr[0].printNode();
		horror->moviearr[1].printNode();
		horror->moviearr[2].printNode();
	}
	else if (resG == 5){
		cout<<"Our Recommendations! "<<endl;
		family->moviearr[0].printNode();
		family->moviearr[1].printNode();
		family->moviearr[2].printNode();
	}
	char response2;
	cout<<"Do you want more recommendations? (y/n)"<<endl;
	cin>>response2;
	if (response2 == 'y'){
		rec();
	}
	else{
		return;
	}
}

void Recommend::recSim(string t){
	Node *tmp = masterlist->first;
	while (t != tmp->title){
		tmp = tmp->next;
		if (tmp == NULL){
			cout<<"Sorry, that movie is not in our database"<<endl;
			char response3;
			cout<<"Would you like to enter another movie? (y/n)"<<endl;
			cin>>response3;
			if (response3 == 'y'){
				rec();
			}
			else{
				return;
			}
		}
	}
	string nodeGenre = tmp->genre;
	if (nodeGenre == "comedy"){
		int index = findInd(comedy, t);
		cout<<"Our Recommendations! "<<endl;
		if ((index+1)< comedy->size){
			comedy->moviearr[index + 1].printNode();
		}
		if ((index+2)< action->size){
			comedy->moviearr[index + 2].printNode();
		}
		if ((index-1) >= 0){
			comedy->moviearr[index - 1].printNode();
		}
		if ((index-2) >= 0){
			comedy->moviearr[index - 2].printNode();
		}
		if((index*2 + 1)< comedy->size){
			comedy->moviearr[index*2 + 1].printNode();
		}
	}
	else if (nodeGenre == "action"){
		int index = findInd(action, t);
		cout<<"Our Recommendations! "<<endl;
		if ((index+1)< action->size){
			action->moviearr[index + 1].printNode();
		}
		if ((index+2)< action->size){
			action->moviearr[index + 2].printNode();
		}
		if ((index-1) >= 0){
			action->moviearr[index - 1].printNode();
		}
		if ((index-2) >= 0){
			action->moviearr[index - 2].printNode();
		}
		if((index*2 + 1)< action->size){
			action->moviearr[index*2 + 1].printNode();
		}
	}
	else if (nodeGenre == "adventure"){
		int index = findInd(adventure, t);
		cout<<"Our Recommendations! "<<endl;
		if ((index+1)< adventure->size){
			adventure->moviearr[index + 1].printNode();
		}
		if ((index+2)< action->size){
			adventure->moviearr[index + 2].printNode();
		}
		if ((index-1) >= 0){
			adventure->moviearr[index - 1].printNode();
		}
		if ((index-2) >= 0){
			adventure->moviearr[index - 2].printNode();
		}
		if((index*2 + 1)< adventure->size){
			adventure->moviearr[index*2 + 1].printNode();
		}
	}
	else if (nodeGenre == "horror"){
		int index = findInd(horror, t);
		cout<<"Our Recommendations! "<<endl;
		if ((index+1)< horror->size){
			horror->moviearr[index + 1].printNode();
		}
		if ((index+2)< action->size){
			horror->moviearr[index + 2].printNode();
		}
		if ((index-1) >= 0){
			horror->moviearr[index - 1].printNode();
		}
		if ((index-2) >= 0){
			horror->moviearr[index - 2].printNode();
		}
		if((index*2 + 1)< horror->size){
			horror->moviearr[index*2 + 1].printNode();
		}
	}
	else if (nodeGenre == "family"){
		int index = findInd(family, t);
		cout<<"Our Recommendations! "<<endl;
		if ((index+1)< family->size){
			family->moviearr[index + 1].printNode();
		}
		if ((index+2)< action->size){
			family->moviearr[index + 2].printNode();
		}
		if ((index-1) >= 0){
			family->moviearr[index - 1].printNode();
		}
		if ((index-2) >= 0){
			family->moviearr[index - 2].printNode();
		}
		if((index*2 + 1)< family->size){
			family->moviearr[index*2 + 1].printNode();
		}
	}

}

int Recommend::findInd(MovieList *arr, string t){
	for(int i = 0; i<arr->size; i++){
		if(arr->moviearr->title == t){
			return i;
		}
	}
}

