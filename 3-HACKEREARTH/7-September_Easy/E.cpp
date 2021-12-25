#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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
    ll n, i, j, k, mv;
    w(t)
    {
        cin >> n;
        ll a[n], b[n];
        map<ll, int> mpa;
        map<ll, int> mpb;
        bool avis[n] = {false}, bvis[n] = {false};

        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            mpa.insert({a[i], i});
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
            mpb.insert({b[i], i});
        }

        // cout << "MAP-A" << endl;
        // for (auto x : mpa)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        // cout << "MAP-B" << endl;
        // for (auto x : mpb)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }

        ll alice = 0, bob = 0;
        for (mv = 0; mv < (n / 2); mv++)
        {

            for (auto el : mpa)
            {
                if (!avis[el.second])
                {
                    for (auto el2 : mpb)
                    {
                        if (!bvis[el2.second])
                        {
                            if (el.second != el2.second)
                            {
                                i = el.second;
                                j = el2.second;
                                if (b[i] > b[j])
                                {
                                    bob += b[i];
                                    alice += a[j];
                                }
                                else
                                {
                                    bob += b[j];
                                    alice += a[i];
                                }
                                avis[j] = true;
                                avis[i] = true;
                                bvis[i] = true;
                                bvis[j] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        cout << alice - bob << endl;
        
    }

    return 0;
}