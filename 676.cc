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

class MagicDictionary
{
  public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        root = new Node;
        root->isWord = false;
        for (int i = 0; i < 26; i++)
            root->next[i] = nullptr;
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for (auto t : dict)
            insert(t);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        bool hasChanged = false;
        Node *tmp = root;

        


        return (hasChanged && tmp->isWord); 
    }

    ~MagicDictionary()
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

    void insert(string word)
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

    void deleteTree(Node *node)
    {
        if (node == nullptr)
            return;
        for (int i = 0; i < 26; i++)
        {
            deleteTree(node->next[i]);
            node->next[i] = nullptr;
        }

        // cout << "delete node:" << endl;
        delete node;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */

int main()
{

    MapSum a;
    a.insert("aa", 3);
    cout << a.sum("a") << endl;

    a.insert("aa", 2);
    cout << a.sum("a") << endl;
    cout << a.sum("aa") << endl;

    a.insert("aaa", 3);
    cout << a.sum("aaa") << endl;
    cout << a.sum("bbb") << endl;
    cout << a.sum("ccc") << endl;

    return 0;
}