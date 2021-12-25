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

int main()
{
    b_v_r();

    ll n;
    cin >> n;
    mk(arr, n, ll);

    int count_nz = 0;
    int min = 1000000001;
    ll psum = 0LL; //Positive Sum

    // Trick Here : Since We have Unlimited Spells
    // We can count the Number of (-ve + 0) in count_nz
    // if count_nz is Even -> We can make all Number Positives (Pairs)
    // if count_nz is Odd -> One Negative Number is Sure -> So Subtract (Twice of Smallest Number(Absolute Value))..Now Think Why??

    // Below is Implementation

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= 0)
            count_nz++;

        if (abs(arr[i]) < min)
            min = abs(arr[i]);

        psum += abs(arr[i]);
    }
    // cout << min << endl;
    if (count_nz % 2 != 0)
    {
        cout << psum - (2 * min) << endl;
    }
    else
    {
        cout << psum << endl;
    }

    return 0;
}
