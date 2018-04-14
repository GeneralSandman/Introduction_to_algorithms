#include <iostream>
#include <string>

using namespace std;
#include <vector>
#include <climits>

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int local = nums[0];
        int global = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            local = max(local + nums[i], nums[i]);
            global = max(local, global);
        }

        return global;
    }
};

int main()
{
    class Solution s;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << s.maxSubArray(nums) << endl;

    nums = {1, 2, 1};
    cout << s.maxSubArray(nums) << endl;

    return 0;
}
