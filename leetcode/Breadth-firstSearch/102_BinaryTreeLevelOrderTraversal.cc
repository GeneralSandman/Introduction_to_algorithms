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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        Order(result, root, 0);
        return result;
    }

    void Order(vector<vector<int>> &res, TreeNode *root, int level)
    {
        if (root == nullptr)
            return;
        if(res.size()==level)
        res.push_back(vector<int>());
        res[level].push_back(root->val);
        Order(res, root->left, level + 1);
        Order(res, root->right, level + 1);
    }
};

int main()
{
    Solution a;

    return 0;
}
