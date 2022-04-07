/***********************************************

	Parker Dunn
	Related to EC 504 - SW HW 4

	Created April 6th, 2022

***********************************************/

// How to use typedef struct --> https://www.educative.io/edpresso/how-to-use-the-typedef-struct-in-c

template <class Data>
class Node {
public:
	// int key; // could be current position of the node in the LL (probably inefficient to deal with)
	Node* next;
	Node* prev;
	Data* data_structure;
};

template <class Data>
class myQueue {
private:
	Node<Data>* head;
	Node<Data>* tail;
	int size;
public:

	Data* front() { return head->data_structure; };
	int getSize() { return size; };
	bool empty() { return (size < 1); };
	
	myQueue() {
		this->size = 0;
		this->head = nullptr;
		this->tail = nullptr;
	};


	~myQueue() {
		/// Delete any remaining elements in the queue if it is not empty
		if (size > 0) {
			while (this->head) {
				Node<Data>* toDel = this->head;
				this->head = this->head->next;
				delete toDel;
			}
		}
	};

	void push(Data* newData) {
		/// Create new node
		Node<Data>* newNode = new Node<Data>;
		newNode->next = nullptr;
		newNode->prev = nullptr;
		newNode->data_structure = newData;

		if (this->size <= 0) { /// need to do some initial stuff on first push
			
			this->head = newNode;
			this->tail = newNode;

		} else { // not empty queue ... do normal push

			// add to end and update size and tail of class
			this->tail->next = newNode;
			newNode->prev = this->tail;
			this->tail = newNode;

		}

		this->size++;
	};
	
	void pop() {
		Node<Data>* toDel = this->head;
		
		/// update head
		this->head = this->head->next;
		this->size--;

		if (this->head) 
			this->head->prev = nullptr; // updating new head's "prev" pointer to point to null

		/// don't think I need any special considerations for deleting last node

		/// delete the removed node
		delete toDel;
	}

	/**** OTHER OPTIONS ****
	void pop_back();
	Node* find(int key - would have to be in the data object);
	************************/
};
