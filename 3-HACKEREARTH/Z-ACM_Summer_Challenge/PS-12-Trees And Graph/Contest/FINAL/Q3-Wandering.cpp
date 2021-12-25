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

int main()
{
    b_v_r();

    int n,m;
    cin>>n>>m;

    vector<int> adj[n+1];

    priority_queue <int, vector<int>, greater<int>> pq; //Lexi - Smaller

    int visited[n+1]={0};

    int a,b;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pq.push(1);
    visited[1]=1;

    while(!pq.empty())
    {
        int smallest=pq.top();
        cout<<smallest<<" ";
        pq.pop();
        for(int i=0;i<adj[smallest].size();i++)
        {
            int index=adj[smallest][i];
            if(visited[index]!=1)
            {
                visited[index]=1;
                pq.push(index);
            }
        }
    }

    return 0;
}