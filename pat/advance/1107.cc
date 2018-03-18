#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

bool persons[1000][1001];

set<int> visited;

set<int> curHobs;
vector<int> sameHobPersons;

void haveSameHob(int index, vector<int> &result)
{
    for (int i = 0; i < 1001; i++)
    {
        if (persons[index][i])
        {
            for (int j = 0; j < 1000; j++)
            {
                if (i != j && persons[j][i])
                    result.push_back(j);
            }
        }
    }
}

void bfs(int index, vector<int> &result)
{
    queue<int> que;
    que.push(index);
    visited.insert(index);

    int all = 0;

    while (!que.empty())
    {
        int size = que.size();
        all += size;
        for (int i = 0; i < size; i++)
        {
            int front = que.front();
            // cout << "process " << front << endl;
            que.pop();
            haveSameHob(front, sameHobPersons);

            for (auto t : sameHobPersons)
                if (visited.find(t) == visited.end())
                {
                    visited.insert(t);
                    que.push(t);
                }
            sameHobPersons.clear();
        }
    }

    result.push_back(all);
}

int main()
{
    memset(persons, false, sizeof(persons));

    int nums;
    cin >> nums;

    for (int i = 0; i < nums; i++)
    {
        int size;
        scanf("%d: ", &size);
        for (int j = 0; j < size; j++)
        {
            int tmp;
            cin >> tmp;
            persons[i][tmp] = true;
        }
    }

    vector<int> result;

    for (int i = 0; i < nums; i++)
    {
        if (visited.find(i) == visited.end())
        {
            bfs(i, result);
        }
    }

    sort(result.begin(), result.end(), [](const int a, const int b) { return a > b; });

    cout << result.size() << endl;
    if (result.empty())
        return 0;
    cout << result[0];
    for (int i = 1; i < result.size(); i++)
        cout << " " << result[i];
    cout << endl;

    return 0;
}