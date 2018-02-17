#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int change(const int &n, int begin, int end, int tag)
{
    if (n >= begin && n <= end)
    {
        return tag;
    }
    return n;
}

string convert(const int &n)
{
    string res;
    res = to_string(n);

    if (res.size() == 1)
    {
        res="00"+res;
    }
    else if (res.size() == 2)
    {
        res="0"+res;
    }

    return res;
}

void fun(const vector<vector<int>> &res, vector<vector<string>> &r, int begin, int end, int tag)
{
    int m = res.size();
    int n = res[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            r[i][j] = convert(change(res[i][j], begin, end, tag));
        }
    }
}

int main()
{
    int m, n;
    int begin, end;
    int tag;

    cin >> m >> n >> begin >> end >> tag;

    vector<int> tmp(n, 0);
    vector<vector<int>> res(m, tmp);

    vector<string> t(n, "");
    vector<vector<string>> s(m, t);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> res[i][j];
        }
    }

    fun(res, s, begin, end, tag);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
