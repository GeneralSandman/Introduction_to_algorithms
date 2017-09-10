#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        int len=0;

        vector<int>tmp(s.size()+1,0);
        vector<vector<int>> res(s.size()+1,tmp);

        for(int i=1;i<s.size()+1;i++)
            res[i][i]=1;
        
        int i=1;

    }
};

int main(){
    Solution a;
    
    return 0;
}


