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
    w(t)
    {
        ll n, m;
        cin >> n >> m;
        vector<int> vis(64, 0);
        ll cut = 0LL, sum = 0LL;
        ll num;
        for (int i = 0; i < m; i++)
        {
            cin >> num;
            sum += num;
            int index = log2(num);
            vis[index]++;
        }
        if (sum < n)
        {
            //Hunger Cant be Satisfied
            cout << "-1" << endl;
            continue;
        }
        else
        {
            int j;
            for (int i = 0; i < 64; i++)
            {
                //Check ith Bit is Set or Not
                if (n & (1LL << i))
                {
                    for (j = 0; j < i; j++)
                    {
                        vis[j + 1] += (vis[j] / 2); //To Get Minimum Cuts
                        vis[j] = vis[j] % 2;        // To Store Only 0 or 1
                    }

                    //if vis[i] is anything other than 0
                    if (vis[i])
                    {
                        //He Ate this Much(1<<i)
                        n -= (1LL << i);
                        vis[i]--;
                        continue;
                    }

                    j = i;
                    // Find Nearest Big
                    while (j < 64 && vis[j] == 0)
                    {
                        vis[j] += 1;
                        j++;
                    }

                    cut += (j - i);

                    vis[j]--;
                    vis[i]--;
                }
            }
            cout << cut << endl;
        }
    }

    return 0;
}