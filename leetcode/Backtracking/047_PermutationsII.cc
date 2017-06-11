#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (nums.empty())
            return result;
        sort(nums.begin(), nums.end());
        do
        {
            result.push_back(nums);
        } while (next_perm(nums));

        return result;
    }

  private:
    bool next_perm(vector<int> &nums)
    {
        vector<int>::iterator front = nums.end() - 2;
        vector<int>::iterator back = nums.end() - 1;
        while (front >= nums.begin() && *front >= *back)
        {
            front--;
            back--;
        }

        if (front < nums.begin())
            return false;

        vector<int>::iterator tmp = nums.end() - 1;

        while (*front >= *tmp)
            tmp--;

        swap(*tmp, *front);

        reverse(back, nums.end());
        return true;
    }
};

int main()
{
    Solution a;

    vector<int> nums = {2,2,1,1};

    vector<vector<int>> result = a.permuteUnique(nums);

    for (auto t : result)
    {
        for (auto i : t)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
