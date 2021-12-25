#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

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

vector<int> ar[100001];
// int mxn = 100000;
int vis[100001];

void dfs(int node)
{
    vis[node] = 1;
    // cout << v << " -> ";
    for (int child : ar[node])
    {
        if (!vis[child])
            dfs(child);
    }
}

int main()
{
    b_v_r();
    // Check Tree
    int n, m;
    cin >> n >> m;
    int a, b;
    int flag = 0;
    if (m >= n)
    {
        flag = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (!flag)
        {
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
    }

    if (m = n - 1)
    {
        // Tree with n node has n-1 edges
        int cc_count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(i);
                cc_count++;
            }
        }
        if (cc_count == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
