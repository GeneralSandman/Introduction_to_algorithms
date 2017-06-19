#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;
class Solution1
{
  public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];

        vector<long long> tmp(n, 1);
        vector<vector<long long>> res;
        for (int i = 0; i < n; i++)
            res.push_back(tmp);
        for (int i = 0; i < n; i++)
            res[i][i] = nums[i];

        for (auto t : res)
        {
            for (auto i : t)
                cout << setfill(' ') << setw(6) << i << " ";

            cout << endl;
        }

        int i = 0;
        int j = 1;
        int tmpj = j;

        while (!(i == 0 && j == n - 1))
        {
            tmpj = j;
            for (; i < n && j < n;)
            {
                res[i][j] = getValue(res, i, j);
                i++;
                j++;
            }

            j = tmpj + 1;
            i = 0;
        }

        res[0][n - 1] = getValue(res, 0, n - 1);
        cout << "..........\n";
        for (auto t : res)
        {
            for (auto i : t)
                cout << setfill(' ') << setw(6) << i << " ";
            cout << endl;
        }

        int max = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (res[i][j] > max)
                    max = res[i][j];

        return max;
    }

  private:
    int getValue(vector<vector<long long>> &res, int i, int j)
    {
        if (!res[i + 1][j - 1])
            return 0;
        return res[i][j - 1] * res[i + 1][j] / res[i + 1][j - 1];
    }
};

class Solution
{
  public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return 0;
        if (n == 1)
            return nums[0];
        
        vector<long long> res(n);
        for(int i=0;i<n;i++)
            res[i]=nums[i];

        for()

        return res[n-1];

    }
};

int main()
{
    Solution a;
    vector<int> nums = {-2, 3, 2, -2, 4};
    cout << "result:" << a.maxProduct(nums) << endl;

    vector<int> n2 = {-2, 0, -1};
    cout << "result:" << a.maxProduct(n2) << endl;

    vector<int> n3 = {0, -1, -4, 4, -4, -5, -2, -1, -1, 2, 3, 5, 1, 3, -6, -1, -1, 0, 0, -2};
    cout << "result:" << a.maxProduct(n3) << endl;

    // to much time ,we have to change

    return 0;
}
