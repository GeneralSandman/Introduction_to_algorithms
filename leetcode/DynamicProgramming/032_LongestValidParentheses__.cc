#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        int result = 0;
        if (s.size() == 0)
            return result;
        vector<int> res;
        for (int i = 0; i < s.size() - 1;)
        {
            if (s[i] == '(' && s[i + 1] == ')')
            {
                res.push_back(i);
                i += 2;
            }
            else
                i++;
        }

        // for(auto i:res)
        //     cout<<i<<" ";
        // cout<<endl;

        if (!res.empty())
            result = sub2(res, 0, res.size() - 1) * 2;

        return result;
    }

  private:
    int sub2(vector<int> &nums, int begin, int end)
    {
        if (begin == end)
            return 1;

        int middle = (begin + end) / 2;
        int l = sub2(nums, begin, middle);
        int r = sub2(nums, middle + 1, end);
        int m = 0;
        if (nums[middle + 1] - nums[middle] == 2)
            m = subacrossL(nums, middle) + subacrossR(nums, middle + 1);

        return max(max(l, r), m);
    }

  private:
    int subacrossL(vector<int> &nums, int end)
    {
        int result = 1;
        for (int i = end - 1; i >= 0; i--)
        {
            if (nums[i] - nums[i + 1] == -2)
                result++;
            else
                break;
        }
        return result;
    }
    int subacrossR(vector<int> &nums, int begin)
    {
        int result = 1;
        for (int i = begin + 1; i < nums.size(); i++)
        {
            if (nums[i] - nums[i - 1] == 2)
                result++;
            else
                break;
        }
        return result;
    }
};

int main()
{
    Solution a;
    cout << a.longestValidParentheses("()(()(()()(()()()") << endl;
    cout << a.longestValidParentheses("()(()") << endl;
    cout << a.longestValidParentheses("(") << endl;
    cout << a.longestValidParentheses("()(())") << endl;
    // result=6

    return 0;
}

// ()(()
// ()(()(()()(()()()