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
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

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

    int pc, pr, i;

    w(t)
    {
        cin >> pc >> pr;
        int cdigit = 0, rdigit = 0;

        cdigit += (pc/9);
        if (pc%9!=0)
            cdigit++;

        rdigit += (pr/9);
        if (pr%9!=0)
            rdigit++;

        if (rdigit <= cdigit)
        {
            // rick win
            cout << "1 " << rdigit << endl;
        }
        else
        {
            cout << "0 " << cdigit << endl;
        }

    }


    return 0;
}
