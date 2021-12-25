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
    w(t)
    {
        ll n,b1,b2;
        cin >> n >> b1 >> b2;
        ll side2 = 0;
        ll line1 = 0;
        if(abs(b1-b2)==1)
        {
            side2 = 4;
            line1 = 3;
        }
        else
        {
            line1 = 4;
            if(abs(b1-b2)==2)
            {
                side2 = 5;
            }
            else
            {
                side2 = 6;
            }
        }
        ll ans2side = n - side2;
        ll ans1side = (n - line1)*(n-4);

    }
        
    return 0;
}
