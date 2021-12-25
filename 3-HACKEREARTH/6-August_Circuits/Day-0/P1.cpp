#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

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

    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        
        vector<int> v;
        int r;

        while(n)
        {
            r = n%2;
            v.push_back(r);
            n/=2;
        }

        // for(auto ele : v)
        // {
        //     cout << ele;
        // }
        // cout << endl;
        ll sz = v.size();
        ll cnt = 0;
        for(int i=0;i<sz;i++)
        {
            if(v[i] == 1)
            {
                cnt++;
            }
        }

        cout << cnt << endl;

        ll power = 1;
        for(int i=0;i<sz;i++)
        {
            if(v[i] == 1)
            {
                cout << v[i]*power << " ";
            }
            power *= 3;
        }

        cout << endl;

    } 
    
    return 0;
}