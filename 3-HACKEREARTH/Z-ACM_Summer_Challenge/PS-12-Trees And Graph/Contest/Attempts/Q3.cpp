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

vector<int> ar[1000002];

int tem[1000002];

int vis[1000002];



void dfs(int node)
{
    vis[node] = 1;

    // cout << v << " -> ";
    for (int child : ar[node])
    {
        if (!vis[child])
        {
            // cout << "vis["<<child<<"] = "<<vis[child]<< endl;
            dfs(child);
        }
    }
}

int main()
{
    b_v_r();
    int n, m;
    cin >> n; // Nodes
    cin >> m; // Sub-Group
    int k, num;
    while (m--)
    {
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> num;
            tem[i] = num;
        }
        for (int i = 1; i <= k; i++)
        {
            for (int j = i + 1; j <= k; j++)
            {
                ar[tem[i]].emplace_back(tem[j]);
                ar[tem[j]].emplace_back(tem[i]);
            }
        }
    }

    for (int j = 1; j <= n; j++)
    {
        dfs(j);
        // cout << "VISITED :" << endl;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            // cout << vis[i] << " ";
            if (vis[i] == 1)
            {
                cnt++;
                vis[i] = 0;
            }
        }
        cout << cnt << " ";
    }

    return 0;
}
