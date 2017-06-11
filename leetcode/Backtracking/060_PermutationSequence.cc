#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> result;
        for(int i=1;i<=n;i++)
            result.push_back(i);
        
        int number=1;
        do{
            if(number==k)
                break;
            number++;
        }while(next_perm(result));

        string tmp;
        for(auto t:result)
            tmp+=char(t+48);

        return tmp;
    }

private:
    bool next_perm(vector<int> &nums)
    {
        vector<int>::iterator front = nums.end() - 2;
        vector<int>::iterator back = nums.end() - 1;
        while (front >= nums.begin() && *front >= *back)
        {
            front--;
            back--;
        }

        if (front < nums.begin())
            return false;

        vector<int>::iterator tmp = nums.end() - 1;

        while (*front >= *tmp)
            tmp--;

        swap(*tmp, *front);

        reverse(back, nums.end());
        return true;
    }
};


int main(){
    Solution a;
    cout<<a.getPermutation(9,17223)<<endl;
    return 0;
}


