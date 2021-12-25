#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
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

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int main()
{
    b_v_r();

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ll n, k, i;
    
    cin >> n >> k;

    vector<ll> a(n);
    vector<ll> b(n);

    // ll a[n] = {0}, b[n] = {0};

    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    
    // shuffle(a.begin(), a.end(), rng);
    // shuffle(b.begin(), b.end(), rng);

    sort(b, b + n);

    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;

    for (i = 0; i < n; i++)
        cout << b[i] << " ";

    cout << endl;

    return 0;
}