#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.empty()){
            return result;
        }//if
        vector<int> visited;
        // 递归
        DFS(num,visited,result);
        return result;
    }
private:
    void DFS(vector<int> &num,vector<int> &visited,vector<vector<int> > &result){
        // 形成一个全排列
        if(num.size() == visited.size()){
            result.push_back(visited);
            return;
        }//if
        vector<int>::iterator isVisited;
        for(int i = 0;i < num.size();i++){
            // 判断num[i]是否已经访问过
           isVisited = find(visited.begin(),visited.end(),num[i]);
           // 如果没有访问过
           if(isVisited == visited.end()){
               visited.push_back(num[i]);
               DFS(num,visited,result);
               visited.pop_back();
           }//if
        }//for
    }
};

int main()
{
    Solution a;
    vector<int> nums={1,2,3};
    vector<vector<int>> result=a.permute(nums);
    for(int i=0;i<result.size();i++){
        for(auto t:result[i])
            cout<<t<<" ";
        cout<<endl;
    }
    return 0;
}
