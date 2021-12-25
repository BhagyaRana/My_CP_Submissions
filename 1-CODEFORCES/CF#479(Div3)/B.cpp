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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

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

    int n, i, j;

    cin >> n;

    string s, t1;

    cin >> s;
    // cout << s << endl;

    map<string, int> mp;

    for (i=0;i<n-1;i++)
    {
        j = i+1;
        t1 += (char)s[i];
        t1 += (char)s[j];

        // cout << t1 << endl;
        auto it = mp.find(t1);
        if (it==mp.end())
        {
            //Not Found
            mp.insert({ t1, 1 });
        }
        else
        {
            mp[t1]++;
        }
        t1.clear();
    }

    int mx = -1;
    for (auto i : mp)
    {
        // cout << i.first << " " << i.second << endl;
        if ((i).second > mx)
            mx = (i).second;
    }

    for (auto i : mp)
    {
        if ((i).second == mx)
        {
            cout << (i).first << endl;
            break;
        }
    }

    return 0;
}
