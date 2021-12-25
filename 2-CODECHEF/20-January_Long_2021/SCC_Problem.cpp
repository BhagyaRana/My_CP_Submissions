#include "bits/stdc++.h"
using namespace std;
#define mod 998244353
#define M2 998244353
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define inf 1e18
#define fl(i, a, b) for (ll i = a; i < b; i++)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define N 500005
#define all(c) c.begin(), c.end()
#define sz(s) (int)s.size()

//debugging template
#define p0(a) cout << a << " "
#define p1(a) cout << a << endl
#define p2(a, b) cout << a << " " << b << endl
#define p3(a, b, c) cout << a << " " << b << " " << c << endl
#define p4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl

ll power(ll a, ll b) //a is base, b is exponent
{
   if (b == 0)
      return 1;
   if (b == 1)
      return a;
   if (b % 2 == 1)
      return (power(a, b - 1) * a) % mod;
   ll q = power(a, b / 2);
   return (q * q) % mod;
}

void solve()
{
   ll m, n, k;
   cin >> m >> n >> k;
   if (m == 2)
   {
      ll x = power(k, 2 * n);
      x = power(x, mod - 2);
      if (k == 1)
      {
         cout << x << endl;
         return;
      }
      ll dp[n][2];
      memset(dp, 0, sizeof dp);
      dp[0][0] = k;
      dp[0][1] = (2 * k * (k - 1)) % mod;
      for (int i = 1; i < n; i++)
      {
         // dp[i][0] += dp[i - 1][0];
         dp[i][0] += ((k - 1) * (dp[i - 1][0] + (k * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][0] %= mod;
         dp[i][0] += dp[i - 1][0];
         dp[i][0] %= mod;
         dp[i][0] += (2LL * dp[i - 1][1]) % mod;
         dp[i][0] %= mod; // p1(dp[i][0]);
         dp[i][0] += ((k - 2) * (dp[i - 1][1] + (((k * (k - 1)) % mod) * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][0] %= mod; //p1(dp[i][0]);

         //  dp[i][1] += dp[i - 1][1];
         dp[i][1] += ((k - 1) * (dp[i - 1][0] + (k * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod;
         dp[i][1] += ((k - 1) * (dp[i - 1][0] + (k * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod; //p1(dp[i][1]);
         dp[i][1] += ((((k - 2) * (k - 1)) % mod) * (dp[i - 1][0] + (2 * k * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod;
         //  dp[i][1] += ((((k - 2) * (k - 1)) % mod) * (dp[i - 1][0] + (2 * k * power(k, 2 * (i - 1))) % mod) % mod) % mod; dp[i][1] %= mod;//p1(dp[1][1]);

         dp[i][1] += dp[i - 1][1];
         dp[i][1] %= mod; //p1(dp[1][1]);
         dp[i][1] += ((((k - 2)) % mod) * (dp[i - 1][1] + (((k * (k - 1)) % mod) * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod;
         dp[i][1] += ((((k - 2)) % mod) * (dp[i - 1][1] + (((k * (k - 1)) % mod) * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod;
         dp[i][1] += ((((k - 2)) % mod) * (dp[i - 1][1] + ((2 * (k * (k - 1)) % mod) * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod;
         dp[i][1] += ((((k - 1)) % mod) * (dp[i - 1][1] + ((2 * (k * (k - 1)) % mod) * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod; //p1(dp[1][1]);
                          //  dp[i][1] += ((((k - 2) * (k - 1)) % mod) * (dp[i - 1][1] + ((2 * (k * (k - 1)) % mod) * power(k, 2 * (i - 1))) % mod) % mod) % mod; dp[i][1] %= mod;
         dp[i][1] += ((((k - 2) * (max(k - 3, 0LL))) % mod) * (dp[i - 1][1] + ((2 * (k * (k - 1)) % mod) * power(k, 2 * (i - 1))) % mod) % mod) % mod;
         dp[i][1] %= mod;
      }
      ll ans = dp[n - 1][0] + dp[n - 1][1];
      ans %= mod;
      ans *= x;
      ans %= mod;
      p1(ans); //p1(dp[1][1]);
   }
   else
   {
      ll dp[n + 1];
      memset(dp, 0, sizeof dp);
      dp[1] = k;
      fl(i, 2, n + 1)
      {
         dp[i] += dp[i - 1];
         dp[i] %= mod;
         dp[i] += ((k - 1) * (dp[i - 1] + (power(k, i - 1)))) % mod;
         dp[i] %= mod;
      }
      ll x = power(k, n);
      x = power(x, mod - 2);
      cout << (dp[n] * x) % mod;
   }
}

int main()
{
   std::ios::sync_with_stdio(false);
   int T = 1;
   //  cin>>T;
   // cin.ignore(); must be there when using getline(cin, s)
   while (T--)
   {
      solve();
   }
   return 0;
}
