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
const int mod = 998244353;
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

ll inverse_modulo(ll a, ll m)
{
    ll m0 = m;
    ll y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        ll q = a / m;
        ll t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

ll wt[26];

ll strwgt(string str)
{
    ll len = str.length();
    ll weight = 0LL;
    for (ll i = 0; i < len; i++)
    {
        weight += wt[str[i] - 'a'];
    }
    return weight;
}

ll strpow(string str)
{
    ll len = str.length();

    if (len == 1 || len == 2)
        return strwgt(str);

    // pow(str) = r + r + r + ... + r + p
    if (len % 2 == 0)
    {
        // string of even length
    }
    else
    {
        // string of odd length
    }
}

void result(string s, int n)
{
    // set to store the strings
    unordered_set<string> st;

    for (int i = 0; i < (int)s.size(); i++)
    {

        string ans = "";
        for (int j = i; j < (int)s.size(); j++)
        {

            ans += s[j];

            // if the size of the string
            // is equal to 1 then insert
            if (ans.size() == n)
            {

                // inserting unique
                // sub-string of length L
                st.insert(ans);
                break;
            }
        }
    }

    // Printing the set of strings
    for (auto it : st)
        cout << it << " ";
}

int main()
{
    b_v_r();
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < 26; i++)
        {
            cin >> wt[i];
        }

        ll wgt = strwgt(s);
        cout << wgt << endl;

        // ll p = 1;
        // ll q = 4;
        // ll q_inv = inverse_modulo(q, mod);
        // ll ans = ((p % mod) * (q_inv % mod)) % mod;
        // cout << ans << endl;
    }

    return 0;
}
