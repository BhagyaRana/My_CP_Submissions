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

int n, m;
vector<int> ar[100002];
int arr1[100002];
int arr2[100002];
vector<int> ans;

void modified_bfs()
{
    queue<pair<int, int>> q; // Queue to Store Parent 
    q.push({1, -1});

    vector<int> parent(n + 1); // To Remember Parent 
    vector<int> diff(n + 1, 0); // For Alternate Sons of Sons
    vector<int> vis(n + 1, 0);
    parent[1] = -1;

    while (!q.empty())
    {
        int u = q.front().first;
        int v = q.front().second;
        // cout << u << " " << v << endl;
        q.pop();

        vis[u] = 1; // mark as visited

        if (v != -1 && parent[v] != -1)
        {
            v = parent[v];
            if (diff[v] % 2) //Son of Sons
            {
                if (arr1[u] != arr2[u])
                    arr1[u] = arr2[u];
                else
                {
                    ans.push_back(u);
                    diff[u]++;
                }
            }
            else
            {
                if (arr1[u] == arr2[u])
                    arr1[u] = arr2[u];
                else
                {
                    ans.push_back(u);
                    diff[u]++;
                }
            }
            diff[u] += diff[v];
        }
        else if(arr1[u]!=arr2[u])
        {
            diff[u]++;
            arr1[u] = arr2[u];
            ans.push_back(u);
        }

        for(auto x : ar[u])
        {
            if(!vis[x])
            {
                parent[x] = u;
                q.push({x,u});
            }
        }
    }
}

int main()
{
    b_v_r();
    cin >> n;
    m = n - 1;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr2[i];
    }
    modified_bfs();

    // Final Answer
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for (int ele : ans)
    {
        cout << ele << endl;
    }

    return 0;
}
