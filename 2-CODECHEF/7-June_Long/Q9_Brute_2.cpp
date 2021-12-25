#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

ll cnt;
ll low;
ll high;

void find_odd(ll s, ll n, ll &count)
{
    // y -> prediction c-> result

    char ans, ans2;
    low = s;
    high = n;
    cnt = count;

    while (low <= high)
    {
        ll prediction = low + ((high - low) / 2);

        cnt += 1;

        cout << prediction << endl;
        fflush(stdout);

        cin >> ans;

        // cnt is odd
        if ((cnt % 2) != 0)
        {

            if (ans == 'E')
            {
                // y == x
                break;
            }
            else
            {
                if (ans == 'L')
                {
                    // prediction > x
                    high = prediction - 1;
                }
                else
                {
                    if (ans == 'G')
                    {
                        // prediction < x
                        low = prediction + 1;
                    }
                }
            }
        }
    }
}

void find_even(ll s, ll n, ll &count)
{
    // y -> prediction c-> result

    char ans, ans2;
    low = s;
    high = n;
    cnt = count;

    while (low <= high)
    {
        ll prediction = low + ((high - low) / 2);

        cnt++;

        cout << prediction << endl;
        fflush(stdout);

        cin >> ans;

        // cnt is odd
        if ((cnt % 2) == 0)
        {

            if (ans == 'E')
            {
                // y == x
                break;
            }
            else
            {
                if (ans == 'L')
                {
                    // prediction > x
                    high = prediction - 1;
                }
                else
                {
                    if (ans == 'G')
                    {
                        // prediction < x
                        low = prediction + 1;
                    }
                }
            }
        }
    }
}

// SACH YA JUTH KA FUNCTION

int xyz = 75;

int sachyajuth(ll n)
{

    char c;

    cout << n << endl;
    fflush(stdout);

    cin >> c;

    if (c == 'E')
    {
        // y == x
        return 0;
    }
    bool torf1 = (c == 'L') ? true : false;

    cout << "1" << endl;
    fflush(stdout);

    cin >> c;

    if (c == 'E')
    {
        // y == x
        return 0;
    }
    bool torf2 = (c == 'G') ? true : false;

    cout << n << endl;
    fflush(stdout);

    cin >> c;
    if (c == 'E')
    {
        // y == x
        return 0;
    }
    bool torf3 = (c == 'L') ? true : false;

    cout << "1" << endl;
    fflush(stdout);

    cin >> c;
    if (c == 'E')
    {
        // y == x
        return 0;
    }
    bool torf4 = (c == 'G') ? true : false;

    if (torf1 && torf2 && torf3 && torf4)
    {
        if (xyz > 0)
        {
            int ans1 = sachyajuth(n);
            xyz -= 1;
            return ans1;
        }
        else
        {
            return 1;
        }

        // 1 -> Sach on odd
        // 2 -> Sach on even
    }
    else
    {
        if (torf1 && torf3 && (!torf2) && (!torf4))
        {
            // 1 -> Sach on odd
            return 1;
        }
        else
        {
            if (torf2 && torf4 && (!torf1) && (!torf3))
            {
                // 2 -> Sach on even
                return 2;
            }
            else
            {
                if ((!torf1) || (!torf3))
                    return 2;
                if ((!torf2) || (!torf4))
                    return 1;
            }
        }
    }
}

int main()
{
    b_v_r();

    ll n;
    cin >> n;

    int ans = sachyajuth(n);
    // 1 -> Sach on odd
    // 2 -> Sach on even
    // -1 -> unable to find sach on odd or even
    ll count = 4;
    if (ans == 1)
    {
        find_odd(1, n, count);
    }
    else
    {
        if (ans == 2)
        {
            find_even(1, n, count);
        }
        else
        {
            return 0;
        }
        
    }
    return 0;
}
