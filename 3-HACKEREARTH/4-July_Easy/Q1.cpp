#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
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
    ll n;
    w(t)
    {
        cin >> n;
        ll price[n];
        set <ll> final; 
        ll x;
        for(int i=0;i<n;i++)
        {
            cin >> x;
            final.insert(x);
        }
        ll amt = 0LL;
        for(auto it= final.begin();it!=final.end();it++)
        {
            amt += (*it);
        }
        cout << amt << endl;

    }
        
    return 0;
}
