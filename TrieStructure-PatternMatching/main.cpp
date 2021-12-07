#include <iostream>
#include<fstream>
#include "Problem4.h"

using namespace std;

int main()
{
    Trie new_dict = generate_dictionary();

    new_dict.print();

//    Trie* myDict = new Trie();
//    string dic = "C:/Users/dvnny/OneDrive/Documents/4-Code/EC330/HW6_Trie_2/words.txt";
//    string line;
//    ifstream file(dic);

//    if (file.is_open()) {
//        while (getline(file, line)) {
//            myDict->insert(line);
//        }
//    }
//    myDict->print();

//    cout << "Search for 'parker' " << myDict->find("parker") << "\n";
//    cout << "Search for 'awesome' " << myDict->find("aw") << "\n";
//    cout << "Search for 'dun' " << myDict->find("dunn") << "\n";

    return 0;
}