#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <stdio.h>

using namespace std;

int serve_time[1000];
vector<queue<int>> queues(20);
int receive_time[1000];

int main()
{
    memset(serve_time, 0, sizeof(serve_time));
    memset(receive_time, 0, sizeof(receive_time));

    int N, M, K, Q;
    cin >> N >> M >> K >> Q;

    for (int i = 0; i < K; i++)
    {
        cin >> serve_time[i];
    }

    int sum = 0;
    int index = 0;

    for (int tim = 0; tim < 9 * 60; tim++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < queues[i].size(); j++)
            {
                if (tim == receive_time[queues[i].front()])
                {
                    queues[i].pop();
                    sum--;

                    if (!queues[i].empty())
                    {
                        int tmp = queues[i].front();
                        receive_time[tmp] = tim + serve_time[tmp];
                    }
                }
            }
        }

        while (N * M > sum && index < K)
        {
            int minIndex = 0;
            int minSize = queues[0].size();

            for (int i = 1; i < N; i++)
            {
                if (queues[i].size() < minSize)
                {
                    minSize = queues[i].size();
                    minIndex = i;
                }
            }

            if (queues[minIndex].empty() && index < K)
            {
                receive_time[index] = tim + serve_time[index];
            }
            if (queues[minIndex].size() < M && index < K)
            {
                queues[minIndex].push(index);
                sum++;
                index++;
            }
        }
    }

    for (int i = 0; i < Q; i++)
    {
        int tmp;
        cin >> tmp;
        if (receive_time[tmp] == 0)
            cout << "Sorry\n";
        else
        {
            int hour = receive_time[tmp] / 60 + 8;
            int min = receive_time[tmp] % 60;
            printf("%02d:%02d\n", hour, min);
        }
    }

    return 0;
}