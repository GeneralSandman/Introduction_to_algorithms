#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
  public:
    int maximumProduct(vector<int> &nums)
    {

        if (nums.size() < 3)
            return 0;

        vector<int> res(3, INT_MIN);

        for (auto t : nums)
        {
            top3(res, t);
        }
        int result = 1;

        for (auto i : res)
            result *= i;

        return result;
    }

  private:
    void top3(vector<int> &nums, int &number)
    {
        if (number > nums[0])
        {
            nums[2] = nums[1];
            nums[1] = nums[0];
            nums[0] = number;
        }
        else if (number > nums[1])
        {
            nums[2] = nums[1];
            nums[1] = number;
        }
        else if (number > nums[2])
        {
            nums[2] = number;
        }
    }
};

int main()
{
    Solution a;
    vector<int> n1 = {1, 2, 3, 4};
    cout << a.maximumProduct(n1) << endl;

    vector<int> n2 = {-1,-2,-3,-4};
    cout << a.maximumProduct(n2) << endl;
    return 0;
}
