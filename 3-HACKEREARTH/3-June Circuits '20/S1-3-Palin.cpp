#pragma GCC optimize("O2")

#include <bits/stdc++.h>
using namespace std;

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
    int n, k;
    cin >> n >> k; // n -> String Length k-> Number of Consecutive SubString
    string s;
    cin >> s;
    s += 'a';
    cout << s << endl;
    // Zero Based Indexing -> In Question it is 1 Based
    vector<string> v;
    string temp;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        if (!((s[i] - 'a') < (s[i + 1] - 'a')))
        {
            cout << i << endl;
            v.push_back(s.substr(start, i - start + 1));
            start = i + 1;
        }
    }

    cout << "VECTOR SIZE : " << v.size() << endl;
    // for(string str : v)
    // {
    //     cout << str << endl;
    // }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    // sort(s.begin(), s.end());

    return 0;
}
