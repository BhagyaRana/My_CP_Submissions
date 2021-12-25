// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;
typedef long long ll;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)
// reverse 0 based.
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)
// reverse 1 based
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)

//SHORT HAND
#define pb push_back

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"

#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

void b_v_r()
{
#ifndef MY_ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// All Functions Here

// All Variables Here

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // DONT FORGET TO COMMENT THIS -> IT CAUSES SIGABORT IN CODECHEF
    // b_v_r();
    // int cnt = 1;
    w(t)
    {
        // cout << "Test Case : " << cnt << endl;
        // cnt++;
        // Size of Array of Candies
        ll n;
        cin >> n;

        ll a[n + 1] = {0};
        ll b[n + 1] = {0};

        ll val;
        bool fo1 = false;
        int pos1 = -1;
        ll prefix[n + 1] = {0};
        prefix[0] = 0;

        // 1 Based indexing
        for1(i, n)
        {
            cin >> a[i];

            if (a[i] & 1)
            {
                if (a[i] == 1)
                {
                    val = 1;
                    fo1 = true;
                    pos1 = i;
                }
                else
                {
                    // odd hai
                    if (i != n)
                    {
                        // chose even
                        val = a[i] - 1;
                    }
                    else
                    {
                        // to do exchange
                        val = a[i];
                    }
                }
            }
            else
            {
                if (i != n)
                {
                    val = a[i];
                }
                else
                {
                    val = a[i] - 1;
                }
            }

            // If Element is odd
            if (a[i] & 1)
            {
                if (a[i] != 1)
                {
                    // take even only
                    b[i] = a[i] - 1;
                }
                else
                {
                    // Case of 1

                    if (pos1 == 1)
                    {
                        b[i] = 1;
                    }
                    else
                    {
                        // if a[i-1] is odd
                        if (a[i - 1] & 1)
                        {
                            // Chef will take odd
                            b[i - 1] = a[i - 1];
                            // Chefu will take 1
                            b[i] = 0;
                        }
                        else
                        {
                            // Chef will make even -> odd
                            b[i - 1] = a[i - 1] - 1;
                            // Chefu will take 1
                            b[i] = 0;
                        }
                    }
                }
            }
            else
            {
                // a[i] is even
                if (i != n)
                    b[i] = a[i];
                else
                {
                    b[i] = a[i] - 1;
                }
            }

            prefix[i] = ((prefix[i - 1]) % mod + (val) % mod) % mod;
        }

        // cout << "B[I] = \n";
        // for1(i,n)
        // {
        //     cout << b[i] << " ";
        // }

        ll my[n + 1] = {0};
        for1(i, n)
        {
            my[i] = ((my[i - 1]) % mod + (b[i]) % mod) % mod;
        }

        // cout << "\nMY[I] = \n";
        // for1(i,n)
        // {
        //     cout << my[i] << " ";
        // }

        //Total Number Of Queries
        ll query;
        cin >> query;

        // Number of Turns
        ll r;

        while (query--)
        {
            cin >> r;
            // cout << "\nr : " << r << endl;

            if ((fo1 == false && pos1 == -1) || (fo1 = true && pos1 == n))
            {
                // Only Chef will Take Everthing
                // watch(fo1);
                // watch(pos1);
                // cout << "here\n" << endl;
                ll time = r / n;
                ll rem = r % n;
                ll ans = 0;
                ans = (ans % mod + (1ll * time * prefix[n]) % mod) % mod;
                ans = (ans % mod + (prefix[rem]) % mod) % mod;
                cout << ans << endl;
            }
            else
            {
                // 1 is there in array between [1 to n-1]
                // cout << "here-cond1\n" << endl;
                if (pos1 == 1)
                {
                    cout << r % mod << endl;
                }
                else
                {
                    ll time = r / n;
                    ll rem = r % n;
                    ll ans = 0;
                    ans = (ans % mod + (1ll * time * my[n]) % mod) % mod;
                    ans = (ans % mod + (my[rem]) % mod) % mod;
                    cout << ans << endl;
                }
            }
        }
    }

    return 0;
}
