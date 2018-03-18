#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int brain[1286][128][60];
int M, N, L, T;

int nexti[6] = {0, 0, 1, 0, 0, -1};
int nextx[6] = {0, 1, 0, 0, -1, 0};
int nexty[6] = {1, 0, 0, -1, 0, 0};

int allCount = 0;

void dfs(int i, int x, int y, int &count, bool isRoot)
{
    count++;
    brain[i][x][y] = 0;
    for (int j = 0; i < 6; i++)
    {
        int ii = i + nexti[j];
        int xx = x + nextx[j];
        int yy = y + nexty[j];

        if ((0 <= ii && ii < L) &&
            (0 <= xx && xx < M) &&
            (0 <= yy && yy < N) &&
            (brain[ii][xx][yy] == 1))
        {
            dfs(ii, xx, yy, count, false);
        }
    }

    if (count >= T && isRoot)
        allCount += count;
}

int main()
{
    memset(brain, 0, sizeof(brain));
    cin >> M >> N >> L >> T;

    for (int i = 0; i < L; i++)
        for (int x = 0; x < M; x++)
            for (int y = 0; y < N; y++)
                cin >> brain[i][x][y];

    for (int i = 0; i < L; i++)
        for (int x = 0; x < M; x++)
            for (int y = 0; y < N; y++)
                if (brain[i][x][y] == 1)
                {
                    int count = 0;
                    dfs(i, x, y, count, true);
                }

    cout << allCount << endl;

    return 0;
}