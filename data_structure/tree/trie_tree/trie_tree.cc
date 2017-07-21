#include"trie_tree.h"

namespace trie_tree{


    bool TrieTree::m_fFindWord(const string & word){
        TrieTreeNode * cur=m_pRoot;

        for(auto t:word){
            if(cur->m_pChild[m_fHashIndex(t)]==nullptr)
                return false;
            else 
                cur=cur->m_pChild[m_fHashIndex(t)];
        }

        return cur->m_nTerm;
    }

    void TrieTree::m_fInsertWord(const string & word){
        TrieTreeNode * cur=m_pRoot;
        for(auto t:word){
            if(cur->m_pChild[m_fHashIndex(t)]==nullptr){
                cur->m_pChild[m_fHashIndex(t)]=new TrieTreeNode();
                cur->m_nChildNumber++;
            }

            cur=cur->m_pChild[m_fHashIndex(t)];
        }

        cur->m_nTerm=true;
    }

    bool TrieTree::m_fDeleteWord(const string &word,TrieTreeNode *cur,bool &result){
        
    }

    bool TrieTree::m_fClear(TrieTreeNode *cur){
        for(int i=0;i<26;i++){
            if(cur->m_pChild[i]==nullptr){
                continue;
            }
            else{
                m_fClear(cur->m_pChild[i]);
                delete cur->m_pChild[i];
                cur->m_pChild[i]=nullptr;
                if(--cur->m_nChildNumber==0)
                    break;
            }
        }
    }

    void TrieTree::m_fVisitAll(TrieTreeNode *cur){
        if(cur->m_nTerm){
            cout<<"display a word"<<endl;
        }

        for(int i=0;i<26;i++){
            if(cur->m_pChild[i]==nullptr)
                continue;
            else{
                m_fVisitAll(cur->m_pChild[i]);
            }
        }

    }

    TrieTree::TrieTree(){
        m_pRoot=nullptr;
    }

    bool TrieTree::findWord(const string & word){
        return m_fFindWord(word);
    }

    void TrieTree::insertWord(const string & word){
        m_fInsertWord(word);
    }

    bool TrieTree::deleteWord(const string & word){
        bool result;
        m_fDeleteWord(word,m_pRoot,result);
        return result;
    }

    bool TrieTree::clearTree(){
        m_fClear(m_pRoot);
        for(int i=0;i<26;i++){
            if(m_pRoot->m_pChild[i])
                cout<<"clear all failed\n";
        }
    }

    void TrieTree::visitAll(){
        m_fVisitAll(m_pRoot);
    }

    TrieTree::~TrieTree(){
        clearTree();
    }

    
}