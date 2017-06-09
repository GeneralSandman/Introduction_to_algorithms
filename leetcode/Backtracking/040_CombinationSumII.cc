#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        if (candidates.empty())
            return result;

        sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        comb(candidates, target, 0, result, tmp);

        sort(result.begin(), result.end());
        auto p = unique(result.begin(), result.end());
        result.erase(p, result.end());

        return result;
    }

  private:
    void comb(vector<int> &can, int target, int begin, vector<vector<int>> &result, vector<int> &tmp)
    {
        if (target == 0)
            result.push_back(tmp);

        if (target < 0 || begin == can.size())
            return;
        if (target == 0)
            result.push_back(tmp);
        else
        {
            tmp.push_back(can[begin]);
            comb(can, target - can[begin], begin + 1, result, tmp);
            tmp.pop_back();

            comb(can, target, begin + 1, result, tmp);
        }
    }
};

int main()
{
    Solution a;
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> result = a.combinationSum2(nums, 8);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
