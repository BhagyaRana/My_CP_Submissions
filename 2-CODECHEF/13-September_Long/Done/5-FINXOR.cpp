#include <bits/stdc++.h>
using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]
const int mod = 1000000007;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

#define watch(x) cout << (#x) << " is : " << (x) << "\n"
#define watch2(x, y) cout << (#x) << " is " << (x) << " and " << (#y) << " is " << (y) << "\n"

#define MAX 20

// All Variables Here
vector<ll> pow2(MAX + 1);

// All Functions Here
void precompute()
{
    pow2[0] = 1;
    for (int i = 1; i < MAX + 1; i++)
        pow2[i] = 2 * pow2[i - 1];
}

int main()
{
    precompute();
    int n, my_sum, judge_sum, tmp;
    w(t)
    {
        cin >> n;
        ll sum = 0;

        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 |<-->| 20

        // Query 1 : For 2^0 Part of Answer
        cout << "1 " << pow2[MAX] << endl;
        fflush(stdout);

        cin >> sum; // Sum of All n Elements

        // Subtract the 2^20 Part from Answer
        sum -= (pow2[20] * n);

        // If sum remaining is Even -> XOR will Ultimately be 0
        int FINXOR = 0;

        // Otherwise -> XOR 1
        // If the Sum is Odd -> Odd + Even -> At 2^0 Place "1" will come
        // if all Elements are XOR

        if (sum & 1)
            FINXOR += 1;

        for (int i = 1; i < 20; i++)
        {
            // 2^i for Each Number = 2^i * n
            my_sum = sum + (pow2[i] * n);

            // watch(my_sum);
            // Query i+1 - > 1 & 2^i
            cout << 1 << " " << pow2[i] << endl;
            fflush(stdout);

            cin >> judge_sum;

            if (judge_sum == -1)
            {
                // Invalid Input or Query Exceed
                break;
            }

            // Difference is {2 * (Sum of 2^i)}
            tmp = ((my_sum - judge_sum) / (pow2[i] * 2));
            // Divide it by One Power Up

            // If the tmp is Odd -> Odd + Even -> At 2^i Place "1" will come
            // if all Elements are XOR

            if (tmp & 1)
                FINXOR += pow2[i];
        }

        cout << 2 << " " << FINXOR << endl;
        fflush(stdout);

        int verdict;
        cin >> verdict;

        if (verdict == -1)
        {
            break;
        }
        else
        {
            continue;
        }
    }

    return 0;
}