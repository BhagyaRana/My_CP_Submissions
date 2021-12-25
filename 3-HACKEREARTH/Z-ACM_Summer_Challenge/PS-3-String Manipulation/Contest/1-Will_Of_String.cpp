#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
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
    w(t)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        //Manacher Algorithm
        ll count = 0;
        int i, j, k,     // iterators
            rp,          // length of 'palindrome radius'
            R[2][n + 1]; // table for storing results (2 rows for odd- and even-length palindromes

        // print s first

        // cout << s << endl;

        // ...then search for palindromes

        s = "@" + s + "#"; // insert 'guards' to iterate easily over s

        for (j = 0; j <= 1; j++)
        {
            R[j][0] = rp = 0;
            i = 1;
            while (i <= n)
            {
                while (s[i - rp - 1] == s[i + j + rp])
                    rp++;
                R[j][i] = rp;
                k = 1;
                while ((R[j][i - k] != rp - k) && (k < rp))
                {
                    R[j][i + k] = min(R[j][i - k], rp - k);
                    k++;
                }
                rp = max(rp - k, 0);
                i += k;
            }
        }

        s = s.substr(1, n); // remove 'guards'

        // print the results

        for (i = 1; i <= n; i++)
        {
            for (j = 0; j <= 1; j++)
                for (rp = R[j][i]; rp > 0; rp--)
                {
                    count++;
                    // for (k = 1; k < i - rp; k++)
                    //     cout << " ";
                    // cout << s.substr(i - rp - 1, 2 * rp + j) << endl;
                }
        }
        ll ans = count + n;
        cout << ans << endl;
        // string ans;

        // cout << Count(s) << endl;
    }

    return 0;
}