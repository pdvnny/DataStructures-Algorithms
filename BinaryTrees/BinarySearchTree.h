// Copyright 2022 pgdunn@bu.edu

// Created 26 Jan 2022
// Creator Parker Dunn


// Trying to create a basic & reliable BinarySearchTree class

// Functionality:
// -- Create a basic BST that holds integers

// Pending features:
// (1) allow the BTnodes to hold another datatype - via (1) template of type or (2) adding another attribute to class
// (2) "Re-make method"/"Balancing" -- a way to empty a BST into an an array then make a new and better structured BST


#include<iostream>
#include<climits>

using std::cout;
using std::cerr;
using std::endl;


// template <typename T>
class BTnode {
public:
	BTnode(int _key, bool _leaf) {
      key = _key;
      leaf = _leaf;
      left = nullptr;
      right = nullptr;
    }
	// BTnode(int _key, bool _leaf, T _data) {key = _key; leaf = _leaf; data = _data; }

	bool isLeaf() { return this->leaf; }
	void notLeaf() { leaf = false; }
	// T getData() { return this->data; }
	int getKey() { return this->key; }
	void updateLeft(BTnode* n) { left = n; }
	void updateRight(BTnode* n) {right = n; }

	void traverse();
	BTnode* insert(int find);
	BTnode* search(int find);

private:
	int key;
	// T data;
	bool leaf;
	BTnode* left;
	BTnode* right;
};


class BST {
public:

	BST();
	void insert(int new_key);
	void traverse() { root->traverse(); }

private:
	BTnode* root;
	int max;
	int min;
	int count;
};

