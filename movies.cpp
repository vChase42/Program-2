// movies.cpp
// Andy Wu, Chase Alcorn
#include "movies.h"
#include <iostream>

using std::cout;
using std::endl;

BST::BST() : root(nullptr) {}

BST::~BST()
{
	clear(root);
}

void BST::clear(Node* n) {
	if (n) {
		clear(n->left);
		clear(n->right);
		delete n;
	}
}

bool BST::insert(string name, double rating)
{
	if (!root) {
		root = new Node(name, rating);
		return true;
	}
	return insert(name, rating, root, 0);
}

bool BST::insert(string name, double rating, BST::Node* n, int depth)
{
	if (name == n->movie_name) {
		return false;
	}
	if (n->movie_name > name) {
		if (n->left) {
			return insert(name, rating, n->left, depth + 1);
		}
		else {
			n->left = new Node(name, rating, depth, n);
			return true;
		}
	}
	else {
		if (n->right) {
			return insert(name, rating, n->right, depth + 1);
		}
		else {
			n->right = new Node(name, rating, depth, n);
			return true;
		}
	}
}

BST::Node* BST::getNodeFor(string name, Node* n) const
{
	if (!n) {
		return nullptr;
	}
	else if(n->movie_name > name) {
		return getNodeFor(name, n->left);
	}
	else if (n->movie_name < name) {
		return getNodeFor(name, n->right);
	}
	else {
		return n;
	}
}

void BST::printInOrder() const
{
	if (root) {
		printInOrder(root);
	}
}

void BST::printInOrder(Node* n) const
{
	if (!n) {
		return;
	}
	printInOrder(n->left);
	cout << n->movie_name << ", " << n->rating << endl;
	printInOrder(n->right);
}

//all below functions are unimplemented

void BST::printByDepth() const
{
}

void BST::printByDeth(Node* n) const
{
}

BST::Node* BST::getSuccessorNode(string name) const
{
	return nullptr;
}

BST::Node* BST::getPredecessorNode(string name) const
{
	return nullptr;
}

BST::Node* BST::searchPrefix(string prefix) const
{
	return nullptr;
}

BST::Node* BST::searchPrefix(string prefix, Node* n) const
{
	return nullptr;
}


bool BST::remove(string name)
{
	return false;
}