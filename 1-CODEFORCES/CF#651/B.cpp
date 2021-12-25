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
bool prime[10000];
void SieveOfEratosthenes()
{

    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= 10000; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= 10000; i += p)
                prime[i] = false;
        }
    }
}

int main()
{
    b_v_r();
    SieveOfEratosthenes();
    w(t)
    {
        int n;
        cin >> n;
        mk(arr, (2 * n), int);
        for (int i = 0; i < (2 * n); i++)
        {
            cin >> arr[i];
        }
        // Compress into n-1 Array
        int count = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] != -1)
                    {
                        if (!prime[arr[i] + arr[j]])
                        {
                            if (count >= 0)
                            {
                                cout << i << " " << j << endl;
                                arr[i] = -1;
                                arr[j] = -1;
                                count--;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
