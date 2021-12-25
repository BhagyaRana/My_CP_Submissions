#include <bits/stdc++.h>

using namespace std;

const int LCM = 2520;
const int MAXDIG = 20;

// [1..9]
long long memo[MAXDIG][2][LCM][(1 << 9) + 5];
vector<int> dig;
int K;

long long dp(int index, int tight, int rem, int mask)
{
    long long &res = memo[index][tight][rem][mask];
    if (res != -1)
    {
        return res;
    }
    res = 0;
    if (index == dig.size())
    {
        int cnt = 0;
        for (int d = 1; d < 10; d++)
        {
            if (mask & (1 << (d - 1)))
            {
                if (rem % d == 0)
                {
                    cnt++;
                }
            }
        }
        if (cnt >= K)
        {
            res = 1;
        }
    }
    else
    {
        for (int d = 0; d < 10; d++)
        {
            if (tight & (d > dig[index]))
            {
                continue;
            }
            int newTight = ((tight == 1) ? (d == dig[index]) : 0);
            int newRem = (rem * 10 + d) % LCM;
            int newMask = mask;
            if (d != 0)
            {
                newMask = (mask | (1 << (d - 1)));
            }
            res += dp(index + 1, newTight, newRem, newMask);
        }
    }
    return res;
}

long long solve(long long n)
{
    dig.clear();
    if (n == 0)
    {
        dig.push_back(n);
    }
    while (n)
    {
        dig.push_back(n % 10);
        n /= 10;
    }
    reverse(dig.begin(), dig.end());
    memset(memo, -1, sizeof(memo));
    return dp(0, 1, 0, 0);
}

int main()
{
    int Q;
    scanf("%d", &Q);
    while (Q--)
    {
        long long L, R;
        scanf("%lld %lld %d", &L, &R, &K);
        long long ans = solve(R) - solve(L - 1);
        /*
    printf("%lld\n", solve(R));
    printf("%lld\n", solve(L - 1));
    */
        printf("%lld\n", ans);
    }
    return 0;
}