#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

bool persons[100][100];

bool haveSon(int i)
{
    for (int j = 0; j < 100; j++)
    {
        if (persons[i][j])
        {
            return true;
        }
    }

    return false;
}

void dfs(vector<int> &result)
{
    queue<int> level;
    level.push(1);

    while (!level.empty())
    {
        int size = level.size();
        int count = 0;

        for (int i = 0; i < size; i++)
        {
            int tmp = level.front();
            level.pop();
            
            for (int j = 0; j < 100; j++)
            {
                if (persons[tmp][j])
                    level.push(j);
            }
            if (!haveSon(tmp))
            {
                count++;
            }
        }

        result.push_back(count);
    }
}

int main()
{
    memset(persons, false, sizeof(persons));

    int allNum, nonLeafNum;
    cin >> allNum >> nonLeafNum;

    for (int i = 0; i < nonLeafNum; i++)
    {
        int id;
        int size;

        cin >> id >> size;

        for (int j = 0; j < size; j++)
        {
            int sonid;
            cin >> sonid;
            persons[id][sonid] = true;
        }
    }

    vector<int> result;
    dfs(result);

    if (!result.empty())
        cout << result[0];
    for (int i = 1; i < result.size(); i++)
        cout << " " << result[i];

    return 0;
}