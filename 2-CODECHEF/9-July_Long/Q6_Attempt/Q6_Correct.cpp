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
        ll n,x;
        cin >> n >> x; // n -> No of Countries Intial Cures -> x

        ll a[n];
        ll day = 0LL;

        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        
        sort(a,a+n);

        ll up_index = 0LL;

        if(binary_search(a,a+n,(x/2)))
        {
            up_index = upper_bound(a, a+n, (x/2)) - a;
        }
        else
        {
            up_index = upper_bound(a, a+n, (x/2)) - a;
        }
        
        // cout << up_index << endl;

        for(ll i=up_index;i<n;i++)
        {
            if(x<a[i])
            {
                while(x<a[i])
                {
                    x *= 2;
                    day++;
                }

                x = 2*a[i];
                a[i] = 0;
                day++;

            }
            else
            {
                x = 2*a[i];
                a[i] = 0;
                day++;
            }
        }

        cout << day + up_index << endl;


    }
    
        
    return 0;
}
