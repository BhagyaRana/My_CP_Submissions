// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
typedef long long ll;
const ll mod = 1000000007;

//LOOPS
// 0 based indexing
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)
// 1 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

//SHORT HAND
#define pb push_back
#define mp make_pair

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
    b_v_r();
    w(t)
    {
        ll n;
        cin >> n;

        ll a[n + 1] = {0};
        bool found1 = false;
        int pos1 = -1;

        for1(i, n)
        {
            cin >> a[i];
            if (a[i] == 1)
            {
                found1 = true;
                pos1 = i;
            }
        }

        // CASE #1 : "1" Not Present
        if (found1 == false && pos1 == -1)
        {
            // Pre-Process
            ll b[n + 1] = {0};
            for1(i, n)
            {
                if (i != n)
                {
                    if (a[i] & 1)
                    {
                        // Even Taken
                        b[i] = a[i] - 1;
                    }
                    else
                    {
                        b[i] = a[i];
                    }
                }
                else
                {
                    // Always Odd to be Selected in Last
                    if (a[i] & 1)
                    {
                        b[i] = a[i];
                    }
                    else
                    {
                        b[i] = a[i] - 1;
                    }
                }
            }
            ll pre[n + 1] = {0};
            for1(i, n)
            {
                pre[i] = ((pre[i - 1]) % mod + (b[i]) % mod) % mod;
            }
            ll query;
            cin >> query;

            // Maximum Number of Candies Chef can Get after r Turns
            ll r;
            while (query--)
            {
                cin >> r;
                ll time = r / n;
                ll rem = r % n;
                ll ans = 0;

                if (rem == 0)
                {
                    if (time >= 1)
                    {
                        ans = ((ans) % mod + ((time - 1) * pre[n]) % mod) % mod;
                    }
                    ans = ((ans) % mod + ((pre[n - 1]) % mod)) % mod;
                    ans = ((ans) % mod + ((a[n]) % mod)) % mod;
                    cout << ans << endl;
                }
                else
                {
                    ans = ((ans) % mod + (time * pre[n]) % mod) % mod;
                    if (rem >= 1)
                    {
                        ans = ((ans) % mod + (pre[rem - 1]) % mod) % mod;
                        ans = ((ans) % mod + (a[rem]) % mod) % mod;
                    }
                    cout << ans << endl;
                }
            }
        }
        // CASE #2 : "1" Found But at Last Position
        else if (found1 == true && pos1 == n)
        {
            // Pre-Process
            ll b[n + 1] = {0};
            for1(i, n)
            {
                if (i != n)
                {
                    if (a[i] & 1)
                    {
                        // Even Taken
                        b[i] = a[i] - 1;
                    }
                    else
                    {
                        b[i] = a[i];
                    }
                }
                else
                {
                    b[i] = a[i];
                }
            }
            ll pre[n + 1] = {0};
            for1(i, n)
            {
                pre[i] = ((pre[i - 1]) % mod + (b[i]) % mod) % mod;
            }
            ll query;
            cin >> query;

            // Maximum Number of Candies Chef can Get after r Turns
            ll r;
            while (query--)
            {
                cin >> r;
                ll time = r / n;
                ll rem = r % n;
                ll ans = 0;

                if (rem == 0)
                {
                    // if (time >= 1)
                    // {
                    //     ans = ((ans) % mod + ((time - 1) * pre[n]) % mod) % mod;
                    // }
                    ans = ((ans) % mod + ((time)*pre[n]) % mod) % mod;
                    // ans = ((ans) % mod + ((pre[n - 1]) % mod)) % mod;
                    // ans = ((ans) % mod + ((a[n]) % mod)) % mod;
                    cout << ans << endl;
                }
                else if (rem >= 1)
                {
                    ans = ((ans) % mod + (time * pre[n]) % mod) % mod;
                    ans = ((ans) % mod + (pre[rem - 1]) % mod) % mod;
                    ans = ((ans) % mod + (a[rem]) % mod) % mod;
                    cout << ans << endl;
                }
            }
        }
        // CASE #3 : "1" Found But at First Position
        else if (found1 == true && pos1 == 1)
        {
            ll query;
            cin >> query;

            // Maximum Number of Candies Chef can Get after r Turns
            ll r;
            while (query--)
            {
                cin >> r;
                ll time = r / n;
                ll rem = r % n;
                ll ans = 0;
                ans = ((ans) % mod + (time) % mod) % mod;
                if(time==0&&rem==1)
                {
                    ans = (ans + 1) % mod;
                }
                if (rem >= 2)
                {
                    ans = (ans + 1) % mod;
                }
                
                cout << ans << endl;
            }
        }
        // CASE #4 : "1" Found But at [2,n-1] Position
        else
        {
            // Pre-Process
            ll b[n + 1] = {0};

            for1(i, n)
            {
                if (i == pos1)
                {
                    b[i] = 0;
                    if (a[i - 1] & 1)
                    {
                        b[i - 1] = a[i - 1];
                    }
                    else
                    {
                        b[i - 1] = a[i - 1] - 1;
                    }
                }
                else
                {
                    if (i == n)
                    {
                        if (a[i] & 1)
                        {
                            b[i] = a[i];
                        }
                        else
                        {
                            b[i] = a[i] - 1;
                        }
                    }
                    else
                    {
                        if (a[i] & 1)
                        {
                            b[i] = a[i] - 1;
                        }
                        else
                        {
                            b[i] = a[i];
                        }
                    }
                }
            }
            ll pre[n + 1] = {0};
            for1(i, n)
            {
                pre[i] = ((pre[i - 1]) % mod + (b[i]) % mod) % mod;
            }
            ll query;
            cin >> query;

            // Maximum Number of Candies Chef can Get after r Turns
            ll r;
            while (query--)
            {
                cin >> r;

                ll time = (r / n);
                ll rem = r % n;
                ll ans = 0;

                // ans = ((ans) % mod + (time * pre[n]) % mod) % mod;
                if (rem == 0)
                {
                    if (time >= 1)
                    {
                        ans = ((ans) % mod + ((time - 1) * pre[n]) % mod) % mod;
                    }
                    ans = ((ans) % mod + ((pre[n - 1]) % mod)) % mod;
                    ans = ((ans) % mod + ((a[n]) % mod)) % mod;
                    cout << ans << endl;
                }
                else if (rem == pos1)
                {
                    ans = ((ans) % mod + (time * pre[n]) % mod) % mod;
                    ans = ((ans) % mod + (pre[rem - 2]) % mod) % mod;
                    if (a[rem - 1] % 2 == 0)
                    {
                        ans = ((ans) % mod + (a[rem - 1] + a[rem]) % mod) % mod;
                    }
                    else
                    {
                        ans = ((ans) % mod + (a[rem - 1] - 1 + a[rem]) % mod) % mod;
                    }
                    cout << ans << endl;
                }
                else if (rem < pos1 && rem >= 1)
                {
                    ans = ((ans) % mod + (time * pre[n]) % mod) % mod;
                    ans = ((ans) % mod + ((pre[rem - 1]) % mod)) % mod;
                    ans = ((ans) % mod + (a[rem]) % mod) % mod;
                    cout << ans << endl;
                }
                else
                {
                    // rem > pos1
                    ans = ((ans) % mod + (time * pre[n]) % mod) % mod;
                    if (rem >= 1)
                    {
                        ans = ((ans) % mod + (pre[rem - 1]) % mod) % mod;
                        ans = ((ans) % mod + (a[rem]) % mod) % mod;
                    }
                    cout << ans << endl;
                }
            }
        }
    }

    return 0;
}
