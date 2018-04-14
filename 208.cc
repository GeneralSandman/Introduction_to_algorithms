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

class Trie
{
  public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node;
        root->isWord = false;
        for (int i = 0; i < 26; i++)
            root->next[i] = nullptr;
    }

    /** Inserts a word into the trie. */
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

    string replace(string word)
    {
        for (int i = 0; i < word.size(); i++)
            word[i] = tolower(word[i]);

        string res;
        Node *tmp = root;
        for (int i = 0; i < word.size(); i++)
        {

            if (tmp->next[word[i] - 'a'] == nullptr || tmp->isWord)
                break;

            if (tmp->next[word[i] - 'a'] != nullptr)
                res += word[i];
            tmp = tmp->next[word[i] - 'a'];
        }

        if (tmp->isWord)
            return res;
        return word;
    }

    ~Trie()
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

class Solution
{
  public:
    string replaceWords(vector<string> &dict, string sentence)
    {
        Trie *obj = new Trie;
        for (int i = 0; i < dict.size(); i++)
            obj->insert(dict[i]);

        vector<string> v;
        string s;
        for (auto t : sentence)
        {
            if (t != ' ')
                s += t;
            else if (!s.empty())
            {
                v.push_back(s);
                s = "";
            }
        }
        if (!s.empty())
            v.push_back(s);

        string res;
        for (int i = 0; i < v.size(); i++)
        {
            if (i != 0)
                res += ' ';
            res += obj->replace(v[i]);
        }

        delete obj;
        obj = nullptr;

        return res;
    }
};

int main()
{

    Solution a;
    vector<string> dict = {"a", "aa", "aaa", "aaaa"};
    string src = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    cout << a.replaceWords(dict, src) << endl;

    return 0;
}