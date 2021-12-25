#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define endl 	"\n"
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> adj[1000001];

void modified_dfs(int node, int &count, int vis[], vector<int> &dfs)
{
    vis[node] = 1;
    count++;

    dfs.push_back(node);

    for (int k = 0; k < adj[node].size(); k++)
    {
        if (vis[adj[node][k]] == 0)
        {
            modified_dfs(adj[node][k], count, vis, dfs);
        }
    }
}

void solve(int n)
{
    int vis[1000001];
    memset(vis, 0, sizeof(vis));

    int ans[1000001];
    memset(ans, 0, sizeof(ans));

    vector<int> dfs;

    for (int i = 1; i < n + 1; i++)
    {
        dfs.clear();

        int count = 0;

        if (!vis[i])
        {
            modified_dfs(i, count, vis, dfs);
        }

        for (int k = 0; k < dfs.size(); k++)
        {
            ans[dfs[k]] = count;
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    b_v_r();
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        if (k == 1)
        {
            int num;
            cin >> num;
            adj[num].push_back(num);
        }
        else
        {
            int num, temp;
            cin >> temp;
            for (int j = 1; j < k; j++)
            {
                cin >> num;
                adj[num].push_back(temp);
                adj[temp].push_back(num);
                temp = num;
            }
        }
    }
    
    solve(n);

    return 0;
}