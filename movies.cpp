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

int BST::size() const{
  if(root){
    return size(root);
  }else{
    return 0;
  }
}

int BST::size(Node* n) const{
  if(!n){
    return 0;
  }
  return 1 + size(n->left) + size(n->right);
}


BST::Node* BST::getSuccessorNode(string value) const
{
	Node* tmp = getNodeFor(value, root);
    if (tmp) {
        if (tmp->right) {
            tmp = tmp->right;
            while (tmp->left) {
                tmp = tmp->left;
            }
            return tmp;
        }
        while (tmp->parent) {
            tmp = tmp->parent;
            if (value < tmp->movie_name) {
                return tmp;
            }
        }
    }
    return nullptr;
}

BST::Node* BST::getPredecessorNode(string value) const
{
	Node* tmp = getNodeFor(value, root);
  if (tmp) {
        if (tmp->left) {
            tmp = tmp->left;
            while (tmp->right) {
                tmp = tmp->right;
            }
            return tmp;
        }
        while (tmp->parent) {
            tmp = tmp->parent;
            if (value > tmp->movie_name) {
                return tmp;
            }
        }
    }
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

bool BST::comparePrefix(string prefix, string n){
  string compare = lower(n);
  string pre = lower(prefix);

  if(pre.compare(0,pre.size()-1,compare,0,pre.size()-1) == 0){
    return true;
  }
  else
  {
    return false;
  }
}

string BST::lower(string word) const{
    string tmp = "";
    for (unsigned i = 0; i < word.size(); i++) {
        tmp += tolower(word[i]);
    }
    return tmp;
}