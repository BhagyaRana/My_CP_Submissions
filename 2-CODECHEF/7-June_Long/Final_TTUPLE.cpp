#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    ll x;     \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
typedef long long ll;
#define rep(i, a, n) for (ll i = a; i < (long long)n; ++i)

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

// Global Result
ll result = 3; // Max result can be 3 Only Upper Bound

void check(ll a[], ll p[], ll ans, ll length)
{
    // cout << a[0] << " " << p[0] << endl;
    if (length == 1)
    {
        if (a[0] != p[0])
            ans += 1;
        result = min(result, ans);
        // cout << result << endl;
        return;
    }

    if (a[0] == p[0])
    {
        // cout << a[0] << "==" << p[0] << std::endl;
        ll gar1[length], gar2[length];

        rep(i, 0, length)
        {
            gar1[i] = a[i];
            gar2[i] = p[i];
        }

        if (length > 1)
            check(gar1 + 1, gar2 + 1, ans, length - 1);

        return;
    }

    if ((a[0] != 0) && ((a[0] + p[0]) % a[0]) == 0)
    {
        ll gar1[length], gar2[length];

        rep(i, 0, length)
        {
            gar1[i] = a[i];
            gar2[i] = p[i];
        }

        ll dv = p[0] / a[0];

        gar1[0] = a[0] * dv;

        if (length == 3)
        {
            gar1[0] = a[0] * dv;
            gar1[1] = a[1];
            gar1[2] = a[2];
            check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

            gar1[0] = a[0] * dv;
            gar1[1] = a[1] * dv;
            gar1[2] = a[2];
            check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

            gar1[0] = a[0] * dv;
            gar1[1] = a[1];
            gar1[2] = a[2] * dv;
            check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

            gar1[1] = a[1] * dv;
            gar1[2] = a[2] * dv;
            gar1[0] = a[0] * dv;
            check(gar1 + 1, gar2 + 1, ans + 1, length - 1);
        }

        if (length == 2)
        {
            gar1[0] = a[0] * dv;
            gar1[1] = a[1];
            check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

            gar1[0] = a[0] * dv;
            gar1[1] = a[1] * dv;
            check(gar1 + 1, gar2 + 1, ans + 1, length - 1);
        }
    }

    ll gar1[length], gar2[length];

    rep(i, 0, length)
    {
        gar1[i] = a[i];
        gar2[i] = p[i];
    }

    ll difference = p[0] - a[0]; // cout << difference << endl;

    gar1[0] = a[0] + difference;

    if (length == 3)
    {
        gar1[0] = a[0] + difference;
        gar1[1] = a[1];
        gar1[2] = a[2];
        check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

        gar1[1] = a[1] + difference;
        gar1[0] = a[0] + difference;
        gar1[2] = a[2];
        check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

        gar1[0] = a[0] + difference;
        gar1[1] = a[1];
        gar1[2] = a[2] + difference;
        check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

        gar1[0] = a[0] + difference;
        gar1[1] = a[1] + difference;
        gar1[2] = a[2] + difference;
        check(gar1 + 1, gar2 + 1, ans + 1, length - 1);
    }

    if (length == 2)
    {
        gar1[0] = a[0] + difference;
        gar1[1] = a[1];
        check(gar1 + 1, gar2 + 1, ans + 1, length - 1);

        gar1[1] = a[1] + difference;
        gar1[0] = a[0] + difference;
        check(gar1 + 1, gar2 + 1, ans + 1, length - 1);
    }

    return;
}

int main()
{
    b_v_r();
    w(test)
    {
        result = 3;

        ll a, b, c, p, q, r;

        cin >> a >> b >> c;
        cin >> p >> q >> r;

        ll area;
        ll slope = 0;
        ll distn1 = abs(a - p);
        ll distn2 = abs(b - q);
        ll distn3 = abs(r - p);

        if ((b - a) != 0 && (q - p) % (b - a) == 0)
            slope = 1;

        if ((c - a) != 0 && (r - p) % (c - a) == 0)
            slope = 1;

        if ((b - c) != 0 && (q - r) % (b - c) == 0)
            slope = 1;

        ll f = 0;
        ll ma = 1;
        ll del = 0;

        if (p == q || q == r || r == p)
            ma = 0;

        area = a * (q - r) + b * (r - p) + c * (p - q); //Cyclicity

        if (area == 0 && slope == 1)
        {
            result = 2;
        }

        if (a != b && p - ((q - p) / (b - a)) * a + c == r && (q - p) % (b - a) == 0)
            del = 1;

        if (c != b && r - ((q - r) / (b - c)) * c + a == p && (q - r) % (b - c) == 0)
            del = 1;

        if (a != c && p - ((r - p) / (c - a)) * a + b == q && (r - p) % (c - a) == 0)
            del = 1;

        if (del == 1)
            result = 2;

        ll x[3], y[3];

        // All the Six Permutations of Pairs (a,p);(b,q);(c,r);

        // Fix Pair (a,p);
        x[0] = a;
        y[0] = p;
        x[1] = c;
        y[1] = r;
        x[2] = b;
        y[2] = q;
        // cout << "check123\n";
        check(x, y, 0, 3);

        x[0] = a;
        y[0] = p;
        x[1] = b;
        y[1] = q;
        x[2] = c;
        y[2] = r;
        // cout << "check123\n";
        check(x, y, 0, 3);

        // Fix Pair (b,q);
        x[0] = b;
        y[0] = q;
        x[1] = a;
        y[1] = p;
        x[2] = c;
        y[2] = r;
        // cout << "check123\n";
        check(x, y, 0, 3);

        x[0] = b;
        y[0] = q;
        x[1] = c;
        y[1] = r;
        x[2] = a;
        y[2] = p;
        // cout << "check123\n";
        check(x, y, 0, 3);

        // Fix Pair (c,r);
        x[0] = c;
        y[0] = r;
        x[1] = b;
        y[1] = q;
        x[2] = a;
        y[2] = p;
        // cout << "check123\n";

        check(x, y, 0, 3);
        x[0] = c;
        y[0] = r;
        x[1] = a;
        y[1] = p;
        x[2] = b;
        y[2] = q;
        // cout << "check123\n";
        check(x, y, 0, 3);

        cout << result << endl;
    }
    return 0;
}