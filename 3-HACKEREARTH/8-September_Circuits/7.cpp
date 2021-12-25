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
ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}
ll inverse(ll a, ll p)
{
    return power(a, p - 2);
}

void precompute()
{
    int n = 1000000;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> prime;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;

            prime.push_back(i);
        }
    }
    int cnt = 0;
    for (auto x : prime)
    {
        cout << "prime[" << cnt << "] = " << x << ";" << endl;
        cnt++;
    }
}

int fx(int m, int n)
{
    // m ^ (1/n)

    float p = ((log10(m)) / n);
    float q = ceil(pow(10, p));
    float u = floor(pow(10, p));
    int r = pow(q, n);
    int s = pow(u, n);

    if (r == m || s == m)
    {
        return 1;
    }
    else
        return 0;
}

// All Variables Here

int main()
{
    b_v_r();
    precompute();
    int i, j;

    int n; //Number of Elements
    int k; // kth root is integer
    int q; // Number of Queries

    cin >> n >> k >> q;

    ll a[n + 1] = {0};

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int qtype;
    ll low, rig, x, y;

    while (q--)
    {
        cin >> qtype;

        if (qtype == 1)
        {
            // is special or not.
            cin >> low >> rig;
            ll prod = 1;
            for (i = low; i <= rig; i++)
            {
                prod *= a[i];
            }
            if (fx(prod, k))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            if (qtype == 2)
            {
                // Multiply all the elements of the subarray -> X^Y
                cin >> low >> rig >> x >> y;
                ll xpowy = power(x, y);
                for (i = low; i <= rig; i++)
                {
                    a[i] *= xpowy;
                }
            }
            else
            {
                if (qtype == 3)
                {
                    //Reset all the elements of subarray -> X.
                    cin >> low >> rig >> x;
                    for (i = low; i <= rig; i++)
                    {
                        a[i] = x;
                    }
                }
            }
        }
    }

    return 0;
}