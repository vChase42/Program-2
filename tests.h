// tests.h
// Andy Wu, Chase Alcorn
#ifndef tests_H
#define tests_H

#include <iostream>
using namespace std;

//declarations for test functions

void test_size();
void test_insert();
void test_clear();
void test_getNodeFor();
void test_tolower();

//assertEquals functions for comparing different object types

void assertEquals(int expected, int actual, string desc){
  if(expected == actual){
    cout<<"PASSED"<<endl;
  }else{
    cout<<"  FAILED: "<<desc<<endl
        <<"  expected: "<<expected<<endl
        <<"  actual: "<<actual<<endl;
  }
}

void assertEquals(double expected, double actual, string desc){
  if(expected == actual){
    cout<<"PASSED"<<endl;
  }else{
    cout<<"  FAILED: "<<desc<<endl
        <<"  expected: "<<expected<<endl
        <<"  actual: "<<actual<<endl;
  }
}

void assertEquals(string expected, string actual, string desc){
  if(expected == actual){
    cout<<"PASSED"<<endl;
  }else{
    cout<<"  FAILED: "<<desc<<endl
        <<"  expected: "<<expected<<endl
        <<"  actual: "<<actual<<endl;
  }
}

#endif