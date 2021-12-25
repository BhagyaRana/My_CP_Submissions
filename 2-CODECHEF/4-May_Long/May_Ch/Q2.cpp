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
    w(t)
    {
        int n;
        cin >> n;
        mk(a,n,int);
        mk(b,n,int);
        mk(prea,n + 1,int);
        mk(preb,n + 1,int);
        prea[0] = 0;
        preb[0] = 0; 
        int i = 0;
        ll wsum = 0;
        rep(i,n)
        {
            cin >> a[i];
            prea[i+1] = prea[i] + a[i];
        }
        int j = 0;
        rep(j,n)
        {
            cin >> b[j];
            preb[j+1] = preb[j] + b[j];
        }
        for(int k=0;k<n;k++)
        {
            if(prea[k]==preb[k])
            {
                if(a[k]==b[k])
                    {
                        wsum += a[k];
                    }
            }
        }
        cout << wsum << endl;

    }
        
    return 0;
}
