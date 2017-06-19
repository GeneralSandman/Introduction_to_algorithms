#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int result = 0;
        if (obstacleGrid.empty())
            return 0;
        if (obstacleGrid[0].empty())
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                {
                    obstacleGrid[i][j] = (i > 0 ? obstacleGrid[i - 1][j] : 0) + (j > 0 ? obstacleGrid[i][j - 1] : 0);
                    if (j == 0 && i == 0)
                        obstacleGrid[i][j] = 1;
                }
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};

int main()
{
    Solution a;
    vector<vector<int>> nums;
    vector<int> tmp = {0, 0};
    nums.push_back(tmp);
    nums.push_back(tmp);

    cout << a.uniquePathsWithObstacles(nums) << endl;

    return 0;
}
