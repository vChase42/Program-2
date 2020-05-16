// utility.h
// Andy Wu, Chase Alcorn
#ifndef utility_H
#define utility_H

#include <iostream>
#include <fstream>
#include "movies.h"

class movie {            //implement this class once BST is mostly done.
public:
	movie();
	//movie(ifstream& file);   //movie constructor that initializes BST with a csv file

	~movie();

	void sort(); //possibly implement this function

	void searchPrefix(); //

private:
	BST list;

};



#endif