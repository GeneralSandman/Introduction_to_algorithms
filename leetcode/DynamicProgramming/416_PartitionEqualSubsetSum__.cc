#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.empty() || nums.size() == 1)
            return false;

        vector<int> res;
        sort(nums.begin(), nums.end());
        int target = accumulate(nums.begin(), nums.end(), 0);
        if (target % 2)
            return false;
        target /= 2;
        bool result = false;
        sub(result, nums, res, target, 0);

        return result;
    }

    void sub(bool &result, vector<int> &nums, vector<int> &res, int target, int i)
    {
        if (i == nums.size() && target != 0)
        {
            return;
        }

        if (target == 0 && res.size() > 0 && res.size() < nums.size())
        {
            result = true;
            return;
        }

        res.push_back(nums[i]);
        sub(result, nums, res, target - nums[i], i + 1);
        res.pop_back();

        sub(result, nums, res, target, i + 1);
    }
};

int main()
{
    Solution a;

    vector<int> n1 = {1, 5, 11, 5};
    if (a.canPartition(n1))
        cout << "succ" << endl;

    vector<int> n2 = {1, 2, 3, 4, 5, 6, 7};
    if (a.canPartition(n2))
        cout << "succ" << endl;

    vector<int> n3 = {100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100};
    if (a.canPartition(n3))
        cout << "succ" << endl;

    return 0;
}
