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
    int n;
    cin >> n;

    string s;
    cin >> s;

    int hashcnt = 0, open = 0;

    bool f = 1;
    int openfirst, openlast, openvalue;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
        {
            hashcnt++;
        }
        else
        {
            if (s[i] == '(')
            {
                if (f)
                {
                    openfirst = i + 1;
                    f = 0;
                }
                open++;
            }
        }
    }

    int x, y;
    // vector<pair<int, int>> hash;
    for (int i = 0; i < hashcnt; i++)
    {
        cin >> x >> y;
        // hash.emplace_back(make_pair(x - 1, y);
    }

    vector<pair<pair<int, int>, int>> brac;

    bool flag = true;

    int start, end, gamma;

    for (int i = 0; i < open; i++)
    {
        cin >> start >> end >> gamma;
        brac.push_back(make_pair(make_pair(start, end), gamma));
        if (start == openfirst)
        {
            openlast = end;
            openvalue = gamma;
        }
    }

    // brac { start, end }->val

    for (auto ele : brac)
    {
        pair<int, int> pr = ele.first;
        if (pr.first > openfirst && pr.second < openlast)
        {
            if (ele.second > openvalue)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    // for (auto ele : brac)
    // {
    //     auto pr = ele.first;
    //     openfirst = pr.first;
    //     openlast = pr.second;
    //     openvalue = ele.second;

    //     for (auto ok : brac)
    //     {
    //         auto okr = ok.first;
    //         if (okr.first > openfirst && okr.second < openlast)
    //         {
    //             if (ok.second >= openvalue)
    //             {
    //                 cout << "No" << endl;
    //                 return 0;
    //             }
    //         }
    //     }
    // }

    if (flag)
        cout << "Yes" << endl;

    return 0;
}