#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;

bool comp(const string &a, const string &b)
{
    //may float
    // string t1 = a + b;
    // string t2 = b + a;

    // return atoi(t1.c_str()) < atoi(t2.c_str());

    return a + b < b + a;
}

int main()
{
    int num;
    cin >> num;
    vector<string> result;
    for (int i = 0; i < num; i++)
    {
        string tmp;
        cin >> tmp;
        result.push_back(tmp);
    }

    sort(result.begin(), result.end(), comp);

    string res;
    for (auto t : result)
        res += t;

    int index = 0;
    for (; index < res.size() && res[index] == '0'; index++)
        ;

    if (index == res.size())
        cout << "0\n";
    else
    {
        printf("%s\n", res.c_str() + index);
    }

    return 0;
}