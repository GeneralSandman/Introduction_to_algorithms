#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;
class Solution
{
  public:
    int findIntegers(int num)
    {
        vector<int> res(num + 1, 0);
        res[0] = 1;
        for (int i = 0; i <= num; i++)
            res[i] = testConsOnes(i) + res[i - 1];
        
        return res[num];
    }

  public:
    bool testConsOnes(int num)
    {
        int key = 1;

        int pre = -1;
        int index = 1;

        while (key <= num)
        {
            if (key & num)
            {
                if (index - pre == 1)
                    return 0;
                else
                    pre = index;
            }

            index++;
            key <<= 1;
        }

        return 1;
    }
};

int main()
{
    Solution a;
    cout<<a.findIntegers(1000000000)<<endl;

    return 0;
}
