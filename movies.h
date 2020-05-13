// movies.h
// Andy Wu, Chase Alcorn
#include <iostream>
#include <string>

#ifndef BST_H
#define BST_H

using namespace std;

class BST{
public:

    BST();
    ~BST();

    bool insert(string name, double rating);
    void printInOrder();
    bool remove(string name);

    



private:
    struct Node{
        string movie_name;
        double rating;
        int depth;

        Node *left, *right, *parent;

        Node(string v = "", double r = 0.0, int d = 0) : movie_name(v), rating(r), depth(d), left(0), right(0), parent(0) {}
    };

    Node* getNodeFor(string name);
    bool insert(string name, double rating, Node* n);
    void printInOrder(Node* n);
    
    Node* getSuccessorNode(string name);
    Node* getPredecessorNode(string name);




};


#endif