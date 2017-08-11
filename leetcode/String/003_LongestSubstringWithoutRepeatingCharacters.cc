#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>dict(256,-1);
        int len=0;
        int start=-1;
        for(int i=0;i<s.size();i++){
            if(dict[s[i]]>start){
                start=dict[s[i]];
            }

            dict[s[i]]=i;
            len=max(len,i-start);
        }
        return len;
    }
};

int main(){
    Solution a;
    cout<<a.lengthOfLongestSubstring("abcabcbb")<<endl;
    return 0;
}


