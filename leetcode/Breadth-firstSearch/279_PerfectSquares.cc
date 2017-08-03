#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

//Dynamic Programming
class Solution
{
  public:
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;

        vector<int> res(n + 1, INT_MAX);
        for (int i = 1; i < n + 1; i++)
        {
            int q=sqrt(i);
            if (q*q == i)
            {
                res[i] = 1;
                continue;
            }
            for (int j = 1; j*j < i; j++)
                res[i] = min(res[i], 1 + res[i - j*j]);       
            

            /*
            //Time Limit Exceeded
            for(int j=1;j<i;j++)
                res[i]=min(res[i],res[i]+res[i-j]);
            */
        }

        return res[n];
    }
};

int main()
{
    Solution a;
    for (int i = 0; i <= 8829; i++)
        cout << i << ":" << a.numSquares(i) << endl;

    return 0;
}
