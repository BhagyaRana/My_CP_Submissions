#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define w(x)    ll x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
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
    ll n,m;
    w(t)
    {
        ll max = -1;
        ll min = 100002;

        cin >> n >> m;

        ll a[n][m];
        ll vis[n][m];

        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];

                if(a[i][j]>max)
                {
                    max = a[i][j];
                }
                if(a[i][j]<min)
                {
                    min = a[i][j];
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==max||a[i][j]==min)
                {
                    for(int row = 0;row<n;row++)
                    {
                        vis[row][j] = 1;
                    }
                    for(int col = 0;col<m;col++)
                    {
                        vis[i][col] = 1;
                    }
                }

            }
        }

        ll cnt = 0LL;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)
                {
                    cnt++;
                }
            }
        }

        cout << cnt << endl;


    }

        
    return 0;
}
