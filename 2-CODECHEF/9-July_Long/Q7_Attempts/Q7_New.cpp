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

stack<ll> Empty_Karo(stack<ll> in)
{
    stack<ll> temp;
    in.swap(temp);
    return in;
}

int main()
{
    b_v_r();

    ll n, q;
    cin >> n >> q;

    ll h[n], s[n], rSum[n], lSum[n], left[n], right[n];

    for (ll i = 0; i < n; i++)
        cin >> h[i];
    for (ll j = 0; j < n; j++)
        cin >> s[j];

    stack<ll> se1, se2;

    for (ll i = n - 1; i >= 0; i--)
    {
        rSum[i] = s[i];

        while (!se1.empty() && h[se1.top()] <= h[i])
            se1.pop();

        if (!se1.empty())
            rSum[i] += rSum[se1.top()];

        se1.push(i);
    }

    // cout << "Right Sum :" << endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << rSum[i] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        lSum[i] = s[i];

        while (!se2.empty() && h[se2.top()] <= h[i])
            se2.pop();

        if (!se2.empty())
            lSum[i] += lSum[se2.top()];

        se2.push(i);
    }

    // cout << "Left Sum :" << endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << lSum[i] << " ";
    // }
    // cout << endl;

    se1 = Empty_Karo(se1);
    se2 = Empty_Karo(se2);

    for (ll i = n - 1; i >= 0; i--)
    {
        while (!se1.empty() && h[se1.top()] < h[i])
            se1.pop();

        right[i] = (se1.empty()) ? n : se1.top();

        se1.push(i);
    }

    // cout << "Right :" << endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << right[i] << " ";
    // }
    // cout << endl;

    for (ll i = 0LL; i < n; i++)
    {
        while (!se2.empty() && h[se2.top()] < h[i])
            se2.pop();

        left[i] = (se2.empty()) ? -1 : se2.top();

        se2.push(i);
    }

    // cout << "Left :" << endl;
    // for (ll i = 0; i < n; i++)
    // {
    //     cout << left[i] << " ";
    // }
    // cout << endl;

    while (q--)
    {
        ll t, a, b;

        cin >> t >> a >> b;

        if (t == 1)
        {
            s[a - 1] = b;
            se1 = Empty_Karo(se1);
            se2 = Empty_Karo(se2);
            for (ll i = n - 1; i >= 0; i--)
            {
                rSum[i] = s[i];

                while (!se1.empty() && h[se1.top()] <= h[i])
                    se1.pop();

                if (!se1.empty())
                    rSum[i] += rSum[se1.top()];

                se1.push(i);
            }
            for (int i = 0; i < n; i++)
            {
                lSum[i] = s[i];

                while (!se2.empty() && h[se2.top()] <= h[i])
                    se2.pop();

                if (!se2.empty())
                    lSum[i] += lSum[se2.top()];

                se2.push(i);
            }
        }
        else
        {
            a--;
            b--;

            if (a == b)
            {
                cout << s[a] << "\n";
                continue;
            }

            if (abs(b - a) == 1)
            {
                cout << s[a] + s[b] << "\n";
                continue;
            }

            bool flag = true;

            if (a > b)
            {
                // Need to Go Back
                if (h[b] >= h[a])
                {
                    //Need to Go Up
                    // Point b to Point c
                    ll high = h[b];

                    for (ll i = a - 1; i > b; i--)
                    {
                        if (h[i] > h[b])
                        {
                            cout << "-1" << endl;
                            flag = false;
                            break;
                        }
                    }
                }
                else
                {
                    // Need to go Down
                    for (ll i = a - 1; i > b; i--)
                    {
                        if (h[i] > h[a])
                        {
                            cout << "-1" << endl;
                            flag = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                // Need to Go Forward
                if (h[b] >= h[a])
                {
                    //Need to Go Up
                    for (ll i = a + 1; i < b; i++)
                    {
                        if (h[i] > h[b])
                        {
                            cout << "-1" << endl;
                            flag = false;
                            break;
                        }
                    }
                }
                else
                {
                    // Need to go Down
                    for (ll i = a + 1; i < b; i++)
                    {
                        if (h[i] > h[a])
                        {
                            cout << "-1" << endl;
                            flag = false;
                            break;
                        }
                    }
                }
            }

            if (flag)
            {
                if (a < b)
                {
                    // cout << "lsum[" << b << "] = " << lSum[b] << endl;
                    // cout << "lsum[" << a << "] = " << lSum[a] << endl;
                    // cout << "s[" << a << "] = " << s[a] << endl;

                    cout << lSum[b] - lSum[a] + s[a] << endl;
                }
                else
                {
                    // cout << "rsum[" << b << "] = " << rSum[b] << endl;
                    // cout << "rsum[" << a << "] = " << rSum[a] << endl;
                    // cout << "s[" << a << "] = " << s[a] << endl;

                    cout << rSum[b] - rSum[a] + s[a] << endl;
                }
            }
        }
    }
    return 0;
}
