#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;
class Solution1 {
public:
    int numDistinct(string s, string t) {
        int m=t.size();
        int n=s.size();

        if(m>n)
            return 0;

        vector<int> tmp(n+1,0);
        vector<vector<int>> res(m+1,tmp);

        for(int i=0;i<n+1;i++)
            res[0][i]=1;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(t[i-1]==s[j-1]){
                    res[i][j]=res[i][j-1]+res[i-1][j-1];
                }
                else
                    res[i][j]=res[i][j-1];
            }
        }


        return res[m][n];
    }
};


int main(){
    Solution1 a;
    string s="rabbbbit",t="rabbit";
    cout<<a.numDistinct(s,t)<<endl;

    s="ccc";
    t="c";
    cout<<a.numDistinct(s,t)<<endl;
    
    
    return 0;
}


