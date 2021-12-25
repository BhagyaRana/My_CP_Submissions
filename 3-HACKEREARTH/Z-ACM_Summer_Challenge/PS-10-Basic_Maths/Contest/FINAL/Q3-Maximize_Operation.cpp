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
     
    int primeFactors(int n)
    {
        int count = 0;
        while (n % 2 == 0)
        {
            // cout << 2 << " ";
            count++;
            n = n / 2;
        }
        for (int i = 3; i <= sqrt(n); i = i + 2)
        {
            while (n % i == 0)
            {
                // cout << i << " ";
                count++;
                n = n / i;
            }
        }
        if (n > 2)
        {
            // cout << n << " ";
            count++;
        }
        return count;
    }
     
    int main()
    {
        b_v_r();
     
        w(t)
        {
            int n;
            cin >> n;
            int ans = primeFactors(n);
            cout << ans << endl;
        }
     
        return 0;
    }