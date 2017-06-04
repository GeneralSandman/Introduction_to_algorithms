#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1)>=0;
    }
private:
    int helper(vector<int>& nums, int s, int e){        
        return s==e ? nums[e] : max(nums[e] - helper(nums, s, e-1), nums[s] - helper(nums, s+1, e));
    }
};

int main()
{
    Solution a;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(2);

    cout << a.PredictTheWinner(nums) << endl;

    return 0;
}