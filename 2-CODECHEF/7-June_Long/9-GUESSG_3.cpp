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
ll low;
ll high;
ll mid;
ll k = 500;

void Truth(ll num1, ll num2)
{
    low = num1;
    high = num2;
    char c, res;
    char ch1, ch2, ch3, ch4, ch5, ch6;
    // cout << num1 << endl;
    // fflush(stdout);
    // cin >> c;
    // if (c == 'E')
    //     return;
    // cout << num2 << endl;
    // fflush(stdout);
    // cin >> c;
    // ch1 = c;
    // if (c == 'E')
    //     return;

    while (low <= high)
    {
        mid = low + ((high - low) / 2);

        int gcnt = 0;
        int lcnt = 0;

        cout << mid << endl;
        fflush(stdout);
        cin >> c;
        ch1 = c;
        if (c == 'E')
            break;
        if (c == 'G')
            gcnt++;
        else
        {
            lcnt++;
        }

        cout << mid << endl;
        fflush(stdout);
        cin >> c;
        ch2 = c;
        if (c == 'E')
            break;
        if (c == 'G')
            gcnt++;
        else
        {
            lcnt++;
        }

        cout << mid << endl;
        fflush(stdout);
        cin >> c;
        ch3 = c;
        if (c == 'E')
            break;
        if (c == 'G')
            gcnt++;
        else
        {
            lcnt++;
        }

        k -= 3;
        if (k >= 0)
        {
            if ((ch1 == ch2 && ch2 == ch3) || (ch1 == ch2) || (ch2 == ch3))
            {
                if (ch1 == ch2)
                {
                    if (ch1 == 'G')
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
                else
                {
                    if (ch2 == ch3)
                    {
                        if (ch2 == 'G')
                        {
                            low = mid + 1;
                        }
                        else
                        {
                            high = mid - 1;
                        }
                    }
                }
            }
            else
            {
                cout << high << endl;
                fflush(stdout);
                cin >> c;
                ch4 = c;
                if (c == 'E')
                    break;
                k--;
                if (ch4 == 'G')
                {
                    if (ch3 == 'G')
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                    if (low <= high)
                    {
                        mid = low + ((high - low) / 2);

                        cout << mid << endl;
                        fflush(stdout);
                        cin >> c;
                        if (c == 'E')
                            break;
                        k--;
                        if (c == 'G')
                        {
                            low = mid + 1;
                        }
                        else
                        {
                            high = mid - 1;
                        }
                    }
                }
                else
                {
                    cout << mid << endl;
                    fflush(stdout);
                    cin >> c;
                    ch5 = c;
                    if (c == 'E')
                        break;
                    if (c == 'G')
                        gcnt++;
                    else
                    {
                        lcnt++;
                    }

                    cout << mid << endl;
                    fflush(stdout);
                    cin >> c;
                    ch6 = c;
                    if (c == 'E')
                        break;
                    if (c == 'G')
                        gcnt++;
                    else
                    {
                        lcnt++;
                    }

                    k-=2;

                    if(gcnt>lcnt)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                    
                }
            }
        }
        else
        {
            break;
        }
    }
    return;
}

int main()
{
    b_v_r();

    ll n;
    cin >> n;
    Truth(1, n);

    return 0;
}