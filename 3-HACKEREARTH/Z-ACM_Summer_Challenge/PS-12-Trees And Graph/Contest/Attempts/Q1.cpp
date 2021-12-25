#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int mxn = 500001;
vector<int> ar[500001];
int vis[500001], dist[500001];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : ar[curr])
        {
            if (vis[child] == 0)
            {
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}

int main()
{
    b_v_r();
    int n, m;
    cin >> n;
    m = n - 1;
    int a, b;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    int color1 = 0;
    int color2 = 0;
    BFS(1);
    for (int i = 1; i <= n; i++)
    {
        // cout << "dist[" << i << "]=" << dist[i] << endl;
        if(dist[i]%2!=0)
        {
            color1++;
        }
        else
        {
            color2++;
        }
    }
    cout << "2" << endl;
    cout << color1 << " " << color2 << endl;
    return 0;
}
