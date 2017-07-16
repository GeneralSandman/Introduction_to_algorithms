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
        if (n <= 2)
            return n;
        vector<int> tmp(n + 2, 0);
        vector<vector<int>> res(n + 1, tmp);

        for (int i = 0; i < n; i++)
            res[i][i + 1] = 1;

        int i = 0, j = 2;
        int tmpj = 2;
        for (int q = 0; q < n; q++)
        {
            int tmp = res[i][j];
            for (int index = i; index < j; index++)
            {
                tmp += find(res, index, i, j);
            }

            while (j != n + 1)
            {
                res[i][j] = tmp;

                i++;
                j++;
            }

            i = 0;
            j = ++tmpj;
        }

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 2; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }

        return res[0][n];
    }

  private:
    int find(vector<vector<int>> &nums, int middle, int begin, int end)
    {
        return max(nums[begin][middle], 1) * max(nums[middle + 1][end], 1);
        return 0;
    }
};

int main()
{
    Solution a;
    cout << a.numTrees(4) << endl; //14
    return 0;
}
