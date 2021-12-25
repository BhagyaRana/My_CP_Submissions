#pragma GCC optimize("O2") 

#include <bits/stdc++.h>
using namespace std;

#define w(x)    int x; cin>>x; while(x--)
#define endl 	"\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long int ll;


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
        ll n;

        cin >> n;

        vector<ll> xcorp;
        vector<ll> xcorn;

        vector<ll> ycorp;
        vector<ll> ycorn;

        ll x,y;
        for(ll i=0;i<((4*n)-1);i++)
        {
            cin >> x >> y;
            if(x>=0)
                xcorp.push_back(x);
            else
            {
                xcorn.push_back(x);
            }
            if(y>=0)
                ycorp.push_back(y);
            else
            {
                ycorn.push_back(y);
            }
        }
        

    } 
    return 0;
}
