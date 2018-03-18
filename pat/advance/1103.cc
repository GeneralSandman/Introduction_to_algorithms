#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

int N, K, P;
bool finded;

long long pow(int n, int p)
{
    if (p == 0)
        return 1;
    if (n == 1)
        return 1;
    int factor = n;
    for (int i = 1; i < p; i++)
        n *= factor;
    return n;
}

void dfs(vector<int> &result, vector<int> &tmp, int index, long long target)
{
    if (index == K)
    {
        if (target == 0)
        {
            copy(tmp.begin(), tmp.end(), result.begin());
            finded = true;
        }
        return;
    }

    long long low = index > 0 ? tmp[index - 1] : 1;
    long long up = sqrt(double(target));
    for (long long i = low; i <= up; i++)
    {
        long long res = pow(i, P);
        if (target >= res)
        {
            tmp[index] = i;
            dfs(result, tmp, index + 1, target - res);
        }
        else
        {
            return;
        }
    }
}

int main()
{
    cin >> N >> K >> P;
    finded = false;

    vector<int> result(K, 0), tmp(K, 0);
    dfs(result, tmp, 0, N);

    reverse(result.begin(), result.end());

    if (finded)
    {
        cout << N << " = ";

        cout << result[0] << "^" << P;

        for (int i = 1; i < result.size(); i++)
            cout << " + " << result[i] << "^" << P;
    }
    else
    {
        cout << "Impossible";
    }

    return 0;
}