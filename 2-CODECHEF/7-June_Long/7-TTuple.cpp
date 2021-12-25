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

int solve(int p, int q, int r, int a, int b, int c)
{
    if (p == a && q == b && r == c) //if all three are equal
        return 0;
    if (p == a && q == b || p == q && r == c || q == b && r == c) // if any two are equal
        return 1;

    if (p == 0 || q == 0 || r == 0)
    {
        int d1 = a - p, d2 = b - q, d3 = c - r;
        if (d1 == d2 && d2 == d3)
            return 1;

        if (d1 == d2 || d2 == d3 || d1 == d3)
            return 2;

        else
            return 3;
        if (p == 0)
        {
            return (min(min(solve(a, q, r, a, b, c), solve(a, q + a, r, a, b, c)), min(solve(a, q, r + a, a, b, c), solve(a, q + a, r + a, a, b, c))));
        }
        else if (q == 0)
        {
            return (min(min(solve(p, b, r, a, b, c), solve(p + b, b, r, a, b, c)), min(solve(p, b, r + b, a, b, c), solve(p + b, b, r + b, a, b, c))));
        }
        else if (r == 0)
            return (min(min(solve(p, q, c, a, b, c), solve(p, q + c, c, a, b, c)), min(solve(p + c, q, c, a, b, c), solve(p + c, q + c, c, a, b, c))));
    }

    if (p == a)
    {
        int d2 = b - q, d3 = c - r;
        int q2 = b / q, q3 = c / r;
        int r2 = b % q, r3 = c % r;

        if (d2 == d3 || (q2 == q3 && r2 == 0 && r3 == 0))
            return 1;
        else
            return 2;
    }
    else if (q == b)
    {
        int d1 = a - p, d3 = c - r;
        int q1 = a / p, q3 = c / r;
        int r1 = a % p, r3 = c % r;

        if (d1 == d3 || (q1 == q3 && r1 == 0 && r3 == 0))
            return 1;
        else
            return 2;
    }
    else if (r == c) //if any one is equal
    {
        int d2 = b - q, d1 = a - p;
        int q2 = b / q, q1 = a / p;
        int r2 = b % q, r1 = a % p;

        if (d1 == d2 || (q2 == q1 && r2 == 0 && r1 == 0))
            return 1;
        else
            return 2;
    }

    else //if none are equal
    {
        int d1 = a - p, d2 = b - q, d3 = c - r;
        int q1 = a / p, q2 = b / q, q3 = c / r;
        int r1 = a % p, r2 = b % q, r3 = c % r;

        if ((d1 == d2 && d2 == d3) || (q1 == q2 && q2 == q3) && (r1 == 0 && r2 == 0 && r3 == 0))
            return 1;

        if ((q1 == q2 && q2 == q3) && r1 == r2 && r2 == r3)
            return 2;

        if (d1 == d2 || d2 == d3 || d1 == d3)
            return 2;

        else
        {
            // int mind=min(d1,min(d2,d3));
            //int minq=min(q1,min(q2,q3));
            //int x1=solve()
            if (b - a == d2 - d1 && c - b == d3 - d2)
                return 2;
            else
                return 3;

        }
    }
}

int main()
{
    b_v_r();
    w(t)
    {
        int p, q, r;
        cin >> p >> q >> r;
        int a, b, c;
        cin >> a >> b >> c;
        int res = solve(p, q, r, a, b, c);
        cout << res << endl;
    }
}