#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

string printOneNum(const int &n)
{
    string res;
    switch (n)
    {
    case 0:
        res = "ling";
        break;
    case 1:
        res = "yi";
        break;
    case 2:
        res = "er";
        break;
    case 3:
        res = "san";
        break;
    case 4:
        res = "si";
        break;
    case 5:
        res = "wu";
        break;
    case 6:
        res = "liu";
        break;
    case 7:
        res = "qi";
        break;
    case 8:
        res = "ba";
        break;
    case 9:
        res = "jiu";
        break;
    }

    return res;
}

void printNum(int n)
{

    string tmp = to_string(n);

    for (int i = 0; i < tmp.size(); i++)
    {
        cout << printOneNum(tmp[i] - 48);

        if (i != tmp.size() - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    string input;
    cin>>input;
    unsigned long long res = 0;
    for (auto t : input)
    {
        res += t - 48;
    }
    printNum(res);
    return 0;
}
