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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 0;
        else if (!root->left || !root->right)
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        else
            return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main()
{
    Solution a;

    return 0;
}
