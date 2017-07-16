#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int numTrees(int n)
    {
        vector<int> tmp(n + 1, 0);
        vector<vector<int>> res(n + 1, tmp);

        for (int i = 1; i < n + 1; i++)
            res[i][i] = 1;

        int i = 1, j = 2;
        int tmpj = 2;
        for (int q = 0; q < n-1; q++)
        {
            for (int index = i; index <= j; index++)
            {
                res[i][j] += find(res, index, i, j);
            }

            i++;
            j++;

            if (j > n)  
            {
                i = 1;
                j = ++tmpj;
            }
        }

        for (int i = 0; i < n+1; i++)
        {
            for (int j = 0; j < n+1; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }

        return res[1][n];
    }

  private:
    int find(vector<vector<int>> &nums, int middle, int begin, int end)
    {
        return max(nums[begin][middle - 1], 1) * max(nums[middle + 1][end], 1);
    }
};

int main()
{
    Solution a;
    cout << a.numTrees(3) << endl;
    return 0;
}
