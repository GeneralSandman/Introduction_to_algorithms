#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;

        if (!root)
            return result;
        push(root, result, 1);

        return result;
    }

  private:
    void push(TreeNode *node, vector<int> &res, int level)
    {
        if (level > res.size())
            res.push_back(node->val);
        else 
            res[level - 1] = max(node->val,res[level-1]);
        if (node->right)
            push(node->right, res, level + 1);
        if (node->left)
            push(node->left, res, level + 1);
    }
};

int main()
{
    Solution a;

    return 0;
}
