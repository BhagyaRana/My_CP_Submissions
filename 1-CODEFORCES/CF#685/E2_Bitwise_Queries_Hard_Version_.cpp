// HEADERS AND NAMESPACE
#include <bits/stdc++.h>
using namespace std;

//LOOPS
// closed interver from l to r r inclusive
#define forc(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i)

// COMMONLY USED TYPES
typedef vector<int> vi;
typedef long long ll;

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

// All Functions Here
ll query(string s, int i, int j)
{
    cout << s << " " << i << " " << j << endl;
    fflush(stdout);
    ll ans;
    cin >> ans;
    if (ans == -1)
    {
        exit(0);
    }
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    string s1 = "XOR", s2 = "AND";
    ll xor1[n + 1] = {0};
    // n - 1 Queries
    set<ll> sset;
    forc(i, 2, n)
    {
        xor1[i] = query(s1, 1, i);

        sset.insert(xor1[i]);
    }
    // VERY IMPORTANT OBSERVATION FACT
    // a + b = (a^b) + 2*(a^b);

    // Each Element Takes Values from [0, n-1]
    // n is power of 2 => this means "n-1" has all bits Set [111111..]

    //CASE #1: Repeated Element in the Array
    // This Would Mean that xor1[i] == xor1[j] so, can find both using AND i & j
    // Ideally n - 1 elements in set
    if (sset.size() != (n - 1))
    {
        // Find Pair Whose XOR are Equal
        int pidx1 = 0;
        int pidx2 = 0;

        bool flag = false;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (xor1[i] == xor1[j])
                {
                    pidx1 = i;
                    pidx2 = j;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }

        // 1 Extra Query = n-1 + 1 = n Queries
        ll ANDij = query(s2, pidx1, pidx2);
        ll arr[n + 1] = {0};
        // arr[pidx1] = ANDij;
        // arr[pidx2] = ANDij;
        arr[1] = xor1[pidx1] ^ ANDij;
        forc(i, 2, n)
        {
            arr[i] = arr[1] ^ xor1[i];
        }

        cout << "! ";
        forc(i, 1, n)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        fflush(stdout);
    }
    else
    {
        // CASE #2 All Elements are Distinct [0, n-1]
        // There will be many pair whose xor will be (n-1) [All Bits Set]
        // Therefore there AND is 0
        // Find Pair Whose XOR are Equal
        // Find the Pair whose XOR == n-1
        int pidx1 = 0;
        int pidx2 = 0;
        bool flag = false;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if ((xor1[i] ^ xor1[j]) == (n - 1))
                {
                    pidx1 = i;
                    pidx2 = j;
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }

        ll xor1i = xor1[pidx1];
        ll xor1j = xor1[pidx2];
        ll xorij = n - 1;

        // n-1 Queries + 2 Queries = n+1 Queries
        ll and1i = query(s2, 1, pidx1);
        ll and1j = query(s2, 1, pidx2);

        ll andij = 0;

        ll sum1i = xor1i + (2 * (and1i));
        ll sum1j = xor1j + (2 * (and1j));
        ll sumij = xorij + (2 * (andij));

        ll arr[n + 1] = {0};

        arr[1] = (sum1i + sum1j - sumij) / 2;
        forc(i, 2, n)
        {
            arr[i] = xor1[i] ^ arr[1];
        }

        cout << "! ";
        forc(i, 1, n)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        fflush(stdout);
    }

    // EASY VERSION SOLN

    // // 3 Queries [n-1 + 3 = n + 2 Queries]
    // ll and12 = query(s2, 1, 2);
    // ll and13 = query(s2, 1, 3);
    // ll and23 = query(s2, 2, 3);

    // // EQUATION 1
    // ll sum12 = xor1[2] + 2 * (and12);
    // // EQUATION 2
    // ll sum13 = xor1[3] + 2 * (and13);
    // ll xor23 = xor1[2] ^ xor1[3];
    // // EQUATION 3
    // ll sum23 = xor23 + 2 * (and23);

    // ll arr[n + 1] = {0};

    // arr[1] = (sum12 + sum13 - sum23) / 2;
    // forc(i, 2, n)
    // {
    //     arr[i] = xor1[i] ^ arr[1];
    // }

    // cout << "! ";
    // forc(i, 1, n)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // fflush(stdout);

    return 0;
}
