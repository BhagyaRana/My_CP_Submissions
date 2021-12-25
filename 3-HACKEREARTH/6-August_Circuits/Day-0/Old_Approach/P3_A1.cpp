#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
typedef unsigned long long int ull;

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

int main()
{
    b_v_r();

    ull k;
    cin >> k;

    bitset<64> b(k);
    // cout << b << endl;

    vector<pair<int, int>> ans;

    int some = 0;
    int onecnt = b.count() - 1;

    for (int i = 63; i >= 0; i--)
    {
        if (b[i] == 1)
        {
            some = i;
            break;
        }
    }

    // cout << 1 << " " << 2 << endl;
    ans.emplace_back(make_pair(1, 2));

    // Diamond
    int cnt = 1;
    int old = 0;
    int final = 0;
    vector<int> v;
    v.push_back(0);
    int i;
    for (i = 2; cnt <= some; i += 3)
    {
        v.emplace_back(i);
        // cout << i << " " << i + 1 << endl;
        ans.emplace_back(make_pair(i, i + 1));
        // cout << i << " " << i + 2 << endl;
        ans.emplace_back(make_pair(i, i + 2));

        if (cnt != some)
        {
            // cout << i + 1 << " " << i + 3 << endl;
            ans.emplace_back(make_pair(i + 1, i + 3));
            // cout << i + 2 << " " << i + 3 << endl;
            ans.emplace_back(make_pair(i + 2, i + 3));
        }
        else
        {
            old = i + 3;
            // cout << i + 1 << " " << old + onecnt << endl;
            ans.emplace_back(make_pair(i + 1, old + onecnt));
            // cout << i + 2 << " " << old + onecnt << endl;
            ans.emplace_back(make_pair(i + 2, old + onecnt));
            final = old + onecnt;
        }
        cnt++;
    }

    reverse(v.begin(), v.end());

    int sz = v.size();
    for (int i = 0; i < some; i++)
    {
        if (b[i] == 1)
        {
            if (i == 0)
            {
                // cout << 1 << " " << old << endl;
                ans.emplace_back(make_pair(1, old));
                // cout << old << " " << final << endl;
                ans.emplace_back(make_pair(old, final));
            }
            else
            {
                // cout << 1 << " " << old << endl;
                ans.emplace_back(make_pair(1, old));
                // cout << old << " " << v[i-1] << endl;
                ans.emplace_back(make_pair(old, v[i - 1]));
            }
        }
    }

    int anssz = ans.size();
    int node = 0;
    for (auto x : ans)
    {
        if(x.second > node)
            node = x.second;  
    }

    cout << node << " " << anssz << endl;
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
