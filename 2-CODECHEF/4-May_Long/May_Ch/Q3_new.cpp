#include <bits/stdc++.h>

#include <ios>

#include <limits>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define rep(i, n) for (i = 0; i < n; ++i)
#define REP(i, k, n) for (i = k; i <= n; ++i)
#define REPR(i, k, n) for (i = k; i >= n; --i)
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
    w(t)
    {
        int n;
        cin >> n;

        string str1, str2;
        cin.ignore(256, '\n');
        getline(cin, str1);
        getline(cin, str2);
        
        int n1 = str1.size();
        int n2 = str2.size();
        int freq1[26], freq2[26];
        memset(freq1, 0, sizeof(freq1));
        memset(freq2, 0, sizeof(freq2));
        for (int i = 0; i < n1; i++)
            freq1[str1[i] - 'a']++;
        for (int i = 0; i < n2; i++)
            freq2[str2[i] - 'a']++;

        
        vector <int> b;
        int j = 0;
        int i = 0;
        int flag = 0;
        int ca1 = 0, cb1 = 0, ca2 = 0, cb2 = 0,brep = 0;
        int aindex = 0;
        bool ok = true;
        bool check = true;
        if(str1==str2)
        {
            cout << "0" << endl;
            check = false;
        }
        rep(i, n)
        {
            if(check==false)
                break;
            if (str1[i] != str2[i])
            {
                if (str1[i] == 'a')
                {
                    cout << "-1" << endl;
                    flag = 1;
                    break;
                }
                else
                {
                    if(str1[i]!='a')
                        brep++;
                    b.push_back(i);
                }
            }
            else
            {
                if (str2[i] == 'a'&&ok)
                {
                    aindex = i;
                    ok = false;
                }
                
            }
        }
        if (flag != 1&&check)
        {
            if (freq1[0] == 0 && freq2[1] > 0)
            {
                cout << "-1" << endl;
            }
            else
            {
                cout << "1" << endl;
                cout << brep + 1 << " " << aindex << " ";
                vector<int> ::iterator it;
                for(it = b.begin();it!=b.end();it++)
                {
                    cout << *it << " ";
                }
                cout << endl;
            }
        }

    }

    return 0;
}
