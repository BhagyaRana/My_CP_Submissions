#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  int x;cin >> x;while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define f(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

// All Functions Here



// All Variables Here


int main()
{
    b_v_r();
    ll n;
    cin >> n;
    ll a[n];
    f(i,n)
    {
        cin >> a[i];
    }
    int ans = 0;
    map<ll,int> prefix;
    prefix[0] = 1;
    ll sum = 0LL;

    f(i,n)
    {
        sum += a[i];
        if(prefix.find(sum)!=prefix.end())
        {
            ans++;
            prefix.clear();
            prefix[0] = 1;
            // Left Prefix is Cut
            sum = a[i];
        }
        prefix[sum] = 1;
    }

    cout << ans << endl;

    return 0;
}