#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    map<int, int> res;
    int size = 0;
    cin >> size;
    vector<int> nums;
    nums.reserve(size);

    int tmp;
    for (int i = 0; i < size; i++)
    {
        cin >> tmp;
        nums.push_back(tmp);
        res[tmp]++;
    }

    int flag = false;
    for (auto t : nums)
    {
        if (res[t] == 1)
        {
            cout << t << endl;
            flag = true;
            break;
        }
    }

    if (!flag)
        cout << "Node\n";

    return 0;
}