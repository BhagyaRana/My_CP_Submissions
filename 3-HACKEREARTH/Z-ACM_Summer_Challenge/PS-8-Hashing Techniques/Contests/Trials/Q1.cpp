#include <bits/stdc++.h>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"
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

vector<int> hashTable[10001];

int main()
{
    b_v_r();
    w(t)
    {
        int n;
        cin >> n;
        mk(arr, n, int);
        mk(arrb, n, int);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            hashTable[arr[i]].push_back(i + 1);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arrb[i];
        }
        vector<int> v;
        v.push_back(0);
        int g = 0;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (hashTable[arrb[i]].size() == 0)
            {
                cout << "-10099" << endl;
                flag = -1;
                break;
            }
            else
            {
                int found = 0;
                for (int k = 0; k < hashTable[arrb[i]].size(); k++)
                {
                    if (hashTable[arrb[i]][k] > v[g])
                    {
                        v.push_back(hashTable[arrb[i]][k]);
                        g++;
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                {
                    g++;
                    for (int l = 0; l < hashTable[arrb[i]].size(); l++)
                    {
                        if (hashTable[arrb[i]][l] > v[g])
                            v.push_back(hashTable[arrb[i]][l]);
                    }
                }

            }
        }
        v.push_back(0);

        // cout << "VECTOR : " << endl;
        int round = 0;
        for (int i = 1; i < v.size(); i++)
        {
            if(v[i]<=v[i-1])
                round++;
        }
        if(flag!=-1)
            cout << round <<endl;


    }

    return 0;
}
