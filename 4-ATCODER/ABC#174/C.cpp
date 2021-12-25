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

    ll k;
    cin >> k;

    if (k % 2 == 0 || k % 5 == 0)
    {
        // If k is even or multiple of 5
        cout << "-1" << endl;
        return 0;
    }
    else
    {
        ll num = 7;
        ll cnt = 1;

        while (true)
        {
            if (num % k == 0)
            {
                // if k divided 7,77,777,7777,...
                cout << cnt << endl;
                break;
            }

            if (cnt > k)
            {
                // The Answer cant be Greater than the Number
                cout << "-1" << endl;
                break;
            }
            // The Most Important Step
            // To make Sure that num does not exceed its limit

            num = ((num % k) * 10) + 7;
            // cout << num << endl;
            cnt++;
        }
    }

    return 0;
}

// BRUTE FORCE SOLUTION

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {

//     int k;
//     cin >> k;
//     int n = 0;
//     // for even value of k check
//     if (k % 2 == 0)
//     {
//         cout << "-1";
//         return 0;
//     }
//     for (int i = 0; i < pow(10, 6); i++)
//     {
//         n = (n * 10 + 7) % k;
//         if (n == 0)
//         {
//             cout << i + 1;
//             break;
//         }
//     }
//     if (n != 0)
//         cout << "-1";
//     return 0;
// }