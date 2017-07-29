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


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        fun(root,1,result);
        return result;
    }
private:
    void fun(TreeNode *root,int level,vector<int>&res){
        if(!root)
            return;
        if(level<res.size())
            res.push_back(root->val);
        
        fun(root->right,level+1,res);
        fun(root->left,level+1,res);
    }
};


int main()
{
    Solution a;

    return 0;
}
