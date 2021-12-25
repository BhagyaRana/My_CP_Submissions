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

// int a[101];

int bubble_sort(int A[], int n)
{
    int temp, cnt = 0;
    for (int k = 0; k < n - 1; k++)
    {

        for (int i = 0; i < n - k - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                // here swapping of positions is being done.
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    b_v_r();
    w(t)
    {
        int n, k;
        cin >> n >> k;
        mk(a, n, int);
        int i = 0;
        rep(i, n)
        {
            cin >> a[i];
        }
        int ans = bubble_sort(a, n);
        if (ans > k)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}