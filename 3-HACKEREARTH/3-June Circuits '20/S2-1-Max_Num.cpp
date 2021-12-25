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
typedef unsigned long long ull;

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
    ull fact[33];
    fact[0] = 1;
    for(int i=1;i<=32;i++)
    {
        fact[i] = fact[i-1]*i;
    }
    // cout << "Fact 32 : "<< fact[32]<<endl;
    int test;
    cin >> test;
    while (test--)
    {
        ll n, l;
        ll count = 0LL;

        cin >> n >> l;

        bitset<32> bitofn(n);
        mk(a, n + 1, ll);

        // Remember 1 Base Indexing
        int sum = 0;
        bitset<32> t1;
        for (ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
            t1 |= a[i];
        }
        bitset<32> t2(t1);
        bitset<32> t3(sum);
        int req_tot_bit = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (t1[i] == 1)
            {
                req_tot_bit = i + 1;
                break;
            }
        }
        // cout << "\nTEST : " << test + 1 << endl;
        // cout << "Req Set Bit : " << req_tot_bit << endl;

        if (l > t1.count())
        {
            cout << "-1" << endl;
        }
        else
        {
            if (l == t1.count())
            {
                cout << "1" << endl;
            }
            else
            {
                // t1.count() > l
                int cnt = t1.count();
                for (int i = 0; i < 32 && (cnt > l); i++)
                {
                    if (t1[i] == 1)
                    {
                        t1[i] = 0;
                        cnt--;
                    }
                }
                int zcnt = __builtin_clz(t1.to_ulong());
                // cout << "Bitset : " << t1 << endl;
                // cout << "Lead Zeros :" << 31 - zcnt << endl;
                // cout << "OBitset: " << t2 << endl;
                // cout << "SBitset: " << t3 << endl;
                int ozcnt = 0,zzcnt = 0;
                for(int i=31-zcnt-1;i>=0;i--)
                {
                    if(t1[i]==1&&t3[i]==0)
                        ozcnt++;
                    if(t1[i]==0&&t3[i]==0)
                        zzcnt++;
                }
                // cout << "ozcnt : "<<ozcnt << endl;
                // cout << "zzcnt : "<<zzcnt << endl;
                // Ans is ozcnt+zzcnt C zzcnt
                int n = ozcnt+zzcnt;
                int r = zzcnt;
                ull a1 = (fact[n]/(fact[n-r]));
                ull ans = a1/(fact[r]);
                cout << ans << endl;

            }
        }
    }

    return 0;
}
