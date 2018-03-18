#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

struct Node
{
    string address;
    int key;
    string next;
};

typedef struct Node Node;

bool comp(const Node &a, const Node &b)
{
    return a.key < b.key;
}

int main()
{
    int size = 0;
    string head;
    cin >> size >> head;

    vector<Node> res;
    res.reserve(size);

    map<string, Node> list;

    string a, n;
    int k;
    for (int i = 0; i < size; i++)
    {
        cin >> a >> k >> n;
        Node tmp = {a, k, n};
        list[a] = tmp;
    }

    while (head != "-1")
    {
        res.push_back(list[head]);
        head = list[head].next;
    }

    sort(res.begin(), res.end(), comp);

    if (size == 0)
    {
        cout << size << " -1\n";
        return 0;
    }

    cout << size << " " << res[0].address << endl;

    if (size == 1)
    {
        cout << res[0].address << " " << res[0].key << " -1\n";
        return 0;
    }

    for (int i = 0; i < size - 1; i++)
    {
        cout << res[i].address << " " << res[i].key << " " << res[i + 1].address << endl;
    }
    cout << res[size - 1].address << " " << res[size - 1].key << " -1\n";

    return 0;
}