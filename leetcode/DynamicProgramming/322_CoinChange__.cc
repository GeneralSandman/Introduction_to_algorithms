#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;

        sort(coins.begin(), coins.end(), [](const int &a, const int &b) { return a > b; });
        int res = 0;

        int i = 0;
        while (amount > 0 && i < coins.size())
        {
            int tmp = amount / coins[i];
            if (tmp == 0)
            {
                i++;
            }else{
                amount-=tmp*coins[i];
                res+=tmp;
            }
        }
        if (amount == 0)
            return res;

        else
            return -1;
    }
};

int main()
{
    Solution a;
    vector<int> coins={2};
    int amount=3;

    cout<<a.coinChange(coins,amount)<<endl;
    return 0;
}
