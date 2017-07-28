#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<set>
#include<unordered_set>

using namespace std;

class Node;

typedef vector<string> Ladder;
typedef unordered_set<string> StringSet;
typedef bool (*NodeCmper) (Node*, Node*);
typedef set<Node*, NodeCmper> NodeSet;

class Node
{
public:
    string word;
    vector<Node*> parents;

    Node(string w) : word(w) {}
    void addparent(Node* parent) { parents.push_back(parent); }

    // Yield all children of this node, and:
    //   1) If the child is found in $targetlayer, which means we found ladders that
    //      connect BEGIN-WORD and END-WORD, then we get all paths through this node
    //      to its ROOT node, and all paths through the target child node to its ROOT
    //      node, and combine the two group of paths to a group of ladders, and append
    //      these ladders to $ladders.
    //   2) Elif the $ladders is empty:
    //       2.1) If the child is found in $nextlayer, then get that child, and add
    //            this node to its parents.
    //       2.2) Else, add the child to nextlayer, and add this node to its parents.
    //   3) Else, do nothing.
    void yieldchildren(NodeSet& nextlayer, StringSet& wordlist, NodeSet& targetlayer,
                       vector<Ladder>& ladders, bool forward)
    {
        string nextword = word;
        for (int i = 0, n = nextword.length(); i < n; i++) {
            char oldchar = nextword[i];
            for (nextword[i] = 'a'; nextword[i] <= 'z'; nextword[i]++) {
                if (wordlist.count(nextword)) {
                    // now we found a valid child-word, let's yield a child.
                    Node* child = new Node(nextword);
                    yield1(child, nextlayer, targetlayer, ladders, forward);
                }
            }
            nextword[i] = oldchar;
        }
    }

    // yield one child, see comment of function `yieldchildren`
    void yield1(Node* child, NodeSet& nextlayer, NodeSet& targetlayer,
                vector<Ladder>& ladders, bool forward) {
        auto itr = targetlayer.find(child);
        if (itr != targetlayer.end()) {
            for (Ladder path1 : this->getpaths()) {
                for (Ladder path2 : (*itr)->getpaths()) {
                    if (forward) {
                        ladders.push_back(path1);
                        ladders.back().insert(ladders.back().end(), path2.rbegin(), path2.rend());
                    } else {
                        ladders.push_back(path2);
                        ladders.back().insert(ladders.back().end(), path1.rbegin(), path1.rend());
                    }
                }
            }
        } else if (ladders.empty()) {
            auto itr = nextlayer.find(child);
            if (itr != nextlayer.end()) {
                (*itr)->addparent(this);
            } else {
                child->addparent(this);
                nextlayer.insert(child);
            }
        }
    }

    vector<Ladder> getpaths()
    {
        vector<Ladder> ladders;
        if (parents.empty()) {
            ladders.push_back(Ladder(1, word));
        } else {
            for (Node* parent : parents) {
                for (Ladder ladder : parent->getpaths()) {
                    ladders.push_back(ladder);
                    ladders.back().push_back(word);
                }
            }
        }
        return ladders;
    }
};

bool nodecmp(Node* pa, Node* pb)
{
    return pa->word < pb->word;
}

class Solution {
public:
    vector<Ladder> findLadders(string begin, string end, StringSet& wordlist) {
        vector<Ladder> ladders;
        Node headroot(begin), tailroot(end);
        NodeSet frontlayer(nodecmp), backlayer(nodecmp);
        NodeSet *ptr_layerA = &frontlayer, *ptr_layerB = &backlayer;
        bool forward = true;

        if (begin == end) {
            ladders.push_back(Ladder(1, begin));
            return ladders;
        }

        frontlayer.insert(&headroot);
        backlayer.insert(&tailroot);
        wordlist.insert(end);
        while (!ptr_layerA->empty() && !ptr_layerB->empty() && ladders.empty()) {
            NodeSet nextlayer(nodecmp);
            if (ptr_layerA->size() > ptr_layerB->size()) {
                swap(ptr_layerA, ptr_layerB);
                forward = ! forward;
            }
            for (Node* node : *ptr_layerA) {
                wordlist.erase(node->word);
            }
            for (Node* node : *ptr_layerA) {
                node->yieldchildren(nextlayer, wordlist, *ptr_layerB, ladders, forward);
            }
            swap(*ptr_layerA, nextlayer);
        }

        return ladders;
    }
};

int main(){
    Solution a;
    
    return 0;
}


