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

int main()
{
    Solution a;

    return 0;
}
