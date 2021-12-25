// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//CONSTANTS
const int mod = 1000000007;

#define endl "\n"

// COMMONLY USED TYPES
typedef long long ll;

vector<int> a(1000010);
// All Functions Here
void fib()
{
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < 1000010; i++)
        a[i] = (a[i - 1] + a[i - 2]) % mod;
}

void solve()
{
    ll n, m;
    cin >> n >> m;

    int i = 0, j = n - 1;
    ll count = m;
    while (count)
    {
        cout << a[i] << " ";
        i++;
        count--;
        if (count == 0)
            break;
        cout << a[j] << " ";
        j--;
        count--;
    }
    cout << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fib();
    int tc = 1;
    cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}