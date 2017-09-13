/*
 * FinalProject.cpp

 *
 *  Created on: Dec 8, 2016
 *      Author: Frank Hulmes and Alvie Hossain
 */
#include "MovieList.hpp"
#include "Recommend.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <stdio.h>
#include <sstream>
using namespace std;

int main() {
	Recommend *main = new Recommend();
	main->rec();
}
