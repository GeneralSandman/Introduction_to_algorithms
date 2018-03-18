#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

void findIncrease(vector<int> &nums,
                  int curlength,
                  int &maxlength,
                  int begin, int lastNum)
{
    if (begin >= nums.size())
    {
        maxlength = max(maxlength, curlength);
        return;
    }

    if (lastNum <= nums[begin])
        findIncrease(nums, curlength+1, maxlength, begin + 1, nums[begin]);
    findIncrease(nums, curlength, maxlength, begin + 1, lastNum);
}

int main()
{

    int likeNums;
    cin >> likeNums;
    map<int, int> likes;

    for (int i = 0; i < likeNums; i++)
    {
        int tmp;
        cin >> tmp;
        likes[tmp] = i + 1;
    }

    int nums;
    cin >> nums;
    vector<int> result;
    for (int i = 0; i < nums; i++)
    {
        int tmp;
        cin >> tmp;
        if (likes.find(tmp) != likes.end())
        {
            result.push_back(likes[tmp]);
        }
    }

    int maxLength = 0;
    findIncrease(result, 0, maxLength, 0, 0);
    cout << maxLength << endl;

    return 0;
}