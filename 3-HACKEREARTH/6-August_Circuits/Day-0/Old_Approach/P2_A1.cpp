#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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
vector<ll> sum1;
vector<pair<ll, vector<ll>>> mp; // sum & set

const int vsz = 10;

int main()
{
    b_v_r();

    /// WORST BRUTE FORCE 
    // SEE CONSTRAINS FIRST!!!! 

    vector<ll> v(vsz);
    v[0] = 1;
    for (int i = 1; i < vsz; i++)
    {
        v[i] = v[i - 1] * 3;
    }

    ll total = 1 << vsz;

    // Consider all numbers from 0 to 2^n - 1
    for (ll i = 0; i < total; i++)
    {
        ll sum = 0;
        vector<ll> tmp;

        for (int j = 0; j < vsz; j++)
        {
            if (i & (1 << j))
            {
                sum += v[j];
                tmp.emplace_back(v[j]);
            }
        }

        // cout << sum << " ";
        if (sum != 0)
        {
            sum1.emplace_back(sum);
            mp.push_back(make_pair(sum, tmp));
        }
    }

    sort(sum1.begin(), sum1.end());
    sort(mp.begin(), mp.end());

    cout << "SUM1" << endl;
    for (auto ele : sum1)
    {
        cout << ele << endl;
    }

    ll sz = mp.size();

    cout << "MAP" << endl;
    // watch(sz);

    for (int i = 0; i < sz; i++)
    {
        vector<ll> t = mp[i].second;
        cout << mp[i].first << endl;
        for (auto x : t)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     ll n;
    //     cin >> n;
    //     vector<ll> t = mp[n - 1].second;
    //     cout << t.size() << endl;
    //     for (auto x : t)
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}
