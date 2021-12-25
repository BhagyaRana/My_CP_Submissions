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
    // cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    b_v_r();

    int n, k, i, j;

    w(t)
    {
        cin >> n >> k;

        int f[n+1];

        int freq[101] ={ 0 };

        int tbcnt = 1, argu = 0, extra = 0;

        int ans1 = 0, ans2 = 0;

        for (i=1;i<=n;i++)
        {
            cin >> f[i];
            freq[f[i]]++;
        }

        set<int> s;
        map<int, int> mp;
        int oldtb = tbcnt;

        for (j=1;j<=n;j++)
        {
            if (s.find(f[j]) == s.end())
            {
                s.insert(f[j]);
                mp.insert(make_pair(f[j], 1));
            }
            else
            {
                // need to modify this part
                mp[f[j]]++;
                if (mp[f[j]] >= k)
                {
                    oldtb = tbcnt;
                    tbcnt++;
                    s.clear();
                    mp.clear();
                    s.insert(f[j]);
                    extra += argu;
                    argu = 0;
                }
                else
                {
                    argu = mp[f[j]];
                    // watch(argu);
                    if (oldtb != tbcnt)
                    {
                        extra += argu;
                    }
                    continue;
                }
            }
        }

        // watch(extra);
        // watch(tbcnt);
        extra += argu;
        ans2 = (k*tbcnt) + extra;

        for (i=1;i<=100;i++)
        {
            if (freq[i] >=2)
            {
                ans1 += freq[i];
            }
        }

        ans1 += k; // cost of 1 table

        // cout << ans1 << " " << ans2 << endl;
        // cout << min(ans1, ans2) << endl;

    }


    return 0;
}
