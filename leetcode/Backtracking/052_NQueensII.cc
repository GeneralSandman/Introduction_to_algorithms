#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int totalNQueens(int n)
    {
        vector<string> tmp;
        string tm;
        for (int i = 0; i < n; i++)
            tm += '.';
        for (int i = 0; i < n; i++)
            tmp.push_back(tm);

        int result=0;
        if (!n)
            return result;
        solve(result, tmp, n, 0);
        return result;
    }

  private:
    void solve(int &result, vector<string> &tmp, int n, int a)
    {
        if (a == n)
        {
            result++;
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
    Solution a;
    cout<<a.totalNQueens(8);

    return 0;
}
