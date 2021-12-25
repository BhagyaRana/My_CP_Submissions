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

bool check(string a, string b)
{
    int subsz = a.length();
    int bsz = b.length();
    string tmp;
    for (int i = 0; i + subsz <= bsz; i++)
    {
        tmp = b.substr(i, subsz);
        if (tmp == a)
        {
            return true;
        }
    }
    return false;
}

bool cmp(string a, string b)
{
    int alen = a.size();
    int blen = b.size();
    return (alen < blen);
}

int main()
{
    b_v_r();

    int n;
    cin >> n;
    vector<string> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);
    // for (auto el : v)
    // {
    //     cout << el << endl;
    // }

    bool ok = true;
    int sz = v.size();
    for (int i = 0; i < sz - 1; i++)
    {
        if (v[i + 1].find(v[i]) == string::npos)
        {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES" << endl;
    for (auto ele : v)
    {
        cout << ele << endl;
    }

    return 0;
}
