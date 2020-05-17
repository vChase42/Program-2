// tests.cpp
// Andy Wu, Chase Alcorn
#include <iostream>
#include <string>
#include "tests.h"
#include "movies.h"
#include "utility.h"

using namespace std;

int main(){

  // BST k;
  // if(k.comparePrefix("nOkay","NOKAYgsdfufsei")){
  //   cout << "came out true" << endl;
  // }else{
  //   cout << "came out false" << endl;
  // }
  // return 1;

    test_size();
    test_insert();
    test_searchPrefix();

    return 0;
}

void test_size(){
    BST l1, l2;
    l1.insert("money men", 6.4);
	l1.insert("ooga boogaloo", 6.9);
	l1.insert("jumanji", 4.2);
    assertEquals(3, l1.size(), "test_size 1");
    l1.insert("cloudy with a chance of meatballs", 7.5);
    assertEquals(4, l1.size(), "test_size 2");
    assertEquals(0, l2.size(), "test_size 3");
}

void test_insert(){
    BST l1, l2;
    l1.insert("money men", 6.4);
	l1.insert("ooga boogaloo", 6.9);
	l1.insert("jumanji", 4.2);
    assertEquals(3, l1.size(), "test_insert 1");
    l1.insert("cloudy with a chance of meatballs", 7.5);
    assertEquals(4, l1.size(), "test_insert 2");
    l2.insert("cloudy with a chance of meatballs", 7.5);
    assertEquals(1, l2.size(), "test_insert 3");
}

void test_searchPrefix(){
    BST l1, l2;
    l1.insert("money men", 6.4);
	l1.insert("ooga boogaloo", 6.9);
	l1.insert("jumanji", 4.2);
    l1.insert("ooga hoobaloo", 3.3);
    Node* tmp = l1.searchPrefix("mon");
    assertEquals("money men", tmp->movie_name, "test_searchPrefix name 1");
    assertEquals(6.4, tmp->rating, "test_searchPrefix rating 1");
    assertEquals(0, tmp->depth, "test_searchPrefix depth 1");
  
    tmp = l1.searchPrefix("oog");
    assertEquals("ooga boogaloo", tmp->movie_name, "test_searchPrefix name 1");
    assertEquals(6.9, tmp->rating, "test_searchPrefix rating 1");
    assertEquals(1, tmp->depth, "test_searchPrefix depth 1");


}




