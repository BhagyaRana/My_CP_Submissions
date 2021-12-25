// OPTIMIZATIONS
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// COMMONLY USED TYPES
typedef long long ll;

// All Variables Here
ll fac[10];

// All Functions Here

void init_fact()
{
    fac[0] = 1;
    for (int i = 1; i < 10; i++)
    {
        fac[i] = i * fac[i - 1];
    }
}

void solve()
{
    ll n;
    cin >> n;
    string str;
    cin >> str;

    set<char> myset;
    for (int i = 0; i < str.length(); i++)
    {
        myset.insert(str[i]);
    }

    string s; // Unique Letter String

    for (auto ch : myset)
    {
        s += ch;
    }

    sort(s.begin(), s.end());

    cout << fac[s.size()] << endl; // N Factorial

    // Print all Permutations
    do
    {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));

    cout << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    init_fact();

    int tc = 1;
    cin >> tc;
    // If No Test Case, Then Comment it!
    while (tc--)
    {
        solve();
    }

    return 0;
}