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
    bool isValidBST(TreeNode *root)
    {
        if(!root)
            return true;
        vector<int> res;
        inoreder(res,root);
        
        for(int i=0;i<res.size()-1;i++){
            if(res[i+1]<res[i])
                return false;
        }

        return true;
        
    }
    private:
        void inoreder(vector<int> &res,TreeNode *root){
            if(!root)
                return ;
            inoreder(res,root->left);
            res.push_back(root->val);
            inoreder(res,root->right);
        }
};

int main()
{
    Solution a;

    return 0;
}
