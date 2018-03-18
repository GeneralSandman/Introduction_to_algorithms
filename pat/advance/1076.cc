#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Person
{
    int id;
    vector<int> funs;
};

typedef struct Person Person;

void dfs(map<int, Person> &persons,
         set<int> &visited,
         int level,
         int maxLevel,
         int id)
{
    if (level > maxLevel)
        return;

    for (auto t : persons[id].funs)
    {
        if (visited.find(t) == visited.end())
        {
            visited.insert(t);
            dfs(persons, visited, level + 1, maxLevel, t);
        }
    }
}

int main()
{
    int nums, maxLevel;
    cin >> nums >> maxLevel;

    map<int, Person> persons;

    Person tmp;
    for (int i = 0; i < nums; i++)
    {
        tmp.id = i + 1;
        persons[i + 1] = tmp;
    }

    for (int i = 0; i < nums; i++)
    {
        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            int tmp;
            cin >> tmp;
            persons[tmp].funs.push_back(i + 1);
        }
    }

    int query_size;
    cin >> query_size;
    vector<int> result;
    set<int> visited;
    for (int i = 0; i < query_size; i++)
    {
        int tmp;
        cin >> tmp;
        dfs(persons, visited, 1, maxLevel, tmp);
        result.push_back(visited.size());
        visited.clear();
    }

    for (auto t : result)
        cout << t << endl;

    return 0;
}