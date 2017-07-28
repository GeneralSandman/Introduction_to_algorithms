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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            vector<int> res(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();

                res[i] = tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }

            result.insert(result.begin(), res);
        }

        return result;
    }
};

int main()
{
    Solution a;

    return 0;
}
