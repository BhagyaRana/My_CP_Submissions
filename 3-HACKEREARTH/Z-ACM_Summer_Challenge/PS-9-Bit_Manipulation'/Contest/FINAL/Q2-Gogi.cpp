#pragma GCC optimize("O2")

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
    w(q)
    {
        int n;
        cin >> n;

        vector<pair<bitset<26>, int>> v;

        string s;
        bitset<26> bit[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s;
            for (int j = 0; j < s.length(); j++)
            {
                bit[i].set(s[j] - 'a');
            }

            v.push_back(make_pair(bit[i], s.length()));
        }

        int max = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                bitset<26> ans = ((v[i].first) & (v[j].first));
                // cout << "i : "<< i << "j : " << j << endl;
                // cout << ans << endl;
                if (ans.count() == 0)
                {
                    int prod = (v[i].second) * (v[j].second);
                    if (prod > max)
                        max = prod;
                }
            }
        }
        cout << max << endl;
    }

    return 0;
}