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

    w(t)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                v.push_back(i);
        }
        //Case 0
        int cnt = 0;
        if (v.size() == 0)
        {
            int cnt = 0;

            for (int i = 0; i < n; i += (k + 1))
            {
                s[i] = '1';
                cnt++;
            }
            cout << cnt << endl;
        }
        else
        {
            //Case 1
            if (v.size() == 1)
            {
                int cnt = 0;

                int index = v[0];
                //Left Side
                for (int i = index - (k + 1); i >= 0; i -= (k + 1))
                {
                    s[i] = '1';
                    cnt++;
                }
                //Right Side
                for (int i = index + (k + 1); i < n; i += (k + 1))
                {
                    s[i] = '1';
                    cnt++;
                }
                cout << cnt << endl;
            }
            else
            {
                int cnt = 0;
                int findex = v[0];
                //Left Side
                for (int i = findex - (k + 1); i >= 0; i -= (k + 1))
                {
                    s[i] = '1';
                    cnt++;
                }

                //Check Between 1's
                for (int i = 0; i < v.size() - 1; i++)
                {
                    int diff = v[i + 1] - v[i] - 1;

                    if (diff > ((2 * k)))
                    {
                        int x = (diff-k)/(k+1);
                        cnt += x;
                    }
                }
                int lindex = v[v.size() - 1];

                //Right Side
                for (int i = lindex + (k + 1); i < n; i += (k + 1))
                {
                    s[i] = '1';
                    cnt++;
                }
                cout << cnt << endl;
            }
        }
        // cout << "String : "<<s << endl;
        // cout << cnt << endl;
    }

    return 0;
}
