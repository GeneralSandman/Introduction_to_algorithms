#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int size = 0;
    int target = 0;
    cin >> size >> target;

    vector<int> coins;

    int tmp = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> tmp;
        coins.push_back(tmp);
    }

    sort(coins.begin(), coins.end());

    int begin = 0;
    int end = size - 1;

    while (begin < end)
    {
        if (coins[begin] + coins[end] == target)
            break;
        else if (coins[begin] + coins[end] > target)
            end--;
        else
            begin++;
    }

    if (begin >= end)
        cout << "No Solution\n";
    else
        cout << coins[begin] << " " << coins[end] << endl;

    return 0;
}