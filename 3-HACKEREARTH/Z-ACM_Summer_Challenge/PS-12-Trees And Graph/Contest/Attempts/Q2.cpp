#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define endl 	"\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void lexi(int arr[], int n) 
{ 
    // Calculate frequency of array elements 
    int cnt[n + 1]; 
    memset(cnt, 0, sizeof(cnt)); 

    for (int i = 0; i < n; ++i) 
        ++cnt[arr[i]]; 
  
    int ele = 1, replacement = 0; 
    bool vis[n + 1]; 
    
    memset(vis, 0, sizeof(vis)); 
    for (int i = 0; i < n; ++i) 
    { 
        if (cnt[arr[i]] == 1) 
            continue; 

        while (cnt[ele]) 
            ++ele; 
  
        if (ele > arr[i] && !vis[arr[i]]) 
            vis[arr[i]] = 1; 
  
        else { 

            --cnt[arr[i]]; 
            arr[i] = ele; 

            // ++replacement; 

            ++ele; 
        } 
    } 
    // cout << replacement << "\n"; 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
} 


vector<int> ar[100001];
// int mxn = 100000;
int vis[100001];
int arr[100001];
vector<int> per;


void dfs(int node)
{
    vis[node] = 1;
    // cout << node << " -> ";
    per.push_back(node);
    for(int child:ar[node])
    {
        if(!vis[child])
            dfs(child);
    }
}

int main()
{
    b_v_r();
    int n,m;
    cin >> n >> m;
    
    int a,b;
    for(int i=1;i<=m;i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    dfs(1);
    int sz = per.size();
    
    for(int i=0;i<sz;i++)
    {
        arr[i] = per[i];
    }
    lexi(arr,sz);

    return 0;
}
