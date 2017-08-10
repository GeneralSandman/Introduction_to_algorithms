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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() != inorder.size() ||
            preorder.size() == inorder.size() == 0)
            return nullptr;
        TreeNode *root = createTree(preorder, 0, preorder.size(),
                                    inorder, 0, inorder.size());

        return root;
    }

  private:
    TreeNode *createTree(vector<int> &preorder, int b1, int e1,
                         vector<int> &inorder, int b2, int e2)
    {
        if (b1 == e1)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[b1]);

        int i = b2;
        for (; i < e2; i++)
        {
            if (inorder[i] == preorder[b1])
                break;
        }
        int left_length = i - b2;
        int right_length = e2 - i;
        node->left = createTree(preorder, b1 + 1, b1 + 1 + left_length,
                                inorder, b2, i);
        node->right = createTree(preorder, b1 + 1 + left_length, e1,
                                 inorder, i + 1, e2);

        return node;
    }
};

int main()
{
    Solution a;
    vector<int> pre = {1, 2, 4, 8, 5, 3, 6, 7};
    vector<int> in = {4, 8, 2, 5, 1, 6, 3, 7};
    // TreeNode *root = a.buildTree(pre, in);

    return 0;
}
