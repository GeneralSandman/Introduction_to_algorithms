#ifndef TRIE_TREE_H
#define TRIE_TREE_H
#include<iostream>
#include<cstring>
#include<string>
namespace trie_tree{
    using namespace std;
    class TrieTreeNode{
        public:
            bool m_nTerm;
            int m_nChildNumber;
            TrieTreeNode * m_pChild[26];
        
        public:
            TrieTreeNode():m_nTerm(false),m_nChildNumber(0){
                memset(m_pChild,0,sizeof(m_pChild));
            }
    };


    class TrieTree{
        private:
            TrieTreeNode * m_pRoot;

            int m_fHashIndex(const char &key){return key%26;}

            bool m_fFindWord(const string &);
            void m_fInsertWord(const string &);
            bool m_fDeleteWord(const string &,TrieTreeNode*,bool &result);
            bool m_fClear(TrieTreeNode *);
            void m_fVisitAll(TrieTreeNode *);
        
        public:
            TrieTree();
            bool findWord(const string &);
            void insertWord(const string &);
            bool deleteWord(const string &);
            bool clearTree();
            void visitAll();
            ~TrieTree();
    };
}

#endif