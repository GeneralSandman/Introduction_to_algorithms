#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stdio.h>
#include <cmath>
#include <stack>

using namespace std;

class Solution
{
  public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int num = graph.size();
        vector<bool> visited(num, false);
        vector<int> safe(num, -1);
        //-1:not set
        //0: not safe
        //1: safe

        for (auto i = 0; i < num; i++)
            dfs(graph, visited, safe, i);
        vector<int> res;
        for (auto i = 0; i < num; i++)
        {
            if (safe[i] == 1)
                res.push_back(i);
        }
        return res;
    }

  private:
    bool dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &safe, int begin)
    {
        // cout << "visited " << begin << endl;
        if (graph[begin].empty())
        {
            safe[begin] = 1;
            return true;
        }

        if (visited[begin])
        {
            safe[begin] = 0;
            return false;
        }

        int numNext = graph[begin].size();
        visited[begin] = true;

        bool hasNotSafeSon = false;
        for (auto i = 0; i < numNext; i++)
        {
            if (safe[graph[begin][i]] == 0)
            {
                hasNotSafeSon = true;
            }
            else if (safe[graph[begin][i]] == -1 && !dfs(graph, visited, safe, graph[begin][i]))
            {
                hasNotSafeSon = true;
            }
        }
        visited[begin] = false;

        if (hasNotSafeSon)
            safe[begin] = 0;
        else
            safe[begin] = 1;
        return safe[begin] == 1;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    // vector<vector<int>> graph = {{1, 2}, {3}, {}, {4}, {1}};
    // vector<vector<int>> graph = {{1, 4}, {2}, {3}, {1}, {}};

    vector<int> res;
    res = a.eventualSafeNodes(graph);

    for (auto t : res)
        cout << t << endl;

    return 0;
}