// A BTree node
class BTreeNode
{
    int *keys;  // An array of keys
    int t;      // Minimum degree (defines the range for number of keys)
    BTreeNode* *C; // An array of child pointers
    int n;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
public:
    BTreeNode(int _t, bool _leaf);   // Constructor

    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be a non-full when
    // this function is called.
    void insertNonFull(int k);

    // A utility function to split the child y of this node. i is index of
    // y in the child array C[]. The child y must be full when this function
    // is called.
    void splitChild(int i, BTreeNode* y);
 
    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();
 
    // A function to search a key in the subtree rooted with this node.   
    BTreeNode *search(int k);   // returns NULL if k is not present.

// Make the BTree friend of this so that we can access private members of this
// class in BTree functions
friend class BTree;
};

// A BTree
class BTree
{
    BTreeNode *root; // Pointer to root node
    int t;  // Minimum degree
public:
    // Constructor (Initializes tree as empty)
    BTree(int _t)
    {  root = nullptr;  t = _t; }
 
    // function to traverse the tree
    void traverse()
    {  if (root != nullptr) root->traverse(); }
 
    // function to search a key in this tree
    BTreeNode* search(int k)
    {  return (root == nullptr)? nullptr : root->search(k); }

    void insert(int k);
};