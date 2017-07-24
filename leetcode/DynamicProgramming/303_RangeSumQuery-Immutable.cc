#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;
class NumArray {
public:
    NumArray(vector<int> nums) {
        num=nums;
    }
    
    int sumRange(int i, int j) {
        if(i<0 || j<0 || i>=num.size() || j>=num.size() || i>j)
            return 0;
        int result=0;
        for(int in=i;in<=j;in++)
            result+=num[in];
        return result;
    }
private:
    vector<int> num;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */


int main(){
    vector<int> nums;
    NumArray a=new NumArray(nums);
    
    return 0;
}


