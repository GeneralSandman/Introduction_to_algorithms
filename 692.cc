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
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> tmp;
        for (auto t : words)
        {
            tmp[t]++;
        }
        typedef pair<string, int> key;
        auto comp = [](const key &a, const key &b) { return a.second == b.second ? a.first > b.first : a.second < b.second; };
        priority_queue<key, vector<key>, decltype(comp)> q(comp);

        for (auto t : tmp)
        {
            q.push(t);
        }

        vector<string> res;
        while (!q.empty() && k--)
        {
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    };

  private:
};

int main()
{
    vector<string> v = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};

    Solution a;
    vector<string> res = a.topKFrequent(v, 4);

    for (auto t : res)
        cout << t << endl;

    return 0;
}