#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

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

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j])
                    dfs(result, matrix, i, j, m, n);
                else
                    result[i][j]=0;
            }

        return result;
    }

  private:
    void dfs(vector<vector<int>> &res, vector<vector<int>> &matrix,
             int i, int j, int m, int n)
    {
        if (checkZero(matrix, i, j, m, n))
            res[i][j] = 1;
        else
        {
            if (i > 0)
            {
                dfs(res, matrix, i - 1, j, m, n);
                res[i][j] = min(res[i][j], res[i - 1][j]);
            }
            if (j > 0)
            {
                dfs(res, matrix, i, j - 1, m, n);
                res[i][j] = min(res[i][j], res[i][j - 1]);
            }
            if (i < m - 1)
            {
                dfs(res, matrix, i + 1, j, m, n);
                res[i][j] = min(res[i][j], res[i + 1][j]);
            }
            if (j < n - 1)
            {
                dfs(res, matrix, i, j + 1, m, n);
                res[i][j] = min(res[i][j], res[i][j + 1]);
            }
        }
    }

  private:
    bool checkZero(vector<vector<int>> &matrix,
                   int i, int j, int m, int n)
    {
        if (i > 0 && matrix[i - 1][j] == 0)
            return true;
        if (j > 0 && matrix[i][j - 1] == 0)
            return true;
        if (i < m - 1 && matrix[i + 1][j] == 0)
            return true;
        if (j < n - 1 && matrix[i][j + 1] == 0)
            return true;
    }
};

int main()
{
    Solution a;

    return 0;
}
