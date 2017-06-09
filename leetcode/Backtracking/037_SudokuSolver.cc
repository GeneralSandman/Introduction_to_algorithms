#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{

  public:
    void solveSudoku(vector<vector<char>> &board)
    {
        input(board, 0, 0);
    }

  private:
    bool result = false;
    void input(vector<vector<char>> &board, int a, int b)
    {
        if (b == 9)
        {
            a += 1;
            b = 0;
        }

        if (a == 9)
        {
            this->result = true;
            return;
        }

        if (board[a][b] == '.')
            for (char tmp = '1'; tmp <= '9'; tmp++)
            {
                board[a][b] = tmp;
                if (test(board, a, b))
                {
                    input(board, a, b + 1);
                }

                if (this->result)
                    return;
                board[a][b] = '.';
            }
        else
            input(board, a, b + 1);
    }

    bool test(vector<vector<char>> &board, int a, int b)
    {
        return testQuare(board, a, b) && testLine(board, a, b) && testList(board, a, b);
    }

    bool testQuare(vector<vector<char>> &board, int a, int b)
    {
        int index1 = (a / 3) * 3;
        int index2 = (b / 3) * 3;
        for (int i = index1; i < index1 + 3; i++)
            for (int j = index2; j < index2 + 3; j++)
            {
                if (i != a || j != b)
                {
                    if (board[i][j] == board[a][b])
                        return false;
                }
            }

        return true;
    }

    bool testLine(vector<vector<char>> &board, int a, int b)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != b && board[a][i] == board[a][b])
                return false;
        }

        return true;
    }

    bool testList(vector<vector<char>> &board, int a, int b)
    {
        for (int i = 0; i < 9; i++)
        {
            if (i != a && board[i][b] == board[a][b])
                return false;
        }

        return true;
    }
};

int main()
{
    Solution a;
    vector<string> nums = {"..9748...", "7........", ".2.1.9...", "..7...24.", ".64.1.59.", ".98...3..", "...8.3.2.", "........6", "...2759.."};

    vector<vector<char>> res(9);

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            res[i].push_back(nums[i][j]);
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 9; j++)
            cout << res[i][j];
        cout << endl;
    }

    cout << "--------\n";

    a.solveSudoku(res);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 9; j++)
            cout << res[i][j];
        cout << endl;
    }

    return 0;
}
