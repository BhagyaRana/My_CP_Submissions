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
    forc(i, 2, n)
    {
        xor1[i] = query(s1, 1, i);
    }
    // VERY IMPORTANT OBSERVATION FACT
    // a + b = (a^b) + 2*(a^b);
    // 3 Queries [n-1 + 3 = n + 2 Queries]
    ll and12 = query(s2, 1, 2);
    ll and13 = query(s2, 1, 3);
    ll and23 = query(s2, 2, 3);

    // EQUATION 1
    ll sum12 = xor1[2] + 2 * (and12);
    // EQUATION 2
    ll sum13 = xor1[3] + 2 * (and13);
    ll xor23 = xor1[2] ^ xor1[3];
    // EQUATION 3
    ll sum23 = xor23 + 2 * (and23);

    ll arr[n + 1] = {0};

    arr[1] = (sum12 + sum13 - sum23) / 2;
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

    return 0;
}
