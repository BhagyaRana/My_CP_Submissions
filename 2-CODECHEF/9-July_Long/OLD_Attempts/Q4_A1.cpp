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
        ll n;
        cin >> n;

        ll xcor[n],ycor[n];
        map<ll,int> mpx;
        map<ll,int> mpy;
        ll xcord = 0LL;
        ll ycord = 0LL;


        for(ll i=0;i<(4*n)-1;i++)
        {
            cin >> xcor[i] >> ycor[i];
            mpx[xcor[i]]++;
            mpy[ycor[i]]++;
        }

        for(auto x : mpx)
        {
            if(x.second==1)
            {
                xcord = x.first;
            }
        }

        for(auto y : mpy)
        {
            if(y.second==1)
            {
                ycord = y.first;
            }
        }

        cout << xcord << " " << ycord << endl;

    } 
    return 0;
}