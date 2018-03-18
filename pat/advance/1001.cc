#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void printInt(int a)
{
    if (a < 0)
        cout << '-';
    a = abs(a);
    if (a == 0)
    {
        cout << "0" << endl;
        return;
    }
    string result = "";
    int count = 0;
    while (a)
    {
        count++;
        if (count == 4)
        {
            result = ',' + result;
            count = 1;
        }
        else
        {
        }
        result = to_string(a % 10) + result;
        a /= 10;
    }

    cout << result << endl;
}

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;

    printInt(a + b);

    return 0;
}