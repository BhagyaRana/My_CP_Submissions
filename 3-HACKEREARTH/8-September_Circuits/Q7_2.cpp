#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

// All Functions Here
#define MAX 1000001

bool v[MAX];
int sp[MAX];

void Sieve()
{
    ll i, j;
    sp[0] = 1;
    sp[1] = 1;
    for (i = 2; i < MAX; i += 2)
        sp[i] = 2; //even numbers have smallest prime factor 2
    for (i = 3; i < MAX; i += 2)
    {
        if (!v[i])
        {
            sp[i] = i;
            for (j = i; (j * i) < MAX; j += 2)
            {
                if (!v[j * i])
                    v[j * i] = true, sp[j * i] = i;
            }
        }
    }
}

ll power(ll a, ll b)
{
    ll result = 1;
    while (b)
    {
        if (b % 2)
            result *= a;
        a *= a;
        b /= 2;
    }
    return result;
}

// All Variables Here

int main()
{
    b_v_r();

    Sieve();

    ll i, j;

    int n; //Number of Elements
    int k; // kth root is integer
    int q; // Number of Queries

    cin >> n >> k >> q;

    ll a[n+1] = {0};

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int qtype;
    ll low, rig, x, y;

    while (q--)
    {
        cin >> qtype;

        if (qtype == 1)
        {
            // is special or not.
            cin >> low >> rig;

            if (k == 1)
            {
                cout << "Yes" << endl;
                continue;
            }

            ll prod = 1;
            map<int, int> mp;

            for (i = low; i <= rig; i++)
            {
                prod = a[i];
                // factorize a[i]
                while (prod != 1)
                {
                    mp[sp[prod]]++;
                    prod = prod / (sp[prod]);
                    if (prod == 1)
                    {
                        break;
                    }
                }
            }

            bool f = true;
            for (auto ele : mp)
            {
                // cout << ele.first << " -> " << ele.second << endl;
                if ((ele.second % k) != 0)
                {
                    cout << "No" << endl;
                    f = false;
                    break;
                }
            }

            if (f)
            {
                cout << "Yes" << endl;
            }
        }
        else
        {
            if (qtype == 2)
            {
                // Multiply all the elements of the subarray -> X^Y
                cin >> low >> rig >> x >> y;
                ll xpowy = power(x, y);
                for (i = low; i <= rig; i++)
                {
                    a[i] *= xpowy;
                }
            }
            else
            {
                if (qtype == 3)
                {
                    //Reset all the elements of subarray -> X.
                    cin >> low >> rig >> x;
                    for (i = low; i <= rig; i++)
                    {
                        a[i] = x;
                    }
                }
            }
        }
    }

    return 0;
}
