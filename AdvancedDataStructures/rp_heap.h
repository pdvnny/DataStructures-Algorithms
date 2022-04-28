/****************************************************

	Parker Dunn

	Related to project for EC 504

	Goal: Implement a Rank-Pairing Heap

*****************************************************/

/*************************************************************************************

	METHODS TO INCLUDE
	(1) insert/push			 - O(1)			--> push(node)
	(2) DeleteMin/ExtractMin - O(log n)		--> top()
	(3) DecreaseKey			 - O(1)			--> decrease_key(key of node to change)
	(4) Merge				 - O(1)			--> merge()

	- Make heap -
	rp_heap()

	- Capacity -
	bool empty() const;
	int size() const;

	- find-min -
	Node_type top() const;

	- insert -
	push(Node_type)   <-- really don't understand how the reference set this one up

	- delete-min -
	void pop();
	void pop(Node_type)

	- delete-all -
	void clear();

	- decrease_key -
	void decrease_key(someway to reference the node that is supposed to change)

	REFERENCES:
	- https://github.com/shingyipcheung/rank-pairing-heaps
	- https://github.com/shingyipcheung/rank-pairing-heaps/blob/master/astarheap/rp_heap.h
	- https://github.com/shingyipcheung/rank-pairing-heaps/blob/master/astarheap/AstarNode.h


************************************************************************************/

#ifndef _RP_HEAP_H_
#define _RP_HEAP_H_

#include <map>
#include <iostream>

using std::map;
using std::cerr;
using std::cout;

typedef struct node {
	int key;
	int data;
	int rank;
	bool root;

	heap_node* left;
	heap_node* right;

	heap_node* parent; // will use this as a dual purpose LL pointer for roots

	heap_node(int nodeData, int nodeKey) {
		key = nodeKey;
		data = nodeData;
		root = true;
		
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}

} heap_node;

/********************* HELPER FUNCTION: max() *************************/

int max(int a, int b) {
	if (b > a) return b;
	else return a;
};


/******************** START OF rp_heap DEFINITION *********************/

//template <class data>
class rp_heap {
private:
	int heap_size;
	int maxRank;
	heap_node* min;
	heap_node* lowest_rank;

	map<int, heap_node*> contents; // will use this keep a pointer to each node

	void setRank(heap_node*); 													// done

	heap_node* join(heap_node*, heap_node*);									// done
	void merge();																// incomplete
	/// My idea: 
	///		"merge" is the recursive process that joins trees to make trees in the heap
	///		"join"  is just the function to put any two trees together and would be called from within merge

	void recalcMaxRank();														// done
	void insert2root(heap_node*);												// done
	/// insert2root -> Updates "lowest_rank", but does NOT update "min"

public:
	rp_heap();																	// incomplete -> feels like i'm still missing stuff...

	bool empty() const { return (heap_size <= 0); }								// done
	int size() const { return heap_size; };										// done

	// normally would return data or something
	int top() const { return min->data; }										// done

	// return top and remove the min node 
	//(plus all clean up after removing a root)
	int extract_min();															// incomplete

	void push(int, int); // would normally push whatever the data is      		// done

	void decreaseKey(int, int);													// done
	/// decreaseKey -> Updates "lowest_rank" (via insert2root) and "min"

};

/********************* CONSTRUCTOR ************************************/

rp_heap::rp_heap() {

	this->min = nullptr;
	this->lowest_rank = nullptr;

	this->maxRank = -1;
	this->heap_size = 0;

};

/**************** PUSH - add new element to heap; LAZY insert *************/

void rp_heap::push(int newData, int newKey) {

	/// increase the size of the heap
	this->heap_size++;

	/// create a new heap_node
	heap_node* newNode = new heap_node(newData, newKey);

	/// Lazy insert of the new node
	insert2root(newNode); // setRank(newNode); - taken care of by this function
	contents.emplace(newKey, newNode);

	/// Update min if necessary
	if (min->data > newNode->data) this->min = newNode;
};


/******************** RECALCULATE MAX RANK METHOD ********************/

void rp_heap::recalcMaxRank() {

	int maximum = this->lowest_rank->rank;
	int current_rank;

	heap_node* itr = this->lowest_rank->parent;
	while (itr != lowest_rank) {
		current_rank = itr->rank;

		if (current_rank > maximum) maxiumum = current_rank;

		itr = itr->parent;
	}

	this->maxRank = maximum;
};

/**************** INSERT 2 ROOT METHOD *******************************/
void rp_heap::insert2root(heap_node* n) {
	
	// preliminary steps to define the node as a root
	n->root = true;
	this->setRank(n);


	// (1) finding the right position
	heap_node* itr = this->lowest_rank->parent;
	while (n->rank > itr->parent->rank and itr != lowest_rank) {
		itr = itr->parent;
	}

	// (2) saving pointers to keep track of before/after
	heap_node* prev = itr;
	heap_node* next = itr->parent;

	// (3) insert new tree in circularly linked list
	n->parent = next;
	prev->parent = n;

	// (4) Update lowest_rank
	if (this->lowest_rank->rank > n->rank) this->lowest_rank = n;
}


/******************** DECREASE KEY METHOD ****************************/  // NEED REVIEWING BY COMPARING TO THE RANK-PAIRING HEAP PAPER
void rp_heap::decreaseKey(int x, int newVal) {

	/// Retrieve pointer to node associated with the key
	heap_node* node = contents.at(x);
	// NOTE: the line above will throw an error if the key is not found

	/// Don't try to change the value if the new value is greater than the current one
	if (newVal > node->data) cerr << "\n\nINVALID: Tried to increase the value/data of a node with key " << node->key << "\n\n";

	/// Decrease the value/data
	node->data = newVal;

	heap_node* p = node->parent;
	heap_node* r = node->right;

	if (!node->root) {  /// updated node is not already a root

		/// Cut node and left branch
		node->parent = nullptr;
		node->right = nullptr;

		/// Re-link right tree to parent  **** I THINK I NEED A SPECIAL EXCEPTION FOR IF THE PARENT IS A ROOT NODE *****
		p->right = r;
		r->parent = p;

		/// Incorporate node into circularly linked list of trees
		this->insert2root(node);

		/// Re-calculate rank of parent and that lost right child
		this->setRank(p);
		//this->setRank(node);   - taken care of by "insert2root"

		/// Final Checks
		this->recalcMaxRank();

	}

	/// Check if new root is the new minimum
	if (min->data > node->data) min = node;
};

/*************** JOIN -> makes all changes to facilitate merging of two trees **/

// **NOTE**: This function will not interact with the LL of root trees!!!
// 			 The circularly linked list will have to be managed separately.

heap_node* rp_heap::join(heap_node* nodeA, heap_node* nodeB) {

	/// Quick Error Check
	if (nodaA->rank != nodeB->rank) cerr << "\n\nWARNING: Trying to join two half-trees with different ranks!\n\n";

	int max_data = max(nodeA->data, nodeB->data);

	if (max_data != nodeA->data) { // Condition: nodeA->data is smaller and should be root

		nodeB->root = false;
		nodeB->parent = nodeA;
		nodeB->right = nodeA->left;

		nodeA->left = nodeB;

		this->setRank(nodeB); // should recurse to nodeA and update that too

		return nodeA;

	} else { // Condition: nodeB->data is smaller or there was a tie and nodeB should be root.

		nodeA->root = false;
		nodeA->parent = nodeB;
		nodeA->right = nodeB->left;

		nodeB->left = nodeA;

		this->setRank(nodeA); // should recurse to nodeB and update that too

		return nodeB;
	}

};


/*************** MERGE -> repeated merging of same rank trees ****************/

void rp_heap::merge() {

	int sz = this->maxRank * 10;

	heap_node* rootTrees[sz];  // making array double in size to be safe
	bool modified[sz];
	for (int i = 0; i < sz; i++) {
		rootTrees[i] = nullptr;
		modified[i] = 0;
	}

	heap_node* roots_itr = this->lowest_rank;
	heap_node* prev;

	/// add first tree to array
	rootTrees[roots_itr->rank] = roots_itr;
	prev = roots_itr;
	roots_itr = roots_itr->parent;


	/// BELOW DOES NOT WORK!!
	/// CHANGES:
	/// (1) need a more structured way to move through the circular LL
	/// (2) "blow up" the circular LL and must find a relaiable way to track each root

	

	/// do-while loop goes through the entire circularly linked list of roots each time
	do {

		/// intention is for this to go through all root nodes once
		for (int n = 0; n < sz; n++) {
			//while (roots_itr != lowest_rank) {

			int cRank = roots_itr->rank;

			if (rootTrees[cRank]) { // TRUE if the position where the current root would go is not empty

				/// join two trees
				roots_itr = this->join(roots_itr, rootTrees[cRank]);

				/// cleanup
				rootTrees[cRank] = nullptr;
				rootTrees[roots->itr]

				modified = true; /// ** this forces do-while to run again

			} else {

				/// add current root to the array and keep going

			}

			/// move iterators
			prev = roots_itr;
			roots_itr = roots_itr->parent;

		}

		int sum = 0;
		for (int j = 0; j < sz; j++) {
			sum = sum + modified[j];
			modified[j] = 0;
		}

	} while (sum > 0);

	/// From the array of root trees, REFORM the circular LL of roots



	/// Re-examine key features of the heap - min, max_rank, lowest_rank
	this->recalcMaxRank();

};


/******************** SET RANK METHOD (RECURSIVE) ********************/
void rp_heap::setRank(heap_node* aNode) {

	/// special procedure if current node is a root
	if (aNode->root) {
		
		aNode->rank = aNode->left->rank + 1;

		return;
	}

	/// setup
	heap_node* L = aNode->left;
	heap_node* R = aNode->right;
	//int rankR, rankL;
	int rankDiff;
	int prevRank = aNode->rank;

	// node with no children
	if (!L and !R) {

		aNode->rank = 0; // because it is a leaf; doesn't matter if it is root or not

	} else if (!L) { // node with no left child

		rankL = -1;
		rankR = R->rank;

	} else if (!R) { // node with no right child

		rankR = -1;
		rankL = L->rank;

	} else {

		rankR = R->rank;
		rankL = L->rank;

	}

	if (!L and !R) {
		/// need to bypass adjusting aNode->rank again
		if (prevRank != 0)
			setRank(aNode->parent);
		else
			return;

	} else {

		rankDiff = rankL - rankR;

		if (rankDiff > 1 or rankDiff < -1) {
			aNode->rank = max(rankR, rankL);
		} else {
			aNode->rank = max(rankR, rankL) + 1;
		}

		if (prevRank != aNode->rank) setRank(aNode->parent);
		else return;

	}

};


#endif /* _RP_HEAP_H_ */

