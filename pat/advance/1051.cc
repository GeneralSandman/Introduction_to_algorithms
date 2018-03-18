#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

bool check(const vector<int> &push, const vector<int> &seq, int maxCap)
{
    int index1 = 0, index2 = 0;
    int len1 = push.size(), len2 = seq.size();
    stack<int> tmp;

    while (index1 < len1 && index2 < len2)
    {
        if (push[index1] == seq[index2])
        {
            index1++;
            index2++;
            while (!tmp.empty() && tmp.top() == seq[index2])
            {
                tmp.pop();
                index2++;
            }
        }
        else
        {
            tmp.push(push[index1++]);
            if (tmp.size() > maxCap)
                return false;
        }
    }

    return tmp.empty();
}

int main()
{
    vector<vector<int>> seq;

    int maxCap;
    int len;
    int size;
    cin >> maxCap >> len >> size;

    seq.reserve(size);

    vector<int> push;
    for (int i = 0; i < len; i++)
        push.push_back(i + 1);

    for (int i = 0; i < size; i++)
    {
        int tmp;
        for (int j = 0; j < len; j++)
        {
            cin >> tmp;
            seq[i].push_back(tmp);
        }
    }

    for (auto t : seq)
    {
        if (check(push, t, maxCap))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}