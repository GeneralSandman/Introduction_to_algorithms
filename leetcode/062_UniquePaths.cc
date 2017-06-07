#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m>0&&n>0)
            return uniquePaths(m,n-1)+uniquePaths(m-1,n);
        else if(m==0 && n>0)
            return uniquePaths(m,n-1);
        else if(m>0 && n==0)
            return uniquePaths(m-1,n);
        else
            return 1;
    }
};

int main(){

    Solution a;
    cout<<a.uniquePaths(1,1);
    cout<<endl;
    cout<<a.uniquePaths(2,2);
    cout<<endl;
    
    cout<<a.uniquePaths(3,2);
    cout<<endl;
    
    cout<<a.uniquePaths(4,3);
    cout<<endl;
    
    cout<<a.uniquePaths(3,4);
    cout<<endl;
    
    cout<<a.uniquePaths(4,4);
    cout<<endl;
    
    return 0;
}

