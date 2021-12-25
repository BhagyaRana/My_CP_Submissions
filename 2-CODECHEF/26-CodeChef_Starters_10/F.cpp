#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MOD 1000000007
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arrr1[n][32];
        int arrr2[n][32];
        int mat[n][32];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                arrr2[i][j] = 0;
                arrr1[i][j] = 0;
                mat[i][j] = 0;
            }
        }

        bool flips[n] = {false};

        int x;
        int index;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            index = 0;
            while (x > 0)
            {
                int rem = x % 2;
                arrr1[i][index] = rem;
                x /= 2;
                index++;
            }
        }

        for (int i = 0; i < n; i++)
        {

            cin >> x;
            index = 0;
            while (x > 0)
            {
                int rem = x % 2;
                arrr2[i][index] = rem;
                x /= 2;
                index++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                mat[i][j] = (arrr1[i][j] | arrr2[i][j]);
                //cout<<mat[i][j]<<" ";
            }
            //cout<<endl;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 32; j++)
            {
                mat[i][j] = mat[i - 1][j] + mat[i][j];
            }
        }

        int lastform = -1;

        for (int i = 31; i >= 0; i--)
        {
            if (mat[n - 1][i] == n)
            {
                lastform = i;
                break;
            }
        }

        if (lastform == -1)
        {
            cout << "0 0\n";
        }
        else
        {
            int answer = 0;
            int flipp = 0;
            int tt = lastform;
            while (lastform >= 0)
            {
                bool ff = false;
                for (int i = 0; i < n; i++)
                {
                    if (flips[i] == false)
                    {
                        if (arrr1[i][lastform] == 1)
                        {
                            //nothing
                        }
                        else
                        {
                            bool fz = false;
                            for (int j = lastform; j <= tt; j++)
                            {
                                if (arrr1[i][j] > arrr2[i][j])
                                {
                                    fz = true;
                                    break;
                                }
                            }
                            if (fz == false && arrr2[i][lastform] == 1)
                            {
                                flipp++;
                                flips[i] = true;
                            }
                        }
                    }
                    else
                    {
                        if (arrr2[i][lastform] == 1)
                        {
                            //nothing
                        }
                        else
                        {
                            ff = true;
                            break;
                        }
                    }
                }
                if (ff == false)
                {
                    answer = answer + pow(2, lastform);
                }
                lastform--;
            }

            cout << answer << " " << flipp << endl;
        }
    }
}