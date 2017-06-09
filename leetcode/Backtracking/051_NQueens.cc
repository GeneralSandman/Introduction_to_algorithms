#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> tmp;
        string tm;
        for (int i = 0; i < n; i++)
            tm += '.';
        for (int i = 0; i < n; i++)
            tmp.push_back(tm);

        vector<vector<string>> result;
        if (!n)
            return result;
        solve(result, tmp, n, 0);
        return result;
    }

  private:
    void solve(vector<vector<string>> &result, vector<string> &tmp, int n, int a)
    {
        if (a == n)
        {
            result.push_back(tmp);
        }

        else
        {

            for (int i = 0; i < n; i++)
            {
                if (test(tmp, n, a, i))
                {
                    tmp[a][i] = 'Q';
                    solve(result, tmp, n, a + 1);
                    tmp[a][i] = '.';
                }
            }
        }
    }

    bool test(vector<string> &result, int n, int a, int b)
    {
        for (int i = 0; i < n; i++)
        {
            if ((i != b && result[a][i] == 'Q') || (i != a && result[i][b] == 'Q'))
                return false;
        }

        for (int i = a, j = b; i < n && j < n; i++, j++)
            if (i != a && result[i][j] == 'Q')
                return false;

        for (int i = a, j = b; i >= 0 && j >= 0; i--, j--)
            if (i != a && result[i][j] == 'Q')
                return false;

        for (int i = a, j = b; i < n && j >= 0; i++, j--)
            if (i != a && result[i][j] == 'Q')
                return false;

        for (int i = a, j = b; i >= 0 && j < n; i--, j++)
            if (i != a && result[i][j] == 'Q')
                return false;

        return true;
    }
};

int main()
{
    vector<vector<string>> result;
    Solution a;

    result = a.solveNQueens(8);

    for (int i = 0; i < result.size(); i++)
    {
        for (auto t : result[i])
            cout << t << endl;
        cout << "------" << endl;
    }

    cout << "------------" << result.size() << endl;

    return 0;
}
