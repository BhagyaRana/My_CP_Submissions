// https://www.codechef.com/AUG20B/problems/SKMP

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

    w(t)
    {
        string s, p;

        cin >> s >> p;

        int slen = s.length(), plen = p.length();

        int sfreq[26] ={ 0 }, pfreq[26] ={ 0 };
        int cnt;

        for (int i=0;i<slen;i++)
        {
            sfreq[s[i]-'a']++;
        }

        // cout << "SFREQ" << endl;
        // for (int i=0;i<26;i++)
        // {
        //     cout << sfreq[i] << " ";
        // }
        // cout << endl;


        for (int i=0;i<plen;i++)
        {
            pfreq[p[i]-'a']++;
        }

        // cout << "PFREQ" << endl;
        // for (int i=0;i<26;i++)
        // {
        //     cout << pfreq[i] << " ";
        // }
        // cout << endl;


        for (int i=0;i<26;i++)
        {
            sfreq[i] -= pfreq[i];
        }

        // cout << "MODIFIED SFREQ" << endl;
        // for (int i=0;i<26;i++)
        // {
        //     cout << sfreq[i] << " ";
        // }
        // cout << endl;

        char ch = p[0];

        string pre, suf, ans;
        char t1;
        // string ans = pre + p + suf;
        for (int i=0;i<=(int)(ch-'a');i++)
        {
            if (i<(int)(ch - 'a'))
            {
                cnt = sfreq[i];
                while (cnt--)
                {
                    t1 = 'a' + i;
                    pre += t1;
                }
                sfreq[i] = 0;
            }
            else
            {
                // i == ch - 'a'
                char t6;

                bool flag = false;
                char c5, c6;
                for (int j=1;j<plen;j++)
                {
                    c5 = p[j-1];
                    c6 = p[j];
                    if ((int)(c6 - 'a') < (int)(c5-'a'))
                    {
                        // good -> need to break
                        flag = true;
                        break;
                    }
                    else
                    {
                        if ((int)(c6 - 'a') == (int)(c5-'a'))
                        {
                            continue;
                        }
                        else
                        {
                            break;
                        }
                    }

                }

                if (flag)
                {
                    break;
                }
                else
                {
                    cnt = sfreq[i];
                    while (cnt--)
                    {
                        t1 = 'a' + i;
                        pre += t1;
                    }
                    sfreq[i] = 0;

                }

            }

        }


        char t2;
        for (int i=0;i<26;i++)
        {
            if (sfreq[i]>0)
            {
                cnt = sfreq[i];
                while (cnt--)
                {
                    t2 = 'a' + i;
                    suf += t2;
                }
                sfreq[i] = 0;
            }
        }

        ans += pre;
        // watch(pre);
        ans += p;

        ans += suf;

        // cout << "FINAL SFREQ" << endl;
        // for (int i=0;i<26;i++)
        // {
        //     cout << sfreq[i] << " ";
        // }
        // cout << endl;

        cout << ans << endl;

    }

    return 0;
}
