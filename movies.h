// movies.h
// Andy Wu, Chase Alcorn
#include <iostream>
#include <string>

#ifndef BST_H
#define BST_H

using std::string;

struct Node {
    string movie_name;
    double rating;
    int depth;
    Node* left, * right, * parent;

    //optional constructor: movie_name, rating, current depth, parent node.
    Node(string v = "", double r = 0.0, int d = 0, Node* p = nullptr) : movie_name(v), rating(r), depth(d), left(0), right(0), parent(p) {}
};

class BST{
public:
    BST();          //constructor
    ~BST();         //destructor

    bool insert(string name, double rating);     //inserts a node into tree with a movie name and rating
    void printInOrder() const;        //prints tree in alphabetical order
    void printPreOrder() const;        //prints the tree from top to bottom (somehow?)
    int size() const;                 //returns the number of nodes in the BST;
    
    Node* getNodeFor(string) const; //returns node that contains that string, otherwise returns null
    Node* searchPrefix(string prefix) const;    //returns a movie with that prefix AND has the highest rating throughout the BST

private:
    //mutators
    void clear(Node* n);                //deletes all nodes in the tree
    bool insert(string name, double rating, Node* n, int depth);    //helper function for insert function.

    //accessors
    void printInOrder(Node* n) const;                   //helper function for printInOrder function
    void printPreOrder(Node* n) const;                    //helper function for bringByDepth function
    int size(Node* n) const;            //helper function for size function

    Node* getNodeFor(string, Node*) const;     //helper function for getNodeFor

    bool comparePrefix(string prefix, string n) const; //if prefix matches first letters of n->movie_name - return true
    Node* searchPrefix(string prefix, Node* n) const;       //helper function for searchPrefix function
    string lower(string) const;

    //variable
    Node* root;
};


#endif