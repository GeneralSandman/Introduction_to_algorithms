#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

//BFS
class Solution
{
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        if (!numCourses)
            return false;

        vector<set<int>> graph(numCourses); //first:course second:needed
        vector<int> inGreed(numCourses, 0); //
        makeGraph(prerequisites, graph);
        countInGreed(prerequisites, inGreed);

        for (int i = 0; i < numCourses; i++)
        {
            int j = 0;
            for (; j < numCourses; j++)
                if (inGreed[j] == 0)
                    break;
            if (j == numCourses)
                return false;
            inGreed[j] = -1;
            for (auto t : graph[j])
                inGreed[t]--;
        }
        return true;
    }

  private:
    void makeGraph(vector<pair<int, int>> &prerequisites, vector<set<int>> &res)
    {
        for (auto t : prerequisites)
            res[t.second].insert(t.first);
    }

    void countInGreed(vector<pair<int, int>> &prerequisites, vector<int> &inGreed)
    {
        for (auto t : prerequisites)

            inGreed[t.first]++;
    }
};

//DFS
class Solution2
{
  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        if (!numCourses)
            return false;

        vector<set<int>> graph(numCourses); //first:course second:needed
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        makeGraph(prerequisites, graph);

        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(graph,i,visited,onpath))
                
        }

        return true;
    }

  private:
    void makeGraph(vector<pair<int, int>> &prerequisites, vector<set<int>> &res)
    {
        for (auto t : prerequisites)
            res[t.second].insert(t.first);
    }

    bool dfs(vector<set<int>>&graph,int node,vector<bool>&visited,vector<bool>&onpath){
        onpath[node]=visited[node]=true;
        for(auto t:graph[node]){
            if(dfs(graph,t,visited,onpath))
        }
    }
};

int main()
{
    Solution a;

    return 0;
}
