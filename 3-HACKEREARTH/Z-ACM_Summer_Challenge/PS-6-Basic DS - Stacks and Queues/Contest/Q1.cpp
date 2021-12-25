#include <bits/stdc++.h>

using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)
typedef long long ll;
#define mk(arr,n,type)   type *arr=new type[n]
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

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
    int n,x;
    cin >> n;
    queue <int> q;
    mk(arr, n, int);
    mk(vis, n + 1, int);

    for(int i = 0;i<n;i++ )
    {
        cin >> x;
        q.push(x);
    }
    
    int cnt = 0; 

    for(int i = 0;i<n;i++ )
    {
        cin >> arr[i];
    } 

    memset(vis,0,sizeof(vis));

    int ind = 0;
    while(q.size()>0)
    {
        if(q.front()==arr[ind])
        {
            q.pop();
            vis[arr[ind]] = 1;
            ind++;
        }
        else
        {
            if(vis[q.front()]==1)
            {
                q.pop();
            }
            else
            {
                cnt++;
                vis[arr[ind]] = 1;
                ind++;
            }
            
        }
        
    }



    // while(ans.size()>1&&q.size()>0)
    // {
    //     if(q.front()==ans.front())
    //     {
    //         ans.pop();
    //         q.pop();
    //     }
    //     else
    //     {
    //         cnt++;
    //         ans.pop();
    //     }
    // }
    cout << cnt << endl;  
    return 0;
}
