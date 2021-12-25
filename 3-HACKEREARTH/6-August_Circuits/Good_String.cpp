#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int MXN = 2005;

// All Functions Here
bool isSubsetSum(int set[MXN][2], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j >= set[i - 1][0])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1][0]];
            else if (j >= set[i - 1][1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1][1]];
            else
                subset[i][j] = false;
        }
    }
    return subset[n][sum];
}

// All Variables Here

int main()
{
    b_v_r();

    int n; // length of string
    int flag = 0; // for yes/no 
    string s; // string

    cin >> n;

    cin >> s;

    int stk[MXN][2];
    int gamma[MXN]; // gamma value
    int end[MXN]; // index of closing bracket
    int val[MXN][2];

    for (int i = 0; i < 2000; i++)
    {
        gamma[i] = 0;
        val[i][0] = 0;
        val[i][1] = 0;
    }

    int h = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '#')
            h++;
        else if (s[i] == '(')
            b++;
    }

    int x, y, z;

    for (int i = 0; i < h; i++)
    {
        cin >> x >> y;
        // value of bracket at index (x-1) = y
        val[x - 1][0] = y;
    }

    for (int i = 0; i < b; i++)
    {
        cin >> x >> y >> z;
        // gamma value of opening bracket at index (x-1)
        gamma[x - 1] = z;
        end[x - 1] = y - 1;
    }

    //traverse from the back

    for (int i = n; i >= 0; i--)
    {
        if (gamma[i])
        {
            int sc = 0;

            y = 0;

            for (int j = i; j < end[i] && j < n; j++)
            {
                // value of bracket
                if (val[j][0])
                {
                    stk[sc][0] = val[j][0];
                    stk[sc++][1] = val[j][1];
                    y += val[j][0] + val[j][1];
                    val[j][0] = 0;
                }
            }

            x = 0;

            if (isSubsetSum(stk, sc, gamma[i]))
                x = gamma[i];
            else
            {
                flag = 1;
                break;
            }

            y = y - x;
            val[i][0] = x;
            val[i][1] = y;
        }
    }

    
    if (flag == 1)
        cout << "No";
    else
        cout << "Yes";

    return 0;
}