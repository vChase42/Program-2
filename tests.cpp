// tests.cpp
// Andy Wu, Chase Alcorn
#include <iostream>
#include <string>
#include "tests.h"
#include "movies.h"
#include "utility.h"

using namespace std;

int main(){

	BST list;

	list.insert("ooga boogaloo", 6.9);
	list.insert("money men", 6.9);
	list.insert("jumanji", 4.2);
	
	

	list.printInOrder();
}