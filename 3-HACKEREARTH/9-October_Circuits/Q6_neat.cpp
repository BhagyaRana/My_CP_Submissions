// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//CONSTANTS
const int mod = 1000000007;

#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll ans = 0;

    // For First Column 3/2 ie 3*mod_inv(2)
    ans += 500000005;
    ans = ans%mod;
    // for rest (n-1) columns probability is 10/16 ie 5/8
    // 5 * mod_inv(8) = 625000005
    ans = (ans + (((n-1)%mod)*(625000005)%mod)%mod)%mod;

    cout << ans << endl;
    
    return 0;
}
