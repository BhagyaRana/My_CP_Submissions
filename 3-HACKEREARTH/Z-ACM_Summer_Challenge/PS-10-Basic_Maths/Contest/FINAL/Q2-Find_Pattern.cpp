#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
typedef unsigned long long ull;
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

ll power(ll a,ll b)
{
    ll result = 1;
    while(b)
    {
        if(b%2) result = ((result%mod)*(a%mod))%mod;
        a = (a%mod*a%mod)%mod;
        b /= 2;
    }
    return result;
}


int main()
{
    b_v_r();
    w(t)
    {
        int n;
        cin >>n;
        if(n<10)
        {
            cout << "-1" << endl;
        }
        else
        {
            ll base = n/10;
            ll last = n%10;
            ull ans = ((power(base,10-last)%mod)*(power(base+1,last)%mod)%mod);
            cout << ans << endl; 
        }
        
    }
        
    return 0;
}
