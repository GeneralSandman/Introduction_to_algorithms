#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
//Depth-first Search

class Solution
{
  public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> result;
        int m = matrix.size();
        if (!m)
            return result;
        int n = matrix[0].size();
        if (!n)
            return result;

        vector<bool> tmp(n, false);
        vector<vector<bool>> n1(m, tmp), n2(m, tmp);

        for (int j = 0; j < n; j++)
        {
            dfs(matrix, n1, 0, j, m, n);
            dfs(matrix, n2, m - 1, j, m, n);
        }

        for (int i = 0; i < m; i++)
        {
            dfs(matrix, n1, i, 0, m, n);
            dfs(matrix, n2, i, n - 1, m, n);
        }

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (n1[i][j] && n2[i][j])
                    result.push_back(make_pair(i, j));
            }

        return result;
    }

  private:
    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &res,
             int i, int j, int m, int n)
    {
        res[i][j] = true;
        if (i > 0 && matrix[i][j] <= matrix[i - 1][j] && !res[i - 1][j])
            dfs(matrix, res, i - 1, j, m, n);
        if (j > 0 && matrix[i][j] <= matrix[i][j - 1] && !res[i][j - 1])
            dfs(matrix, res, i, j - 1, m, n);
        if (i + 1 < m && matrix[i][j] <= matrix[i + 1][j] && !res[i + 1][j])
            dfs(matrix, res, i + 1, j, m, n);
        if (j + 1 < n && matrix[i][j] <= matrix[i][j + 1] && !res[i][j + 1])
            dfs(matrix, res, i, j + 1, m, n);
    }
};

int main()
{
    Solution a;
    //[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
    //result:[[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
    return 0;
}
