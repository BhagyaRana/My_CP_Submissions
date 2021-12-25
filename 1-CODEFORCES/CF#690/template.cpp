// <Template For nCr>
const int MAXN = 300500;
const int mod = 1000000007;
using ll = long long;
ll fact[MAXN];
ll invFact[MAXN];

ll fast_pow(ll a, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p % 2 == 0)
        {
            a = (a * a) % mod;
            p /= 2;
        }
        else
        {
            res = (res * a) % mod;
            p--;
        }
    }
    return res;
}

ll nCr(int n, int k)
{
    if (k > n)
    {
        return 0;
    }
    return fact[n] * invFact[k] % mod * invFact[n - k] % mod;
}

// IMP! Add this to Precompute Before Test Cases!

// fact[0] = invFact[0] = 1;
// for (int i = 1; i < MAXN; i++)
// {
//     fact[i] = (fact[i - 1] * i) % mod;
//     invFact[i] = fast_pow(fact[i], mod - 2);
// }

// IMP! Add this to Precompute Before Test Cases!