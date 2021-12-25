/*
DO NOT COMPARE YOURSELF WITH OTHERS
YOU ARE UNIQUE AND BE HONEST WITH CODING 
SHORT TERM CHEATING WILL MAKE YOU LIFE LONG IMPAIRED
*/

#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define endl "\n"

typedef long long ll;
#define mk(arr, n, type) type *arr = new type[n]

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

int gcd(int a, int b, int& x, int& y) 
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_soln(int a, int b, int c, int &x0, int &y0, int &g) 
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

int main()
{
    b_v_r();
    w(t)
    {
        int p, q, r, a, b, c;
        cin >> p >> q >> r;
        cin >> a >> b >> c;

        // px + 1d1 = a
        int flag =1;

        // If all three Equal
        if(p==a&&q==b&r==c)
        {
            cout << "0" << endl;
            flag = 0;
        }
        // if any Two are Equal
        if (p == a && q == b || p == q && r == c || q == b && r == c) 
        {
            cout << "1" << endl;
            flag = 0;
        }

        if(flag)
        {
            // px + 1*d1 = a
            int eq1x0,eq1y0,eq1gcd;
            find_soln(p,1,a,eq1x0,eq1y0,eq1gcd);

            // qx + 1*d2 = b
            int eq2x0,eq2y0,eq2gcd;
            find_soln(q,1,b,eq2x0,eq2y0,eq2gcd);

            // rx + 1*d3 = c
            int eq3x0,eq3y0,eq3gcd;
            find_soln(r,1,c,eq3x0,eq3y0,eq3gcd);

            // CASE 1:
            if(((eq1x0==1)&&(eq2x0==1)&&(eq3x0==1))&&((eq1y0==eq2y0)&&(eq1y0==eq3y0)))
            {
                cout<<"1"<<endl;
            }

            // CASE 4:
            if(((eq1y0==0)&&(eq2y0==0)&&(eq3y0==0))&&((eq1x0==eq2x0)&&(eq1x0==eq3x0)))
            {
                cout<<"1"<<endl;   
            }


        }
    }
}

    














 