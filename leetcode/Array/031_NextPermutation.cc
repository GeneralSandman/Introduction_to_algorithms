#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.empty())
            return;
        if (!next_perm(nums))
            sort(nums.begin(), nums.end());
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
    vector<int> nums = {3, 2, 1};
    a.nextPermutation(nums);
    for(auto t:nums)
        cout<<t<<" ";
    cout<<endl;
    return 0;
}
