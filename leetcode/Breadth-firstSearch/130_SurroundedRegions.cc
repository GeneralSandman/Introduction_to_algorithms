#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        if (!row)
            return;
        int col = board[0].size();
        if (!col)
            return;

        //change
        int i = 0, j = 0;

        for (i = 0; i < row; i++)
        {
            change(board, i, 0, row, col);
            if (col > 1)
                change(board, i, col - 1, row, col);
        }
        for (j = 1; j + 1 < col; j++)
        {
            change(board, 0, j, row, col);
            if (row > 1)
                change(board, row - 1, j, row, col);
        }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';

                if (board[i][j] == 'C')
                    board[i][j] = 'O';
            }
    }

  private:
    void change(vector<vector<char>> &board, int i, int j, int row, int col)
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = 'C';

            if (i + 1 < row)
                change(board, i + 1, j, row, col);
            if (j + 1 < col)
                change(board, i, j + 1, row, col);
            if (i > 1)
                change(board, i - 1, j, row, col);
            if (j > 1)
                change(board, i, j - 1, row, col);
        }
    }
};

int main()
{
    Solution a;
    vector<char> tmp;
    tmp.push_back('O');
    tmp.push_back('O');
    vector<vector<char>> v;
    v.push_back(tmp);
    v.push_back(tmp);

    a.solve(v);
    return 0;
}
