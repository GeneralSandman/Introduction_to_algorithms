#include"trie_tree.h"
#include<iostream>
using namespace std;
using namespace trie_tree;

int main(){
    TrieTree t;
    t.insertWord("tree");  
    t.insertWord("tea");  
    t.insertWord("A");  
    t.insertWord("ABC");  

    return 0;
}