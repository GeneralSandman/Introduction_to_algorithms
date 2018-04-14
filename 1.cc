#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stdio.h>
#include <set>

using namespace std;

map<char, string> a1, a2, a3;

void erase(multiset<char> &all, map<char, string> &a,
           char target)
{
    auto p = all.find(target);
    while (p != all.end())
    {
        for (auto i : a[target])
        {
            auto e=all.find
        }
    }
}

void find(const string &tmp, vector<int> &res)
{
    multiset<char> all;
    for (auto t : tmp)
        all.insert(t);

    while (!all.empty())
    {
        for (auto t : a1)
        {
            if (all.find(t.first) != all.end())
            {
                for (auto i : t.second)
                {
                    auto p = all.find(i);
                    all.erase(p);
                }
            }
        }

        for (auto t : a2)
        {
            if (all.find(t.first) != all.end())
            {
                for (auto i : t.second)
                {
                    auto p = all.find(i);
                    all.erase(p);
                }
            }
        }

        for (auto t : a3)
        {
            if (all.find(t.first) != all.end())
            {
                for (auto i : t.second)
                {
                    auto p = all.find(i);
                    all.erase(p);
                }
            }
        }
    }

    sort(res.begin(), res.end());
}

int main()
{
    a1['Z'] = "ZERO";
    a1['W'] = "TWO";
    a1['U'] = "FOUR";
    a1['X'] = "SIX";
    a1['G'] = "EIGHT";

    a1['O'] = "ONE";
    a1['R'] = "THREE";
    a1['F'] = "FIVE";
    a1['S'] = "SEVEN";

    a1['I'] = "NINE";

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        vector<int> res;

        find(tmp, res);
        for (auto t : res)
            cout << t;
        cout << endl;
    }

    return 0;
}