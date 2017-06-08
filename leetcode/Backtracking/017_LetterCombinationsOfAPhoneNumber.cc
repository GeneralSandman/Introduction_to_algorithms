#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        string tmp;
        vector<string> nums = {" ",
                               "",
                               "abc",
                               "def",
                               "ghi",
                               "jkl",
                               "mno",
                               "pqrs",
                               "tuv",
                               "wxyz"};
        if(digits.size()==0)
            return result;
        comb(result, tmp, nums, digits, 0);
        return result;
    }

  private:
    void comb(vector<string> &result, string &tmp, vector<string> &nums, string &digits, int begin)
    {
        if (begin == digits.size())
            result.push_back(tmp);

        int index = digits[begin] - '0';
        for (int i = 0; i < nums[index].size(); i++)
        {
            string temp = tmp;
            tmp += nums[index][i];
            comb(result, tmp, nums, digits, begin + 1);
            tmp = temp;
        }
    }
};

int main()
{
    Solution a;
    vector<string> result=a.letterCombinations("23");
    for(auto t:result)
        cout<<t<<endl;
    return 0;
}
