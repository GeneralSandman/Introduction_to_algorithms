#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>

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
    vector<int> findMode(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        map<int, int> times;
        int maxTimes = 0;

        makeMap(root, times, maxTimes);

        for (auto t : times)
        {
            if (t.second == maxTimes)
            {
                result.push_back(t.first);
            }
        }

        return result;
    }

  private:
    void makeMap(TreeNode *root, map<int, int> &res, int &maxTimes)
    {
        if (!root)
            return;
        res[root->val]++;
        maxTimes = max(maxTimes, res[root->val]);
        makeMap(root->left, res, maxTimes);
        makeMap(root->right, res, maxTimes);
    }
};

int main()
{
    Solution a;

    return 0;
}
