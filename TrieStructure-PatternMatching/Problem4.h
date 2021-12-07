//
//  Problem4.h
//  ec330_hw6
//

#ifndef Problem4_h
#define Problem4_h

#include<map>
#include<string>
#include<vector>

#define NUM_CHARS 52

using namespace std;


/// CURRENTLY CONFIGURED TO ONLY WORK WITH CHARACTERS BELOW
/// 'a' - 'z' and 'A' - 'Z'

class TrieNode {
private:
    char key;
    bool nodeIsEnd;
    int count;
//    int size;
public:
    ~TrieNode();
    TrieNode* children[NUM_CHARS];
    explicit TrieNode(char c);
    bool isEnd() const;
    void print(string);
    void rinsert(vector<char>::iterator, vector<char>*);
    int search(string::iterator, string*);
};

//  char getKey();
//  bool keyExists(char c);
//
//  std::map<char, TrieNode> children;
//  explicit TrieNode(char c);

//  void setAsEnd();

class Trie {
 private:
    TrieNode* root;
//  char key;
//  Trie* children[NUM_CHARS];
//  bool TrieIsEnd;
//  int size;
//  void print(string);

 public:
  Trie();
  ~Trie();
//  explicit Trie(char);
  void insert(vector<char>);
//  bool isEnd();
//  Trie* search_children(char);
  void print();
  int find(string);
};

Trie generate_dictionary();

/************************ GENERAL IMPROVEMENTS ************************
 *
 *  (1) Separate user from the TrieNode class by figuring out how to
 *      properly use inheritance
 *
 *
 *
 ********************************************************************/


#endif /* Problem4_h */