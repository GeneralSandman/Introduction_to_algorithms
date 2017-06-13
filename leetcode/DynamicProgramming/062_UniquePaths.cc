#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int uniquePaths(int m, int n)
    {
        vector<int> tmp(n, 0);
        vector<vector<int>> res(m, tmp);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                if (j == 0 || i == 0)
                    res[i][j] = 1;
                else
                    res[i][j] = res[i - 1][j] + res[i][j - 1];
        }

        return res[m - 1][n - 1];
    }
};

int main()
{

    Solution a;
    cout << a.uniquePaths(1, 1);
    cout << endl;

    cout << a.uniquePaths(1, 2);
    cout << endl;

    cout << a.uniquePaths(2, 2);
    cout << endl;

    cout << a.uniquePaths(3, 2);
    cout << endl;

    cout << a.uniquePaths(4, 3);
    cout << endl;

    cout << a.uniquePaths(3, 4);
    cout << endl;

    cout << a.uniquePaths(4, 4);
    cout << endl;

    cout << a.uniquePaths(23, 12) << endl; //to much time

    return 0;
}
