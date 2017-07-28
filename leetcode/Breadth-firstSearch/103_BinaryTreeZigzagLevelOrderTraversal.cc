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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if(root==nullptr)
            return result;
        
        queue<TreeNode *> q;
        q.push(root);

        bool left2right=true;
        while(!q.empty()){
            int size=q.size();
            vector<int> res(size);
            for(int i=0;i<size;i++){
                TreeNode *tmp=q.front();
                q.pop();
                int index=0;

                if(left2right)
                    index=i;
                else
                    index=size-1-i;

                res[index]=tmp->val;
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            result.push_back(res);
            left2right=!left2right;

        }

        return result;

    }
};

int main()
{
    Solution a;

    return 0;
}
