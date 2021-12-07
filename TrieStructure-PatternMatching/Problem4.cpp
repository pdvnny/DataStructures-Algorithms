//
// Created by dvnny on 11/16/2021.
//

/// THIS SCRIPT WAS DEVELOPED BASED ON AN ASSIGNMENT
/// THERE ARE SOME REMAINING VARIABLES AND SECTION THAT ARE
/// NOT RELEVANT TO BUILDING THE TRIE DATA STRUCTURE


/************************************************
// Created by dvnny on 11/14/2021.

 Parker Dunn
 BU ID: U67368938
 DUE DATE: 16 Nov 2021

 EC 330 - HW6

 THIS SUBMISSION WAS NOT FOR MY HW
 I WANTED TO FOLLOW UP ON AN ASSIGNMENT BY LEARNING
 ABOUT THE TRIE STRUCTURE FOR STRING MATCHING

**************************************************/

#include<algorithm>
#include<iostream>
#include<fstream>
#include<unordered_map>

#include "Problem4.h"

using namespace std;

/// HOME COMPUTER FILENAMES
//string filename = "C:/Users/dvnny/OneDrive/Documents/4-Code/EC330/HW6/TinyData.txt";
//string filename = "C:/Users/dvnny/OneDrive/Documents/4-Code/EC330/HW6_Trie_2/BigData.txt";
//string dictionary = "C:/Users/dvnny/OneDrive/Documents/4-Code/EC330/HW6/dictionary.txt";

/// LAPTOP FILENAMES
//string filename = "C:/Users/parke/OneDrive/Documents/4-Code/EC330/HW6/TinyData.txt";
//string dictionary = "C:/Users/parke/OneDrive/Documents/4-Code/EC330/HW6/dictionary.txt";

/// WORKING DIRECTORY FILE NAMES
//string filename = "./TinyData.txt";
string dictionary_text = "dictionary.txt";
//string filename = "/BigData.txt";

/********************* SUPPORTING FUNCTIONS **********************************/

Trie generate_dictionary() {
    ifstream file(dictionary_text);
    Trie dict;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            vector<char> word;
            for (char & chr : line) {
                word.push_back(chr);
            }
            dict.insert(word);
        }
    } else {
        cerr << "\nFile was not opened.\n";
    }
    file.close();
    return dict;
}

/*********************** PROBLEM 4 FUNCTIONS *********************************/

//int count_elems(Trie* dict) {
//
//
//    int found = 0;
//
//}

/// TRIENODE IMPLEMENTATION ///
TrieNode::TrieNode(char c) {
    this->key = c;
    this->nodeIsEnd = false;
    this->count = 0;
//    this->size = 0;
    // initialize array to null
    for (auto& child : this->children) child = nullptr;
}

TrieNode::~TrieNode() {
    for (auto & child : this->children) {
//        cout << "Deleted\n";
        delete child;
    }
    /// I think delete will call the constructor of each child which should work
    /// recursively
}

bool TrieNode::isEnd() const {
    return this->nodeIsEnd;
}

void TrieNode::print(string str) {
    if (this->isEnd()) {
        cout << (str + this->key) << "\n";
    }
    str = str + this->key;
    for (auto & child: this->children)
        if (child != nullptr) child->print(str);
}

void TrieNode::rinsert(vector<char>::iterator vec_itr, vector<char>* str) {
//    TrieNode* child;
    int loc;
//    unsigned char c;
    if (*vec_itr > 96 and *vec_itr < 123) {
        loc = *vec_itr - 'a';
//        c = *vec_itr - 'a';
//        loc = c;
    } else {
        loc = (*vec_itr - 'A') + 26;
//        c = *str_itr - 'A';
//        loc = c + 26;
    }
    if (vec_itr == str->end()) {                              /// ON THE LAST CHARACTER
        this->nodeIsEnd = true;
        this->count++;
//        if (this->children[loc] == nullptr) {
//            /// need to create a new TrieNode in children array
//            this->children[loc] = new TrieNode(*str_itr);
//            this->size++;               /// REMOVE LINE
//            this->nodeIsEnd = true;
//
//        } else {
//            /// Trie for the character already exists
//            this->nodeIsEnd = true;
//        }
    } else {                                                /// NOT ON THE LAST CHARACTER
        if (this->children[loc] == nullptr) {
            /// need to create a new Trie in children array
            this->children[loc] = new TrieNode(*vec_itr);
//            this->size++;
            this->children[loc]->rinsert(++vec_itr, str);
        } else {
            this->children[loc]->rinsert(++vec_itr, str);
        }
    }
}

int TrieNode::search(string::iterator sitr, string* strptr) {
    int loc;
//    unsigned char c;
    if (sitr == strptr->end()) {
        return this->count;
    } else {
        if (*sitr > 96 and *sitr < 123) {
            loc = *sitr - 'a';
            //        loc = c;
        } else if (*sitr > 64 and *sitr < 91) {
            loc = (*sitr - 'A') + 26;
            //        loc = c + 26;
        } else {
            cerr << "Invalid character\n";
            return 0;
        }
        if (this->children[loc] == nullptr)
            return 0;
        else
            return this->children[loc]->search(++sitr, strptr);
    }
}

/// TRIE IMPLEMENTATION ///
Trie::Trie() {
    this->root = new TrieNode('*');
}

Trie::~Trie() {
    delete this->root;
}

void Trie::insert(vector<char> vec) { /// initialize the TrieNode rinsert calls
    int loc;
//    unsigned char c;
    auto vec_itr = vec.begin();
    if (*vec_itr > 96 and *vec_itr < 123) {
        loc = *vec_itr - 'a';
//        c = *str_itr - 'a';
//        loc = c;
    } else {
        loc = (*vec_itr - 'A') + 26;
//        c = *str_itr - 'A';
//        loc = c + 26;
    }
    if (this->root->children[loc] == nullptr)
        this->root->children[loc] = new TrieNode(vec.at(0));

    this->root->children[loc]->rinsert(++vec_itr, &vec);
}

void Trie::print() {
    string printable;
    for (auto & child : this->root->children)
        if (child != nullptr) child->print(printable);
}

int Trie::find(string str) {
    string::iterator sitr = str.begin();
    return this->root->search(sitr, &str);
}

//Trie* Trie::search_children(char c) {
//    for (int i = 0; i <= this->size; i++) {
//        if (this->children[i] != nullptr) {
//            if (this->children[i]->key == c) return this->children[i];
//        }
//    }
//    return nullptr;
//}

//void Trie::print() {
//    string printable;
//    for (int i = 0; i <= this->size; i++)
//        this->children[i]->print(printable);
//}
//
//void Trie::insert(string str) {
//    Trie* child;
//    string::iterator itr = str.begin();
//
//    /// either insert node or find node in children array
//    if (this->search_children(*itr) == nullptr) {
//
//        this->children[this->size] = new Trie(str.at(0));
//        if (this->children[this->size]->recursive_insert(++itr, &str)) {
//            cout << "Insertion successful.\n";
//            this->size++;
//        } else {
//            cerr << "Insertion failed.\n";
//        }
//
//    } else {
//
//        child = this->search_children(*itr);
//        /// NOW, child points to trie holding str.at(0)
//        if (child->recursive_insert(++itr, &str)) cout << "Insertion successful.\n";
//        else cerr << "Insertion failed.\n";
//
//    }
//}


