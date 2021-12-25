#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
typedef long long ll;

unsigned int gcd1(unsigned int u, unsigned int v)
{
    int shift;
    if (u == 0)
        return v;
    if (v == 0)
        return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do
    {
        v >>= __builtin_ctz(v);
        if (u > v)
        {
            unsigned int t = v;
            v = u;
            u = t;
        }
        v = v - u;
    } while (v != 0);
    return u << shift;
}

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

int fx(int n)
{
    stringstream stream;
    stream << std::hex << n;
    string r(stream.str());
    int len = r.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if ((r[i] - '0' >= 0) && (r[i] - '0' <= 9))
            sum += (r[i] - '0');
        else
        {
            switch (r[i])
            {
            case 'a':
                sum += 10;
                break;
            case 'b':
                sum += 11;
                break;
            case 'c':
                sum += 12;
                break;
            case 'd':
                sum += 13;
                break;
            case 'e':
                sum += 14;
                break;
            case 'f':
                sum += 15;
                break;
            }
        }
    }
    // cout << sum <<  endl;
    return sum;
}

int val[100001];

int main()
{
    b_v_r();
    val[0] = 1;
    for (int k = 1; k <= 100000; k++)
    {
        val[k] = fx(k);
        // cout << "val[" << k << "] = " << val[k] << endl;
    }
    w(t)
    {
        int l, r;
        cin >> l >> r;
        int cnt = 0;
        // fx(27);

        int ans1 = 0;
        int ans2 = 0;
        for (int i = l; i <= r; i++)
        {
            // cout << "gcd find start :"<<endl;
            ans2 = gcd1(i, val[i]);
            // cout << "gcd find ends :"<<endl;
            // cout << "ans2 : "<< ans2 << endl;
            if (ans2 > 1)
                cnt++;
        }
        cout << cnt << endl;
    }

    return 0;
}
