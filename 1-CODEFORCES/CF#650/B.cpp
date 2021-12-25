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
        int n;
        cin >> n;
        mk(arr, n, int);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int deven = 0;
        for (int j = 0; j < n; j += 2)
        {
            if (arr[j] % 2 != 0)
                deven++;
        }

        int dodd = 0;
        for (int j = 1; j < n; j += 2)
        {
            if (arr[j] % 2 == 0)
                dodd++;
        }

        // Case 0
        int flag = 0;
        int sum = deven + dodd; 
        if (sum == 0)
        {
            cout << "0" << endl;
            flag = 1;
        }
        // cout << "Deven : "<< deven<<endl ;
        // cout << "Dodd : "<< dodd <<endl;

        if(flag!=1&&(deven==dodd))
        {
            cout << dodd << endl;
        }
        else
        {
            if(flag!=1)
                cout << "-1" << endl;
        }
        


    }

    return 0;
}
