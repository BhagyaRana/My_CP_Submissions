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
    int n, k;
    w(t)
    {
        // Input Taken n & k
        cin>>n>>k;

        vector<ll> f(n); // vector to store family 
        map<ll, ll>mp; // for frequency & argument
        vector <vector<ll>> dp(n, vector<ll>(n, 0)); // dp matrix
        ll argument = 0, old_res = 0;
        ll ans = INT_MAX;//2147483647

        for (int i = 0; i < n; i++)
        {
            cin>>f[i];
        }

        for (int i = 0; i < n; i++)
        {
            mp[f[i]]++;
            if (mp[f[i]] == 1)
            {
                // No Need to Do Anything
                ;
            }
            else if (mp[f[i]] == 2)
            {
                argument+=2;
            }
            else if (mp[f[i]]>2)
            {
                argument+=1;
            }

            dp[0][i] = k + argument;
            // K = Cost of Each Table + Arguments
        }

        for (int i = 1;i < n; i++)
        {
            mp.clear();
            old_res = INT_MAX;
            argument = 0;

            for (int j = 0; j < i; j++)
            {
                old_res = min(old_res, dp[j][i-1]);
            }

            for (int j = i; j < n; j++)
            {
                mp[f[j]]++;

                if (mp[f[j]] == 1)
                {
                    // No Need to Do Anything
                    ;
                }
                else if (mp[f[j]] == 2)
                {
                    argument +=2;
                }
                else if (mp[f[j]]>2)
                {
                    argument+=1;
                }

                dp[i][j] = k + argument + old_res;
                //  = Cost of Each Table + Arguments + old result
            }
        }

        cout << "DP MATRIX" << endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0;i<n;i++)
        {
            ans = min(ans, dp[i][n-1]);
        }

        cout << ans << endl;
    }
    return 0;
}