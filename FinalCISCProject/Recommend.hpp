/*
 * Recommen.hpp

 *
 *  Created on: Dec 9, 2016
 *      Author: Frank Hulmes and Alvie Hossain
 */

#ifndef RECOMMEND_HPP_
#define RECOMMEND_HPP_

#include "Node.hpp"
#include "MovieList.hpp"
#include <string>

class Recommend{
	MovieList *masterlist;
	MovieList *comedy;
	MovieList *action;
	MovieList *horror;
	MovieList *adventure;
	MovieList *family;
	bool isSorted;
public:
	Recommend();
	~Recommend();
	void rec();
	void recBest(int g);
	void recSim(string t);
	int findInd(MovieList *arr, string t);
	MovieList *makeGenre(string g);
};


#endif /* RECOMMEND_HPP_ */
