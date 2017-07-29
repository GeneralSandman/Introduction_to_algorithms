#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

struct UndirectedGraphNode
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){};
};

//Bread-first Search
class Solution
{
  private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> copyed;

  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node)
            return nullptr;

        UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
        copyed[node] = newnode;
        queue<UndirectedGraphNode *> next_q;
        next_q.push(node);

        while (!next_q.empty())
        {
            UndirectedGraphNode *next_node = next_q.front();
            next_q.pop();

            for (auto neighbour : next_node->neighbors)
            {
                if (copyed.find(neighbour) == copyed.end())
                {
                    UndirectedGraphNode *neighbour_copy =
                        new UndirectedGraphNode(neighbour->label);
                    copyed[neighbour] = neighbour_copy;
                    next_q.push(neighbour);
                }
                copyed[next_node]->neighbors.push_back(copyed[neighbour]);
            }
        }

        return newnode;
    }
};

//Depth-first Search

class Solution2
{
  private:
    map<UndirectedGraphNode *, UndirectedGraphNode *> copyed;

  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (!node)
            return nullptr;

        if (copyed.find(node) == copyed.end())
        {
            copyed[node] = new UndirectedGraphNode(node->label);
            for (auto n : node->neighbors)
            {
                copyed[node]->neighbors.push_back(cloneGraph(n));
            }
        }

        return copyed[node];
    }
};

int main()
{
    Solution a;

    return 0;
}
