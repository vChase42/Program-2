// movies.h
// Andy Wu, Chase Alcorn
#include <iostream>
#include <string>

#ifndef BST_H
#define BST_H

using std::string;

class BST{
    struct Node {
        string movie_name;
        double rating;
        int depth;

        Node* left, * right, * parent;

        //optional constructor: movie_name, rating, current depth, parent node.
        Node(string v = "", double r = 0.0, int d = 0, Node* p = nullptr) : movie_name(v), rating(r), depth(d), left(0), right(0), parent(p) {}
    };
public:

    BST();          //constructor
    ~BST();         //destructor

    bool insert(string name, double rating);     //inserts a node into tree with a movie name and rating
    void printInOrder() const;        //prints tree in alphabetical order
    void printByDepth() const;        //prints the tree from top to bottom (somehow?)
    bool remove(string name);           //removes a node and reorganizes tree
    
    Node* searchPrefix(string prefix) const;    //returns a movie with that prefix AND has the highest rating throughout the BST

private:
    

    Node* getNodeFor(string name, Node* n) const;           //returns node with given movie name (exact name required)
    bool insert(string name, double rating, Node* n, int depth);    //helper function for insert function.
    void printInOrder(Node* n) const;                   //helper function for printInOrder function
    void printByDeth(Node* n) const;                    //helper function for bringByDepth function
    void clear(Node* n);                //deletes all nodes in the tree
    
    Node* getSuccessorNode(string name) const;      //returns the node that comes alphabetically after the string (does not have to be exact)
    Node* getPredecessorNode(string name) const;    //returns the node that comes alphabetically before the string (does not have to be exact)

    Node* searchPrefix(string prefix, Node* n) const;       //helper function for searchPrefix function

    //variable
    Node* root;
};


#endif