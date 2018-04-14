#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stdio.h>
#include <cmath>
#include <stack>

using namespace std;

class WordDictionary
{
  public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Node;
        root->isWord = false;
        for (int i = 0; i < 26; i++)
            root->next[i] = nullptr;
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = tolower(word[i]);
        Node *tmp = root;

        for (auto t : word)
        {
            Node *&n = tmp->next[t - 'a'];
            if (n == nullptr)
            {
                n = new Node;
                n->isWord = false;
                for (int i = 0; i < 26; i++)
                    n->next[i] = nullptr;
            }
            tmp = n;
        }
        tmp->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = tolower(word[i]);
        return search(word, 0, root);
    }

    ~WordDictionary()
    {
        deleteTree(root);
    }

  private:
    typedef struct Node
    {
        bool isWord;
        Node *next[26];
    } Node;

    Node *root;

    bool search(string &word, int begin, Node *node)
    {
        Node *tmp = node;

        for (int i = begin; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (int j = 0; j < 26; j++)
                {
                    word[i] = char('a' + j);
                    if (tmp->next[j] != nullptr && search(word, i, tmp))
                        return true;
                }
            }
            else
            {
                if (tmp->next[word[i] - 'a'] == nullptr)
                    return false;
                tmp = tmp->next[word[i] - 'a'];
            }
        }
        if (tmp->isWord == true)
            return true;
        else
            return false;
    }

    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        for (int i = 0; i < 26; i++)
        {
            deleteTree(node->next[i]);
            node->next[i] = nullptr;
        }

        delete node;
    }
};

int main()
{

    WordDictionary *obj = new WordDictionary;

    vector<string> v = {"WordDictionary", "addWord", "addWord", "addWord", "addWord", "addWord", "addWord",
                        "addWord", "addWord", "search", "search", "search", "search", "search", "search", "search", "search", "search", "search"};

    // vector<string> v{"abab","asasas"};
    for (int i = 0; i < v.size(); i++)
    {
        obj->addWord(v[i]);
    }

    for (auto t : v)
    {
        if (obj->search(t))
        {
            cout << "success\n";
        }
    }

    string tmp;
    while (cin >> tmp)
    {
        if (obj->search(tmp))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    delete obj;

    return 0;
}