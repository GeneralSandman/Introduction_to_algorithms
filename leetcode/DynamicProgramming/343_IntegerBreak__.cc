#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int integerBreak(int n)
    {
        vector<int> nums(n + 1, 0);
        nums[1] = 1;
        for (int i = 2; i < n + 1; i++)
        {
            for (int j=1;j<=i-1;j++)
                nums[i] = max(nums[i], max(nums[i-j] * nums[j], (i-j) * j));
        }

        return nums[n];
    }
};

int main()
{
    Solution a;
    int n;
    cin>>n;
    cout<<a.integerBreak(n)<<endl;

    return 0;
}
