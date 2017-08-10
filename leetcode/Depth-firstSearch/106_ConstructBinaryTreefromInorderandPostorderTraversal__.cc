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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() != postorder.size() ||
            inorder.size() == postorder.size() == 0)
            return nullptr;
        TreeNode *root = createTree(inorder, 0, inorder.size(),
                                    postorder, 0, postorder.size());

        return root;
    }

  private:
    TreeNode *createTree(vector<int> &inorder, int b1, int e1,
                         vector<int> &postorder, int b2, int e2)
    {
        if (b1 == e1)
            return nullptr;
        TreeNode *node = new TreeNode(postorder[e2]);

        int i = b1;
        for (; i < e1; i++)
        {
            if (inorder[i] == postorder[e2])
                break;
        }
        int left_length = i - b1;
        int right_length = e1 - i;

        node->left = createTree(inorder, b1, i,
                                postorder, b2, b2 + left_length);
        node->right = createTree(inorder, i + 1, e1,
                                 postorder, b2 + left_length, e2-1);

        return node;
    }
};

int main()
{
    Solution a;

    return 0;
}
