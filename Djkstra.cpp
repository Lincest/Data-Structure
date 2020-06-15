#include <bits/stdc++.h>
using namespace std;


int a[100][100]; //邻接矩阵
int vis[100];    //是否已经确定
int dis[100];    //确定最短路长度
int p[100];      //前驱
int change;      //迭代过程中结点i是否更新了,这个主要用来确定前驱是否要更新
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(a, 127, sizeof(a)); //127不是数字127,而是一个很大的数
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;                             //n条边,m个结点
    int x, y, cnt, mindis = 100, minvis = 100; //mindis,minvis记录迭代过程中最小的路径以及对应的结点
    while (n--)
    {
        cin >> x >> y >> cnt;
        a[x][y] = cnt;
    }
    for (int i = 0; i <= m; ++i)
    {                        //初始化
        a[i][i] = 0;         //自己到自己为0
        if (a[1][i] > 10000) //如果1与i不到达
            dis[i] = 10000;  //初始dis为10000
        else
        {
            dis[i] = a[1][i]; //若到达,则dis[i]=1 -> i
            p[i] = 1;         //前驱为1
        }
    }
    vis[1] = 1;
    dis[1] = 0;
    p[1] = 1;
    int i = 1; //从1开始
    cnt = 1;   //cnt开始计数,1已经确定,所以cnt初值=1
    while (true)
    {
        for (int j = 1; j <= m; ++j)
        {
            change = dis[j];
            dis[j] = min(a[i][j] + dis[i], dis[j]);
            if (dis[j] != change)
            {
                p[j] = i;
            }
            if (!vis[j])
            {
                if (dis[j] < mindis)
                {
                    mindis = dis[j];
                    minvis = j;
                }
            }
        }
        vis[minvis] = 1;
        dis[minvis] = mindis;
        i = minvis;
        if (++cnt == m)
            break;
        mindis = 100;
        minvis = 100;
    }
    //输出
    for (int i = 1; i <= m; ++i)
    {
        cout << "到" << i << "最短的距离是: " << dis[i] << endl;
        cout << "路径为: " << i;
        int k = i;
        while (p[k] != 1)
        {
            cout << " <- " << p[k];
            k = p[k];
        }
        cout << " <- 1" << endl;
    }
    return 0;
}

