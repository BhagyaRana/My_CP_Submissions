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
    ll x,y;
    w(t)
    {
        cin >> x >> y;
        if( (x>=y) && (x>=0) && (y>=0) )
        {
            // Answer Exist
            if( (x==y) || (y==0))
            {
                cout << x << endl;
            }
            else
            {
                ll i = x;
                ll j = y;
                ll diag = 0LL;
                ll left = 0LL;
                while(j--)
                {
                    i--;
                    diag++;
                }
                left = i;
                cout << left + diag << endl;
            }

        }
        else
        {
            cout << "-1" << endl;
        }
        
    }
    

        
    return 0;
}
