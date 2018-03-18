#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#define inf INT_MAX
using namespace std;
struct street{
    int end;
    int dis;
    int cost;   
};
int Dijkstra(vector<vector<street> >& map,int start,int end,int n,vector<int>& preNode)
{//n代表城市个数
    //dis
    vector<int> fromStartDis;//所走路径长度存储数组
    vector<int> fromStartCost;//用时存储数组
    vector<bool> visited;//访问标记数组
    //初始化
    fromStartDis.resize(n,inf);
    fromStartCost.resize(n,inf);
    preNode.resize(n,-1);
    visited.resize(n,false);
    visited[start]=true;
    fromStartDis[start]=0;
    fromStartCost[start]=0;
    //初始化结束
    while(true)
    {
        for(int i=0;i<map[start].size();++i)//更新路径
        {
            if(fromStartDis[map[start][i].end]>fromStartDis[start]+map[start][i].dis)
            {//找到更短的路径，更新路径长度和时间花费
                fromStartDis[map[start][i].end]=fromStartDis[start]+map[start][i].dis;
                fromStartCost[map[start][i].end]=fromStartCost[start]+map[start][i].cost;
                preNode[map[start][i].end]=start;
            }
            else if(fromStartDis[map[start][i].end]==fromStartDis[start]+map[start][i].dis)
            {//找到花费更少的路径，更新时间花费
                if(fromStartCost[map[start][i].end]>fromStartCost[start]+map[start][i].cost)
                {
                    fromStartCost[map[start][i].end]=fromStartCost[start]+map[start][i].cost;
                    preNode[map[start][i].end]=start;
                }
            }
        }
        int min=inf;
        int minIndex=-1;
        for(int i=0;i<n;++i)
        {
            if(!visited[i]&&fromStartDis[i]<min)
            {
                min=fromStartDis[i];
                minIndex=i;
            }
        }
        if(minIndex==-1)//结束,未找到路径
            break;
        start=minIndex;
        visited[start]=true;
        if(start==end)//结束，找到路径
            break;
    }
    return fromStartDis[end];

}
void reversePreNode(vector<int>& pre,int cur,vector<int>& remain)//剔除数组中不在最短路中的节点
{//remain保存最后start->end的路径
    if(cur==-1)
        return;
    remain.clear();
    while(cur!=-1)
    {
        remain.insert(remain.begin(),cur);
        cur=pre[cur];
    }
}
void prePrint(vector<int>& remain)
{//格式化输出
    if(remain.size()>0)
        cout<<remain[0];
    if(remain.size()>1)
        for(int i=1;i<remain.size();++i)
            cout<<" -> "<<remain[i];
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<street> > map;//二维数组map
    map.resize(n);
    street tmp;
    int start,oneWay;
    for(int i=0;i<m;++i)
    {
        cin>>start>>tmp.end>>oneWay>>tmp.dis>>tmp.cost;
        map[start].push_back(tmp);
        if(!oneWay)
        {
            int st=start;
            start=tmp.end;
            tmp.end=st;
            map[start].push_back(tmp);
        }
    }//buildTable
    int end;
    cin>>start>>end;
    vector<int>preDis;
    vector<int>preCost;
    int disSum=Dijkstra(map,start,end,n,preDis);
    cout<<"Distance = "<<disSum;
    vector<int>remainDis;//保存最短路的整个路径
    reversePreNode(preDis,end,remainDis);//剔除数组中不在最短路中的节点
    //至此，关于选取最短距离的最短路计算结束
    for(int i=0;i<n;++i)//改造map数组，直接用之前的Dijkstra进行计算
        for(int j=0;j<map[i].size();++j)
        {
            map[i][j].dis=map[i][j].cost;
            map[i][j].cost=1;
        }
    int disCost=Dijkstra(map,start,end,n,preCost);
    vector<int>remainCost;//保存最短路的整个路径
    int i;
    reversePreNode(preCost,end,remainCost);//剔除数组中不在最短路中的节点
    //以下部分用于比较，然后进行格式化的输出
    if(remainCost.size()==remainDis.size())
    {
        for(i=0;i<remainCost.size();++i)
            if(remainCost[i]!=remainDis[i])
                break;
        if(i>=remainCost.size())
        {
            cout<<"; "<<"Time = "<<disCost<<": ";
            prePrint(remainCost);
            cout<<endl;
        }
        else
        {
            cout<<": ";prePrint(remainDis);cout<<endl;
            cout<<"Time = "<<disCost<<": ";
            prePrint(remainCost);cout<<endl;
        }
    }
    else
    {
        cout<<": ";prePrint(remainDis);cout<<endl;
        cout<<"Time = "<<disCost<<": ";
        prePrint(remainCost);cout<<endl;
    }
    return 0;
}