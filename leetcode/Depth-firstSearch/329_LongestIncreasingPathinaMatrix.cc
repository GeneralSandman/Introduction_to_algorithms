#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        if (!m)
            return 0;
        int n = matrix[0].size();
        if (!n)
            return 0;

        vector<int> tmp(n, -1);
        vector<vector<int>> path(m, tmp);

        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                dfs(result, path, matrix, i, j, m, n);
        }

        // for (int i = 0; i < m; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //         cout << path[i][j] << " ";
        //     cout << endl;
        // }

        return result;
    }

  private:
    void dfs(int &res, vector<vector<int>> &path,
             vector<vector<int>> &matrix, int i, int j, int m, int n)
    {
        if (path[i][j] == -1)
        {
            int tmp = 0;

            if (i > 0 && matrix[i][j] < matrix[i - 1][j])
            {
                dfs(res, path, matrix, i - 1, j, m, n);
                tmp = max(tmp, path[i - 1][j] + 1);
            }

            if (j > 0 && matrix[i][j] < matrix[i][j - 1])
            {
                dfs(res, path, matrix, i, j - 1, m, n);
                tmp = max(tmp, path[i][j - 1] + 1);
            }
            if (i + 1 < m && matrix[i][j] < matrix[i + 1][j])
            {
                dfs(res, path, matrix, i + 1, j, m, n);
                tmp = max(tmp, path[i + 1][j] + 1);
            }
            if (j + 1 < n && matrix[i][j] < matrix[i][j + 1])
            {
                dfs(res, path, matrix, i, j + 1, m, n);
                tmp = max(tmp, path[i][j + 1] + 1);
            }

            path[i][j] = max(tmp, 1);
        }

        res = max(path[i][j], res);
    }
};

int main()
{
    Solution a;
    vector<vector<int>> matrix;
    matrix.push_back({9, 9, 4});
    matrix.push_back({6, 6, 8});
    matrix.push_back({2, 1, 1});
    cout << a.longestIncreasingPath(matrix) << endl;

    vector<vector<int>> m;
    m.push_back({3, 4, 5});
    m.push_back({3, 2, 6});
    m.push_back({2, 2, 1});
    cout << a.longestIncreasingPath(m) << endl;

    return 0;
}
