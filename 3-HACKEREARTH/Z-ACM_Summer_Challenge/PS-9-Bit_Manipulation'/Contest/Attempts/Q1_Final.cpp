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
    // units of powers of 2
    //  nutrition requirement of N units
    // M Fruits -> Ai to m -> Non Negative Power of 2
    //  cannot eat the fruits which have nutrition value more than N-K  where K denotes the sum of nutrition values of fruits he already ate
    w(t)
    {
        ll n;  // Hunger Requirement
        int m; // No of Elements in Array

        cin >> n >> m;
        ll temp_n = n;
        ll k = 0; // Food Ate

        mk(arr, m, ll);

        ull sum = 0;

        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if (sum < n)
        {
            // No Matter How Many Cuts -> You can't Satisfy
            cout << "-1" << endl;
        }
        else
        {
            if (sum == n)
            {
                cout << "0" << endl;
            }
            else
            {
                // sum > n
                ll cuts = 0LL;
                int flag = 0;

                sort(arr, arr + m);
                cout << "Sorted" << endl;

                while (!(n - k ==0))
                {
                    // Case 1 : Find the Exact n - k
                    bool found = binary_search(arr, arr + m, n - k);
                    if (found == true)
                    {
                        // Zero Cuts Required
                        cout << "Binary Search Found" << endl;
                        cout << cuts << endl;
                        flag  = 1;
                    }

                    // Case 2 :
                    int upp = upper_bound(arr, arr + n, n - k) - arr;

                    cout << "Upper Index : "<< upp << endl;

                    //arr[upp] > (n-k)
                    while (arr[upp] > (n - k))
                    {
                        cuts++;
                        arr[upp] /= 2;
                        k += arr[upp];
                    }
                }
                if(flag!=1)
                {
                    cout << "Flag Final : "<< endl;
                    cout << cuts << endl;
                }
            }
        }
    }

    return 0;
}
