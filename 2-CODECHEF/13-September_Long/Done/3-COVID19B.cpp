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

int main()
{
    b_v_r();
    w(t)
    {
        int n;
        cin >> n;
        int spd[n] = {0}, ans[n] = {0};

        for (int i = 0; i < n; i++)
        {
            cin >> spd[i];
        }

        for (int inf = 0; inf < n; inf++)
        {
            vector<int> left, right, extra;
            set<int> index;
            index.insert(inf);
            int l1 = 0, r1 = 0;
            for (int lf = inf - 1; lf >= 0; lf--)
            {
                if (spd[lf] > spd[inf])
                {
                    left.push_back(spd[lf]);
                    index.insert(lf);
                    l1++;
                }
            }
            for (int rt = inf + 1; rt < n; rt++)
            {
                if (spd[rt] < spd[inf])
                {
                    right.push_back(spd[rt]);
                    index.insert(rt);
                    r1++;
                }
            }

            for (auto l : left)
            {
                for (int rt = inf + 1; rt < n; rt++)
                {
                    if (l > spd[rt])
                    {
                        extra.push_back(spd[rt]);
                        index.insert(rt);
                    }
                }
            }

            for (auto r : right)
            {
                for (int lt = inf - 1; lt >= 0; lt--)
                {
                    if (r < spd[lt])
                    {
                        extra.push_back(spd[lt]);
                        index.insert(lt);
                    }
                }
            }

            ans[inf] = index.size();
            // watch(ans[inf]);
        }
        int minn = 6, maxn = 0;

        for (int i = 0; i < n; i++)
        {
            minn = min(minn, ans[i]);
            maxn = max(maxn, ans[i]);
        }
        cout << minn << " " << maxn << endl;
    }

    return 0;
}