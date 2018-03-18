#include <stdio.h>
#include <queue>
using namespace std;
int serve_time[1001];
int ans[1001];
queue<int> Q[21];
int main(void)
{
    int w, cap, cus, k; //分别记录窗口数量、窗口最大人数、顾客数量和查询数量
    int i, j;
    scanf("%d%d%d%d", &w, &cap, &cus, &k);
    for (i = 1; i <= cus; i++)
    {
        scanf("%d", &serve_time[i]);
    }

    int sum = 0;
    int count = 1;
    for (int ti = 0; ti < 540; ti = ti + 1)
    { //以时间来作为循环，这个很关键
        for (i = 0; i < w; i++)
        {
            for (j = 0; j < Q[i].size(); j++)
            {
                if (ti == ans[Q[i].front()])
                { //如果当前队伍的人服务结束了
                    Q[i].pop();
                    sum--;

                    if (!Q[i].empty())
                    { //并且计算当前队伍下一个人的结束时间
                        int tmp = Q[i].front();
                        ans[tmp] = ti + serve_time[tmp]; //结束时间为当前时间+顾客的服务时间
                    }
                }
            }
        }

        while (sum < w * cap && count <= cus)
        {
            int min = 0;
            for (i = 0; i < w; i++)
                if (Q[min].size() > Q[i].size())
                    min = i;
            //找到人最少的那个队伍
            if (Q[min].size() == 0)
                ans[count] = ti + serve_time[count]; //如果队伍没人则直接开始服务，并且计算结束时间
            if (Q[min].size() < cap && count <= cus)
            {
                Q[min].push(count); //否则把让下一个顾客进队
                count++;
                sum++;
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        int query;
        scanf("%d", &query);
        if (ans[query] == 0)
            puts("Sorry"); //值为0说明没有被开始服务，只能Sorry
        else
        {
            int hour, min;
            hour = 8 + ans[query] / 60;
            min = ans[query] % 60;
            printf("%02d:%02d\n", hour, min); //把时间转换为标准格式并输出
        }
    }
    return 0;
}
