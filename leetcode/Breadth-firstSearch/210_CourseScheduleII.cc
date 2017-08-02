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
class Solution2 {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> toposort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs(graph, i, onpath, visited, toposort))
                return {};
        reverse(toposort.begin(), toposort.end());
        return toposort;
    }
private:
    vector<set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs(vector<set<int>>& graph, int node, vector<bool>& onpath, vector<bool>& visited, vector<int>& toposort) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true; 
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, toposort))
                return true;
        toposort.push_back(node);
        return onpath[node] = false;
    }
};

int main()
{
    Solution a;

    return 0;
}
