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

string func(string str)
{
    // size of the string
    int n = str.size();
    // to store maximum frequency
    int maxi = 0;
    // to store string which has maximum frequency
    string s;

    int lenmax = 0;

    string ans;

    int gid = 100001;

    map<string, int> m;
    map<string, int> idx;

    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = i; j < n; j++)
        {
            s += str[j];
            m[s]++;
            if (idx.find(s) == idx.end())
                idx[s] = i;
        }
    }

    for (auto i = m.begin(); i != m.end(); i++)
    {
        // cout << "F :" << i->first << " S : " << i->second << endl;
        if (i->second >= maxi)
        {
            maxi = i->second;
            lenmax = max(lenmax, (i->first).length());
            // s = i->first;
            // cout << "String : "<< s << endl;
        }
    }
    // cout << maxi << endl;
    // cout << lenmax << endl;

    for (auto i = m.begin(); i != m.end(); i++)
    {
        // cout << "F :" << i->first << " S : " << i->second << endl;
        if ((i->second == maxi) && ((i->first).length() == lenmax))
        {
            string k = i->first;
            // if(k.length() == lenmax)
            // {
            //     cout << "String : "<< k << endl;
            // }
            // cout << "String : "<< k << endl;
            // cout << "IDX :" << idx[k] << endl;
            if (idx[k] < gid)
            {
                ans = k;
                gid = idx[k];
                // cout << ans << endl;
            }
        }
    }
    // for (auto i = idx.begin(); i != idx.end(); i++)
    // {
    //     cout << "F :" << i->first << " S : " << i->second << endl;
    // }

    // return substring which has maximum frequency
    return ans;
}

int main()
{
    b_v_r();

    string s;

    cin >> s;

    cout << func(s) << endl;

    return 0;
}