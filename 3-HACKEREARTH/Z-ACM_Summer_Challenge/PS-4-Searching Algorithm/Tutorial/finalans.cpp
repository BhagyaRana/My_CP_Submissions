    #include <bits/stdc++.h>
     
    using namespace std;
     
    #define w(x)  \
        int x;    \
        cin >> x; \
        while (x--)
    #define endl "\n"
    #define rep(i, n) for (i = 0; i < n; ++i)
    typedef long long ll;
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
        w(t)
        {
            int n;
            cin >> n;
            mk(arr, n , int);
            int i=0;
            rep(i,n)
            {
                cin >> arr[i];
            }
            int count = 0;
            for(int i=1;i<n;i++)
            {
                sort(arr,arr + (i-1));

                int k = upper_bound(arr,arr+i,arr[i]) - arr;
                // cout << " k : "<<k <<" : i : "<< i << endl;
                count += (i-k);
            }
            // for(int i=0;i<n;i++)
            //     cout << arr[i] << " ";
            cout << count << endl;

        }
     
        return 0;
    }