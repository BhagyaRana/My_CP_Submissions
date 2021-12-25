#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define w(x)  int x;cin >> x;while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
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
    int n,u,v,i;
    w(t)
    {
        cin >> n;
        ll in_degree[n+1]={0};
        int cnt = n-1;
        while(cnt--)
        {
            cin >> u >> v;
            in_degree[v]++;
        }
        ll zero = 0LL;
        for(i=1;i<=n;i++)
        {
            if(in_degree[i]==0)
            {
                zero++;
            }
        }
        cout << zero - 1 << endl;
    }
  
    return 0;
}