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
#define M 32

int main()
{
    // b_v_r();
    int n;
    w(t)
    {

        cin >> n; // Number of Elements

        // Ask Question
        // 1 k
        ll finxor = 0;
        ll ans = 0;
        ll k = 1;
        ll tmp;

        for (int i = 0; i < 20; i++)
        {
            fflush(stdout);
            cout << 1 << " " << k << endl;
            fflush(stdout);
            cin >> ans;
            if (ans == -1)
            {
                continue;
            }

            bitset<32> b(ans);

            finxor += (k * b[i]);

            k *= 2;
        }

        fflush(stdout);
        cout << 2 << " " << finxor << endl;
        fflush(stdout);

        cin >> ans;
        if (ans == 1)
            continue;

        if (ans == -1)
            break;
    }

    return 0;
}