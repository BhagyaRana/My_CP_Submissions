    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define w(x)  \
        int x;    \
        cin >> x; \
        while (x--)
    #define endl '\n'
    // #define mod 1000000007
    typedef long long int ll;
    #define mk(arr, n, type) type *arr = new type[n]
     
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
        ll k;
        cin >> n >> k;
        mk(arr, n, int);
        ll mod = (ll) (1000000007);
        if (k == 1)
        {
            int m = 1000000007;
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            int sub = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        sub++;
                    }
                }
            }
            cout << sub % m << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
            int sub = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] > arr[j])
                    {
                        sub++;
                    }
                }
            }
     
            int ulta = 0;
            for(int i=n-1;i>=0;i--)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(arr[i]>arr[j])
                        ulta++;
                }
            }
            ll ans1 = 1;
            ll mi = (mod+1)/2; 
            ans1 = (ans1*(sub)) % mod;
            ans1 = (ans1*(k)) % mod;
            ans1 = (ans1*((k+1))) % mod;
            ans1 = (ans1*(mi)) % mod;
     
            ll ans2 = 1;
            ans2 = (ans2*(ulta)) % mod;
            ans2 = (ans2*(k)) % mod;
            ans2 = (ans2*((k-1))) % mod;
            ans2 = (ans2*(mi)) % mod;
     
            cout << (ans1 + ans2)%mod << endl;
        }
     
        return 0;
    }