#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==0)
            return 0;
        int result=s.size();

        vector<int> tmp(s.size()+1,0);
        vector<vector<int>> res(s.size()+1,tmp);
        for(int i=1;i<s.size()+1;i++)
            res[i][i]=1;
        
        for(int i=1;i<s.size()+1;i++){
            for(int j=1;j<s.size()+1;j++){
                
            }
        }

        result+=res[1][s.size()];
        return result;
    }
};

int main(){
    Solution a;
    
    return 0;
}


