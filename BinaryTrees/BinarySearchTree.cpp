// Copyright 2022 pgdunn@bu.edu

// Created 26 Jan 2022
// Creator Parker Dunn

// Class definitions in BinarySearchTree.h

#include "BinarySearchTree.h"

/********** BTnode METHODS **********/

void BTnode::traverse() {
	if (leaf) {
		cout << " " << key << " ";
	} else {
		left->traverse();
		right->traverse();
	}
}

BTnode* BTnode::search(int find) {
	if (key == find) {
		return this;
	} else if (leaf) {
		return nullptr;
	} else {
		if (key > find) return left->search(find);  	// looking for a smaller key
		else return right->search(find);				// looking for a larger key
	}
}

BTnode* BTnode::insert(int find) {
	if (find == key) {
		return nullptr;
	} else if (leaf) {
		return this;
	} else {
		if (key > find) {
			if (left != nullptr) return left->insert(find);
			else return this;
		} else {
			if (right != nullptr) return right->insert(find);
			else return this;
		}
	}
}

/********** BST Methods **************/

BST::BST() {
	root = nullptr;
	count = 0;
	min = INT_MIN;
	max = INT_MAX;
}

void BST::insert(int new_key) {
	cout << "Inserting " << new_key << endl;
	if (root == nullptr) {
		root = new BTnode(new_key, true);
		min = new_key;
		max = new_key;
		count++;
	} else {
		BTnode* loc = root->insert(new_key);
		if (!loc) {
			cerr << "This key already exists in the data. You can only enter unique values." << endl;
		} else {

			// Maintaining the BST
			if (new_key < min) min = new_key;
			if (new_key > max) max = new_key;
			count++;

			// Insert Process
			// (1) Create the new node
			// (2) determine left or right insert
			// (3) insert new node
			// (4) change "root" to being not a leaf anymore
			
			// (1)
			BTnode* newNode = new BTnode(new_key, true);
			// (2) & (3)
			if (loc->getKey() > new_key) // new key is smaller
				loc->updateLeft(newNode);
			else
				loc->updateRight(newNode);
			// (4)
			loc->notLeaf();
		}
	}
}