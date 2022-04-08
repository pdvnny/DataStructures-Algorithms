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

typedef struct node {
	int key;
	int data;
	int rank;
	bool root;

	heap_node* left;
	heap_node* right;

	heap_node* parent;

	heap_node(int nodeKey, int nodeData, bool isRoot) {
		key = nodeKey;
		data = nodeData;
		root = isRoot
	}

} heap_node;


//template <class data>
class rp_heap {
private:
	int heap_size;
	heap_node* min;

	map<int, heap_node*> contents; // will use this keep a pointer to each node

public:
	rp_heap();

	bool empty() const { return (heap_size <= 0); }
	int size() const { return heap_size; }

	// normally would return data or something
	int top() const { return min->data; }
	int extract_min(); // return top and remove the min node (plus all clean up after removing a root)

	heap_node* push(int); // would normally push whatever the data is

};




#endif /* _RP_HEAP_H_ */
