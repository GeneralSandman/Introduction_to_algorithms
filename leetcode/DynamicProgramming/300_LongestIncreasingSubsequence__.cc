#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int result = 0;

        int begin = 0, end = nums.size() - 1;

        while (begin <= end)
        {
            int find = findMiddle(nums, begin, end);
            if (find > result)
                result = find;

            if()
        }

        return result;
    }

  private:
    int findMiddle(vector<int> &nums, int begin, int end)
    {
    }
};

int main()
{
    Solution a;

    return 0;
}
