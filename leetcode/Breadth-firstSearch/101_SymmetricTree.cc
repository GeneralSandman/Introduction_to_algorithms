#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
  public:
    bool isSymmetric(TreeNode *root)
    {
        bool result;
        if (root == nullptr)
            return true;
        return isSameTree(root->right, root->left);
    }

  private:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr && q != nullptr)
            return false;
        else if (p != nullptr && q == nullptr)
            return false;
        else
        {
            if (p->val == q->val)
            {
                bool result = (isSameTree(p->left, q->right) && isSameTree(p->right, q->left));
                return result;
            }

            else
                return false;
        }
        return false;
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;

        TreeNode *left=root->left,*right=root->right;
        queue<TreeNode *> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){

            left=q1.front();
            right=q2.front();
            q1.pop();
            q2.pop();

            if(left==nullptr && right==nullptr)
                continue;
            else if(left==nullptr || right==nullptr)
                return false;
            else if(left->val==right->val){
                q1.push(left->left);
                q1.push(left->right);

                q2.push(right->right);
                q2.push(right->left);
            }
            else
                return false;
        }

        return true;

    }
};

int main()
{
    Solution a;

    return 0;
}
