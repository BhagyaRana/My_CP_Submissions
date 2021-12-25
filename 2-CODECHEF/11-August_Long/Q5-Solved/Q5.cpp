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

    int n, k, i, j;

    w(t)
    {
        cin >> n >> k;

        int f[n+1];
        int freq[101] ={ 0 };

        int tbcnt = 1, argu = 0;

        int ans1 = 0, ans2 = 0;

        for (i=1;i<=n;i++)
        {
            cin >> f[i];
            freq[f[i]]++;
        }

        for (i=1;i<=100;i++)
        {
            if (freq[i] >=2)
            {
                ans1 += freq[i];
            }
        }

        ans1 += k; // cost of 1 table

        set<int> s;
        unordered_map<int, int> mp;
        int arg = 0, glarg = 0;
        vector<int> v;

        for (j=1;j<=n;j++)
        {

            if (s.find(f[j]) == s.end())
            {
                s.insert(f[j]);
            }
            else
            {
                //repeat huwa hai
                if (k==1)
                {
                    bool include = false;

                    if (j>= n-k +1 && j <= n-1)
                    {
                        include = true;
                    }

                    if (include && (k>1))
                    {
                        if (mp.find(f[j]) == mp.end())
                        {
                            mp.insert(make_pair(f[j], 2));
                        }
                        else
                        {
                            mp[f[j]]++;
                        }
                    }
                    else
                    {
                        tbcnt++;
                        s.clear();
                        s.insert(f[j]);
                    }

                }
                else
                {

                    if (v.empty())
                        v.emplace_back(f[j]);

                    if (f[j] == v[0] && v.size()>=1)
                    {
                        v.emplace_back(f[j]);
                    }
                    else
                    {
                        // cout  << "vector : ";
                        // for (auto ele : v)
                        // {
                        //     cout << ele << " ";
                        // }
                        // cout << endl;
                        if (v.size()>1)
                        {
                            arg += v.size();
                            // watch(arg);
                        }

                        tbcnt++;
                        v.clear();
                        v.emplace_back(f[j]);
                        s.clear();
                        s.insert(f[j]);
                    }

                }



            }
        }


        for (auto ele : mp)
        {
            arg += ele.second;
        }

        // watch(arg);
        // watch(tbcnt);

        ans2 = k*tbcnt + arg;

        // cout << ans1 << " " << ans2 << endl;
        cout << min(ans1, ans2) << endl;

    }


    return 0;
}
