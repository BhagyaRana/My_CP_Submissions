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

    w(t)
    {
        int n,k;

        cin >> n >> k;
        // sum not more than k
        int w[n+1] = {0};
        
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            cin >> w[i];

            if(w[i]>k)
            {
                flag = false;
            }

        }
        if(!flag)
        {
            cout << "-1" << endl;
            continue;
        }

        if(n==1)
        {
            if(w[1]<=k)
            {
                cout << "1" << endl;
                continue;
            }
            else
            {
                cout << "-1" << endl;
                continue;
            }
        }

        int round = 1,sum = 0;
        for(int i=1;i<=n;i++)
        {
            if(sum + w[i] <= k)
            {
                sum += w[i];
            }
            else
            {
                i--;
                sum = 0;
                round++;
            }
        }
        cout << round << endl;
    }
  
    return 0;
}