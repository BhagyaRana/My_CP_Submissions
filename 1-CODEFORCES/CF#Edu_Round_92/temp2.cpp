#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main()
{
    b_v_r();
    int n,i;
    ll x,temp;
    w(t)
    {
        cin >> n >> x;
        ll a[n] = {0};
        for(i=0;i<n;i++)
        {
            cin >> a[i];
        }
        
        sort(a,a+n);

        ll cnt = 0;
        ll num = 1;
        ll sum = 0;

        for(i=n-1;i>=0;i--)
        {
            sum += a[i];
            if((sum/(num*1.0)) >= x)
            {
                cnt++;
                num++;
            }
            else
            {
                break;
            } 
        }
        cout << cnt << endl;
    }

    return 0;
}
