#include <bits/stdc++.h>

#define MAX 100000
#define bitscount 31

using namespace std;

int preComputeArray[bitscount][MAX];

long long int myFunction[bitscount][MAX];
long int power[31];
long long int powersum[31];

void preCompute(int arr[], int n)
{
    for (int i = 0; i < bitscount; i++)
    {
        preComputeArray[i][0] = ((arr[0] >> i) & 1);

        long long int temp = power[i] - (powersum[i] & arr[0]);
        if (temp > 0)
        {
            myFunction[i][0] = temp;
        }
        else
        {
            myFunction[i][0] = 0;
        }
        for (int j = 1; j < n; j++)
        {
            preComputeArray[i][j] = ((arr[j] >> i) & 1);

            temp = power[i] - (powersum[i] & arr[j]);
            if (temp > 0)
            {
                myFunction[i][j] = temp;
            }
            else
            {
                myFunction[i][j] = 0;
            }
            myFunction[i][j] += myFunction[i][j - 1];
            preComputeArray[i][j] += preComputeArray[i][j - 1];
        }
    }
}

long long int minimumADD(int l, int r)
{
    long long int ans;
    for (int i = 0; i < bitscount; i++)
    {
        int x;
        long long int temp;
        if (l == 0)
        {
            x = preComputeArray[i][r];
            temp = myFunction[i][r];
            //cout<<temp<<" ";
        }
        else
        {
            x = preComputeArray[i][r] - preComputeArray[i][l - 1];
            temp = myFunction[i][r] - myFunction[i][l - 1];
            //cout<<temp<<" ";
        }

        if (x == r - l + 1)
        {
            return 0;
        } //cout<<"Dsd"<<endl;
        //long long int temp = (r-l+1-x)*power[i];

        if (i == 0)
        {
            ans = temp;
        }
        else if (ans > temp)
        {
            ans = temp;
            //cout<<"HEllo"<<ans<<" ";
        }
    }
    return ans;
}

// Driver code
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    power[0] = 1;
    powersum[0] = 1;
    powersum[1] = 3;
    for (int i = 1; i < 31; i++)
    {
        power[i] = power[i - 1] * 2;
        //cout<<power[i]<<" ";
    }
    for (int i = 2; i < 30; i++)
    {
        powersum[i] = power[i + 1] - 1;
    }

    powersum[30] = power[30] * 2 - 1;

    preCompute(arr, n);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << minimumADD(l - 1, r - 1) << endl;
    }
    /*
    for(int i=0;i<31;i++){
        for(int j=0;j<n;j++)
        {
          cout<<myFunction[i][j]<<" ";
        }
      cout<<endl;
    }*/
    return 0;
}