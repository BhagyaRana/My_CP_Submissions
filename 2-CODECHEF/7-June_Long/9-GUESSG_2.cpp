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
ll k = 300;

void Truth(ll num1, ll num2)
{
    low = num1;
    high = num2;
    char c, res;
    while (low <= high)
    {
        mid = low + ((high - low) / 2);

        cout << low << endl;
        fflush(stdout);
        cin >> c;
        if (c == 'E')
            break;
        bool A1 = (c == 'G') ? true : false;

        cout << mid << endl;
        fflush(stdout);
        cin >> c;
        res = c;
        if (c == 'E')
            break;
        bool A2 = (c == 'G') ? true : false;

        cout << high << endl;
        fflush(stdout);
        cin >> c;
        if (c == 'E')
            break;
        bool A3 = (c == 'L') ? true : false;

        k -= 3;
        if (k >= 0)
        {
            if (A1 == false || A3 == false)
            {
                //Query 2 is Truth
                if (A2)
                {
                    //Prediction is Less
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }

                if (A3 == false)
                {
                    //Next Query Answer Sach Tena Padega
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