#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
  public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>> &edges)
    {
        vector<int> result;
        if (!n)
            return result;

        vector<set<int>> graph(n); //first:course second:needed
        vector<int> inGreed(n, 0); //
        makeGraph(edges, graph);
        countInGreed(graph, inGreed);

        int minLength=n;
        for(int i=0;i<n;i++){
            int cur=findLength(i,edges,graph,inGreed);
            if(cur<minLength)
            {
                result.erase(result.begin(),result.end());
                result.push_back(i);
            }
            else if(cur==minLength)
                result.push_back(i);
        }

        return result;

    }

  private:
    void makeGraph(vector<pair<int, int>> &edges, vector<set<int>> &graph)
    {
        for (auto t : edges)
        {
            graph[t.first].insert(t.second);
            graph[t.second].insert(t.first);
        }
    }

    void countInGreed(vector<set<int>> &graph, vector<int> &inGreed)
    {
        for(int i=0;i<graph.size();i++){
            inGreed[i]=graph[i].size();
        }
    }

    int findLength(int i,vector<pair<int, int>> &edges, vector<set<int>> &graph, vector<int> &inGreed)
    {
        if(inGreed[i]==1)
            return 1;
        
        inGreed[i]--;
        for(auto next:graph[i]){
            return 1+findLength(next,edges,graph,inGreed);
        }

    }
};

int main()
{
    Solution a;

    return 0;
}
