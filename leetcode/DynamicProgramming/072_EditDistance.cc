#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if(m==0)
            return n;
        if(n==0)
            return m;
        vector<int> tmp(n+1, 0);
        vector<vector<int>> res;
        for (int i = 0; i < m+1; i++)
            res.push_back(tmp);

        for (int i = 0; i <= n; i++)
            res[0][i] = i;

        for (int i = 0; i <= m; i++)
            res[i][0] = i;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i-1] == word2[j-1])
                    res[i][j] = res[i - 1][j - 1];
                else
                    res[i][j] = min(res[i - 1][j - 1], min(res[i - 1][j], res[i][j - 1])) + 1;
            }
        }

        return res[m][n];
    }
};

int main()
{
    Solution s;
    string a;
    string b;
    cin>>a;
    cin>>b;
    cout<<s.minDistance(a,b)<<endl;


    return 0;
}
