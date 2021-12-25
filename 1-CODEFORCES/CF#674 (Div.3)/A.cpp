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
    int n,x;
    w(t)
    {
        cin >> n >> x;
        int floor = 1;
        if(n==1||n==2)
        {
            cout << 1 << endl;
        }
        else
        {
            n -= 2;
            if(n%x!=0)
                floor += (int)(n/x) + 1;
            else
            {
                floor += (int)(n/x);
            }
            
            cout << floor << endl;
        }
    }
  
    return 0;
}