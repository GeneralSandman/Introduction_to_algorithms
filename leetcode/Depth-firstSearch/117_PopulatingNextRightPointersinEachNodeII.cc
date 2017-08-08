#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<queue>

using namespace std;
struct TreeLinkNode
{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
  public:
    void connect(TreeLinkNode *root)
    {
        if (!root)
            return;
        queue<TreeLinkNode *> res;
        queue<TreeLinkNode *> cur;

        res.push(root);

        while (!res.empty())
        {

            TreeLinkNode *node;
            int size = res.size();
            for (int i = 0; i < size; i++)
            {
                node = res.front();
                res.pop();

                if(node->left)
                    res.push(node->left);
                if(node->right)
                    res.push(node->right);
                
                cur.push(node);
            }

            make(cur);
            queue<TreeLinkNode *> tmp;
            cur.swap(tmp);
        }
    }

  private:
    void make(queue<TreeLinkNode *> &res)
    {
        if (res.empty())
            return;
        TreeLinkNode *node = res.front();
        res.pop();

        TreeLinkNode *next;
        while (!res.empty())
        {
            next = res.front();
            res.pop();

            node->next = next;
            node = node->next;
        }

        node->next=nullptr;
    }
};


int main(){
    Solution a;
    
    return 0;
}


