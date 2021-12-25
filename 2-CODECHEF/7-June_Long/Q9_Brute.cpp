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

void find_odd(ll s, ll n, ll cnt)
{
    // y -> prediction c-> result

    char ans, ans2;
    ll low = s;
    ll high = n;
    ll prediction = low + ((high - low) / 2);

    cnt += 1;

    cout << prediction << endl;
    fflush(stdout);
    // cnt is odd
    if (cnt & 1)
    {
        cin >> ans;

        if (ans == 'E')
        {
            // y == x
            return;
            cout << "Found Number";
        }
        else
        {
            if (ans == 'L')
            {
                // prediction > x
                find_odd(low, prediction - 1, cnt);
            }
            else
            {
                if (ans == 'G')
                {
                    // prediction < x
                    find_odd(prediction + 1, high, cnt);
                }
            }
        }
    }
    else
    {
        //cnt is even
        cin >> ans2;
        if (ans2 == 'E')
        {
            // y == x
            return;
            cout << "Found Number";
        }
        // find_odd(low, high, cnt);
    }
}

void find_even(ll s, ll n, ll &cnt)
{
    // y -> prediction c-> result

    char ans, ans2;
    ll low = s;
    ll high = n;
    ll prediction = low + ((high - low) / 2);

    cnt += 1;

    cout << prediction << endl;
    fflush(stdout);

    // cnt is odd
    if ((cnt % 2) == 0)
    {
        cin >> ans;

        if (ans == 'E')
        {
            // y == x
            return;
            cout << "Found Number";
        }
        else
        {
            if (ans == 'L')
            {
                // prediction > x
                find_even(low, prediction - 1, cnt);
            }
            else
            {
                if (ans == 'G')
                {
                    // prediction < x
                    find_even(prediction + 1, high, cnt);
                }
            }
        }
    }
    else
    {
        //cnt is even
        cin >> ans2;
        if (ans2 == 'E')
        {
            // y == x
            return;
            cout << "Found Number";
        }
        // find_even(low, high, cnt);
    }
}

// SACH YA JUTH KA FUNCTION

int xyz = 5;

int sachyajuth(ll n)
{

    char c;
    ll n1 = n;

    cout << n << endl;
    fflush(stdout);
    cin >> c;
    if (c == 'E')
    {
        // y == x
        return 0;
        cout << "Found Number";
    }
    bool torf1 = (c == 'L') ? true : false;

    cout << 1 << endl;
    fflush(stdout);
    cin >> c;
    if (c == 'E')
    {
        // y == x
        return 0;
        cout << "Found Number";
    }
    bool torf2 = (c == 'G') ? true : false;

    cout << n << endl;
    fflush(stdout);
    cin >> c;
    if (c == 'E')
    {
        // y == x
        return 0;
        cout << "Found Number";
    }
    bool torf3 = (c == 'L') ? true : false;

    cout << 1 << endl;
    fflush(stdout);
    cin >> c;
    if (c == 'E')
    {
        // y == x
        return 0;
        cout << "Found Number";
    }
    bool torf4 = (c == 'G') ? true : false;

    if (torf1 && torf2 && torf3 && torf4)
    {
        if (xyz > 0)
        {
            int ans1 = sachyajuth(n1);
            xyz -= 1;
            return ans1;
        }
        else
        {
            return -1;
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
