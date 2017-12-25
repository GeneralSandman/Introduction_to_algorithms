#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

bool Just(int &a, int &num)
{
    if (a == 1)
        return true;
    if (a % 2 == 0)
    {
        a /= 2;
    }
    else
    {
        a = 3 * a + 1;
        a /= 2;
    }
    num++;
    return false;
}

int main()
{
    int a;
    cin >> a;

    int num = 0;
    
    while(!Just(a,num));

    cout<<num<<endl;


    return 0;
}
