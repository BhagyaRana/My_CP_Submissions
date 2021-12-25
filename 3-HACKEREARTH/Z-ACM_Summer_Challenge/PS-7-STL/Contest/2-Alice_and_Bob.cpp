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
    int n;
    cin >> n;
    set<long long int> s;
    ll k;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        s.insert(k);
    }
    set<long long int> s2(s.begin(), s.end());

    int len = s2.size();
    vector<ll> bob;
    set<long long int>::iterator it2;
    for (it2 = s2.begin(); it2 != s2.end(); it2++)
    {
        bob.push_back(*it2);
    }

    set<long long int> temp(s.begin(), s.end());
    vector<ll> v1, v2, v3;
    set<long long int>::iterator it;
    for (it = temp.begin(); it != temp.end(); it++)
    {
        if ((*it) % 3 == 0)
        {
            v1.push_back(*it);
        }
        else
        {
            if ((*it) % 2 == 0)
            {
                v2.push_back(*it);
            }
            else
            {
                v3.push_back(*it);
            }
        }
    }
    vector<ll> alice;
    for (auto i : v1)
    {
        alice.push_back(i);
    }
    for (auto i : v2)
    {
        alice.push_back(i);
    }
    for (auto i : v3)
    {
        alice.push_back(i);
    }
    int awin = 0, bwin = 0, tie = 0;
    for (int i = 0; i < len; i++)
    {
        if (alice[i] > bob[i])
        {
            awin++;
        }
        else
        {
            if (alice[i] < bob[i])
            {
                bwin++;
            }
            else
            {
                tie++;
            }
        }
    }
    cout << awin << " " << bwin << " " << tie << endl;

    return 0;
}
