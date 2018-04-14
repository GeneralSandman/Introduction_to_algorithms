#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <stdio.h>
#include <climits>

using namespace std;

typedef struct street
{
    int end;
    int length;
    int time;
} street;

int Dijkstra(map<int, vector<street>> &graph, vector<int> &pre, int begin, int end)
{
    vector<bool> visited(pre.size(), false);
    vector<int> dist(pre.size(), INT_MAX);
    vector<int> tim(pre.size(), INT_MAX);

    visited[begin] = true;
    dist[begin] = 0;
    tim[begin] = 0;

    while (true)
    {
        for (int i = 0; i < graph[begin].size(); i++)
        {
            if (dist[graph[begin][i].end] > dist[begin] + graph[begin][i].length)
            {
                dist[graph[begin][i].end] = dist[begin] + graph[begin][i].length;
                tim[graph[begin][i].end] = tim[begin] + graph[begin][i].time;
                pre[graph[begin][i].end] = begin;
            }
            else if (dist[graph[begin][i].end] == dist[begin] + graph[begin][i].length)
            {
                if (tim[graph[begin][i].end] > tim[begin] + graph[begin][i].time)
                {
                    tim[graph[begin][i].end] = tim[begin] + graph[begin][i].time;
                    pre[graph[begin][i].end] = begin;
                }
            }
        }

        int minIndex = -1;
        int minNum = INT_MAX;

        for (int i = 0; i < pre.size(); i++)
        {
            if (!visited[i] && dist[i] < minNum)
            {
                minIndex = i;
                minNum = dist[i];
            }
        }

        if (minIndex == -1)
            break;
        if (minIndex == end)
            break;
        begin = minIndex;
        visited[begin] = true;
    }
    return dist[end];
}

bool isSame(vector<int> &a, vector<int> &b)
{
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

vector<int> getPath(vector<int> &pre, int end)
{
    vector<int> res;
    while (end != -1)
    {
        res.push_back(end);
        end = pre[end];
    }
    reverse(res.begin(), res.end());
    return res;
}

void printPath(vector<int> &path)
{
    if (path.empty())
        return;
    cout << path[0];
    for (int i = 1; i < path.size(); i++)
        cout << " -> " << path[i];
}

int main()
{
    map<int, vector<street>> graph;
    int nodeNum, streetNum, begin, end;
    cin >> nodeNum >> streetNum;

    for (int i = 0; i < streetNum; i++)
    {
        int a, b, one, length, tim;
        scanf("%d%d%d%d%d", &a, &b, &one, &length, &tim);
        street tmp = {b, length, tim};
        graph[a].push_back(tmp);
        if (!one)
        {
            street tmp2 = {a, length, tim};
            graph[b].push_back(tmp2);
        }
    }

    cin >> begin >> end;

    vector<int> pre(nodeNum, -1);
    int shortest = Dijkstra(graph, pre, begin, end);
    vector<int> shortestPath = getPath(pre, end);

    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            graph[i][j].length = graph[i][j].time;
            graph[i][j].time = 1;
        }
    }

    fill(pre.begin(), pre.end(), -1);
    int fastest = Dijkstra(graph, pre, begin, end);
    vector<int> fastestPath = getPath(pre, end);

    if (isSame(shortestPath, fastestPath))
    {
        printf("Distance = %d; ", shortest);
        printf("Time = %d: ", fastest);
        printPath(shortestPath);
        cout << endl;
    }
    else
    {
        printf("Distance = %d: ", shortest);
        printPath(shortestPath);
        cout << endl;
        printf("Time = %d: ", fastest);
        printPath(fastestPath);
        cout << endl;
    }

    return 0;
}