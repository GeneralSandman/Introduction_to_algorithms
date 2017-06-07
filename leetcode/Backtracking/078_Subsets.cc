#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;
        m_fSubsets(result,nums,tmp,0,nums.size());

        return result;
    }
private:
    void m_fSubsets(vector<vector<int>> & result,vector<int> &nums,vector<int> & tmp,int begin,int number){
        if(number==0)
            result.push_back(tmp);
        if(begin>=nums.size())
            return;
        tmp.push_back(nums[begin]);
        m_fSubsets(result,nums,tmp,begin+1,number-1);
        tmp.pop_back();

        m_fSubsets(result,nums,tmp,begin+1,number-1);
        
    }
};


int main(){
    Solution a;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    
    vector<vector<int>> result;
    result=a.subsets(nums);

    for(auto t:result){
        for(auto i:t)
            cout<<i<<" ";
        cout<<endl;
    }

}