#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main()
{
    string source, pattern;
    set<char> dele;

    getline(cin, source);
    getline(cin, pattern);

    for (auto t : pattern)
        dele.insert(t);

    cout << source << endl
         << pattern << endl;

    for (auto t : source)
    {
        if (dele.find(t) == dele.end())
            cout << t;
    }

    cout << endl;

    return 0;
}
