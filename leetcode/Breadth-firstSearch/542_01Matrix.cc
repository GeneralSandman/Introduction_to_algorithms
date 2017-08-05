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
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (!m)
            return vector<vector<int>>();
        int n = matrix[0].size();
        if (!n)
            return vector<vector<int>>(m);

        vector<int> tmp(n, -1);
        vector<vector<int>> result(m, tmp);

        // cout<<result.size()<<" "<<result[0].size()<<endl;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] && result[i][j] == -1)
                    dfs(result, matrix, i, j, m, n);
                else
                    result[i][j] = 0;
            }

        return result;
    }

  private:
    void dfs(vector<vector<int>> &res, vector<vector<int>> &matrix,
             int i, int j, int m, int n)
    {
        if (matrix[i][j] == 0)
        {
            res[i][j] = 0;
            return;
        }

        int min_ = INT_MAX;
        if (i > 0)
        {
            if (res[i - 1][j] == -1)
                dfs(res, matrix, i - 1, j, m, n);
            min_ = min(min_, res[i - 1][j] + 1);
        }
        if (j > 0)
        {
            if (res[i][j - 1] == -1)
                dfs(res, matrix, i, j - 1, m, n);
            min_ = min(min_, res[i][j - 1] + 1);
        }
        if (i < m - 1)
        {
            if (res[i + 1][j] == -1)
                dfs(res, matrix, i + 1, j, m, n);
            min_ = min(min_, res[i + 1][j] + 1);
        }
        if (j < n - 1)
        {
            if (res[i][j + 1] == -1)
                dfs(res, matrix, i, j + 1, m, n);
            min_ = min(min_, res[i][j + 1] + 1);
        }

        res[i][j] = min_;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> v;
    vector<int> tm1 = {0, 0, 0};
    vector<int> tm2 = {0, 0, 0};
    vector<int> tm3 = {1, 1, 1};

    v.push_back(tm1);
    v.push_back(tm2);
    v.push_back(tm3);

    vector<vector<int>> res = a.updateMatrix(v);

    for (auto t : res)
    {
        for (auto i : t)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
