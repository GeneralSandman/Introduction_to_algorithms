#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int findTargetSumWays(vector<int> &nums, int S)
    {
        sort(nums.begin(), nums.end());
        int result = 0;
        fun(nums, result, 0, S);
        return result;
    }

  private:
    void fun(vector<int> &nums, int &result, int begin, int target)
    {
        if (begin == nums.size() && target == 0)
        {
            result++;
            return;
        }
        else if (begin < nums.size())
        {

            fun(nums, result, begin + 1, target - nums[begin]);
            fun(nums, result, begin + 1, target + nums[begin]);
        }
    }
};

int main()
{
    Solution a;
    vector<int> nums;
    for (int i = 0; i < 5; i++)
        nums.push_back(1);
    cout << a.findTargetSumWays(nums, 3) << endl;
    return 0;
}
