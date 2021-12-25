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

    vector<bool> is_prime(1e6 + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= 1000000; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
                is_prime[j] = false;
        }
    }

    vector<int> prime;
    for (int i = 2; i <= 1e6; i++)
    {
        if (is_prime[i])
        {
            prime.emplace_back(i);
        }
    }

    ll n;
    w(t)
    {
        cin >> n;
        // cout << flcm[n] << endl;
        // cout << findlcm(n) << endl;
        // ll arrlcm = findlcm(n);
        if (n == 1)
        {
            cout << "0" << endl;
            continue;
        }

        if (n == 2)
        {
            cout << "1" << endl;
            continue;
        }

        ll final = 0;
        ll cnt1 = lower_bound(prime.begin(), prime.end(), n + 1) - prime.begin();
        final += (cnt1 - 1);
        final += (n - 2);
        cout << final << endl;
    }

    return 0;
}
