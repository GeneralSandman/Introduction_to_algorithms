#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;

int weight[100];
bool tree[100][100];

bool haveSon(int i)
{
    for (int j = 0; j < 100; j++)
        if (tree[i][j] == true)
            return true;
    return false;
}

void dfs(vector<vector<int>> &result, vector<int> &tmp,
         int index, int target)
{
    if (!haveSon(index) && target == weight[index])
    {
        tmp.push_back(target);
        result.push_back(tmp);
        tmp.pop_back();
        return;
    }
    if (target < 0)
        return;

    for (int j = 0; j < 100; j++)
    {
        tmp.push_back(weight[index]);
        if (tree[index][j])
            dfs(result, tmp, j, target - weight[index]);
        tmp.pop_back();
    }
}

bool comp(const vector<int> &a, const vector<int> &b)
{
    for (int i = 0; i < a.size() && i < b.size(); i++)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
}

int main()
{
    memset(weight, 0, sizeof(weight));
    memset(tree, false, sizeof(tree));

    int allNum, nonLeafNum, target;
    cin >> allNum >> nonLeafNum >> target;

    for (int i = 0; i < allNum; i++)
        cin >> weight[i];

    for (int i = 0; i < nonLeafNum; i++)
    {
        int id, size;
        cin >> id >> size;
        for (int j = 0; j < size; j++)
        {
            int tmp;
            cin >> tmp;
            tree[id][tmp] = true;
        }
    }

    vector<vector<int>> result;
    vector<int> tmp;
    dfs(result, tmp, 0, target);

    sort(result.begin(), result.end(), comp);

    for (auto i : result)
    {
        cout << i[0];
        for (int j = 1; j < i.size(); j++)
            cout << " " << i[j];
        cout << endl;
    }

    return 0;
}