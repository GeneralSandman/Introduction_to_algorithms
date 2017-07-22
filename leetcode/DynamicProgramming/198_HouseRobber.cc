#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;
class Solution1 {
	public:
		int rob(vector<int>& nums) {
			if(nums.empty())
				return 0;
			return findMax(nums,nums.size()-1);
		}

	private:
		int findMax(vector<int> & nums,int i){
			if(i-2>=0)
				return max(findMax(nums,i-2)+nums[i],findMax(nums,i-1));
			else if(i-1>=0)
				return max(nums[i],findMax(nums,i-1));
			else
				return nums[i];
	
		}
};


class Solution2 {
public:
    int rob(vector<int>& nums) {
		if(nums.empty())
			return 0;
        vector<int> res(nums.size()+1,0);

		res[1]=nums[0];

		for(int i=2;i<nums.size()+1;i++)
		{
			res[i]=max(res[i-1],res[i-2]+nums[i-1]);

		}
		return res[nums.size()];

    }
};

int main(){
	Solution2 a;
	vector<int> n1={3, 2, 1, 5};
	cout<<a.rob(n1)<<endl;

		vector<int> n2={114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
	cout<<a.rob(n2)<<endl;
	return 0;
}


