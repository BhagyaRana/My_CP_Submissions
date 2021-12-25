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

int lgth(ll n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

vector<ll> spc;
int i;
ll temp, temp2;

void func(vector<ll> old)
{
    int vsz = old.size();
    int len = lgth(old[0]);

    if(len == 9)
    {
        return; 
    }

    ll pow = 1;

    for (i = 0; i < len; i++)
    {
        pow *= 10;
    }

    vector<ll> vec;

    for (i = 0; i < vsz; i++)
    {
        temp = (pow * 4) + old[i];
        vec.emplace_back(temp);
        spc.emplace_back(temp);
    }

    for (i = 0; i < vsz; i++)
    {
        temp2 = (pow * 7) + old[i];
        vec.push_back(temp2);
        spc.emplace_back(temp2);
    }

    func(vec);

    return;
}

int main()
{
    b_v_r();

    spc.push_back(4);
    spc.push_back(7);

    func(spc);
    
    int sz = spc.size();

    // for(int j=0;j<sz;j++)
    // {
    //     watch(spc[j]);
    // }


    // sort(spc,spc+n);
    ll n;
    cin >> n;
    ll pcnt = 0LL;
    int idx = upper_bound(spc.begin(), spc.end(), n) - spc.begin();
    // watch(idx);
    for (int i = 0; i < idx; i++)
    {
        for (int j = i; j < idx; j++)
        {
            if (__gcd(spc[i], spc[j]) == 1)
                pcnt++;
        }
    }
    cout << pcnt << endl;

    return 0;
}
