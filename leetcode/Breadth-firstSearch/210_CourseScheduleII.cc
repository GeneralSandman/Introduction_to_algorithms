#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

//BFS
class Solution
{
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<int> result;
        if (numCourses == 0)
            return result;

        vector<set<int>> graph(numCourses);
        vector<int> inGreed(numCourses, 0);
        queue<int> zones;
        vector<bool> done(numCourses, false);

        makeGraph(numCourses, prerequisites, graph);
        countinGreed(prerequisites, inGreed);
        for (int i = 0; i < numCourses; i++)
            if (!inGreed[i])
                zones.push(i);
        for (int i = 0; i < numCourses; i++)
        {
            if (zones.empty())
                return {}; //haven't a node which inGreed==0 &&have surplus node can't
            //      push result
            int t = zones.front();
            zones.pop();
            result.push_back(t);
            for (auto next : graph[t])
            {
                inGreed[next]--;
                if (inGreed[next] == 0)
                    zones.push(next);
            }
        }
        return result;
    }

  private:
    void makeGraph(int num, vector<pair<int, int>> &prerequisites, vector<set<int>> &graph)
    {
        for (auto t : prerequisites)
        {
            graph[t.second].insert(t.first);
        }
    }
    void countinGreed(vector<pair<int, int>> &prerequisites, vector<int> &inGreed)
    {
        for (auto t : prerequisites)
        {
            inGreed[t.first]++;
        }
    }
};

//DFS
class Solution2
{
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        vector<int> result;
        if (numCourses == 0)
            return result;

        vector<set<int>> graph(numCourses);
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        makeGraph(prerequisites, graph);

        for (int i = 0; i < numCourses; i++)
        {
            if (!visited[i] && dfs(graph, i, visited, onpath,result))
                return {};
        }

        reverse(result.begin(),result.end());
        return result;
    }

  private:
    void makeGraph(vector<pair<int, int>> &prerequisites, vector<set<int>> &res)
    {
        for (auto t : prerequisites)
            res[t.second].insert(t.first);
    }

    bool dfs(vector<set<int>> &graph, int node, vector<bool> &visited, vector<bool> &onpath,vector<int> &result)
    {
        onpath[node] = visited[node] = true;
        for (auto t : graph[node])
        {
            if (onpath[t] || dfs(graph, t, visited, onpath,result))
                return true; //have cycle
        }
        result.push_back(node);

        onpath[node] = false; //recover the onpath[node]
        return false;
    }
};

int main()
{
    Solution a;

    return 0;
}
