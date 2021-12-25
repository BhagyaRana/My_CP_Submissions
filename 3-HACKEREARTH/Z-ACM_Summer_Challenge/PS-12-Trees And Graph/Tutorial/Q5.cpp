#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

vector<int> ar[2001];
int vis[2001],col[2001];

bool dfs(int node,int c)
{
    vis[node] = 1;
    col[node] = c;
    for(int child : ar[node])
    {
        if(vis[child]==0)
        {
            int res = dfs(child,1^c);
            if(res==false)
                return false;
        }
        else
        {
            if(col[node]==col[child])
                return false;
        }
    }
    return true;
}



int main()
{
    b_v_r();
    int t,n,m,a,b;
    cin >> t;
    for(int test=1;test<=t;test++)
    { 
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            ar[i].clear();
            vis[i] = 0;
        }

        for(int i=1;i<=m;i++)
        {
            cin >> a >> b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }

        bool flag = true;

        for(int i=1;i<n;i++)
        {
            if(vis[i]==0)
            {
                bool res = dfs(i,0);
                if(res==false)
                    flag = false;
            }
        }

        cout << "Scenario #"<<test<<":"<<endl;
        if(flag==false)
        {
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "No suspicious bugs found!" << endl;
        }

    }
    
    return 0;    
}
