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
private:
    int maxValue;
  public:
    int maxPathSum(TreeNode *root)
    {
    }
    private:
    int maxPathDown(TreeNode *node){
        if(node==nullptr)
            return 0;
        
        int left=max(maxPathDown(node->left),0);
        int right=max(maxPathDown(node->right),0);
        
        return max(left,right)+node->val;
    }
};

int main()
{
    Solution a;

    return 0;
}
