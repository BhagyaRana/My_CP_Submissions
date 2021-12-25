#include <bits/stdc++.h>

using namespace std;

void b_v_r()
{
    // ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int MAX = 62;
int a[62][62];
void print(int arr[][MAX], int n)
{
    cout << "2" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    b_v_r();
    // COVID SAMPLING
    // T = 2
    int t;
    cin >> t;
    while (t--)
    {
        int n, p; //N = 60 Q = 18000 = 5*(N^2)
        cin >> n >> p;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << "1 " << i << " " << j << " " << i << " " << j << endl;
                cin >> ans;
                a[i][j] = ans;
            }
        }
        print(a, n);
        int x;
        cin >> x; //No. Of Infected People
        // x = -1 -> Invalid Query/>Q Queries
        if (x == -1)
        {
            exit(2);
            cout << "Invalid Query" << endl;
        }

        // --- Queries  Over ---
        // cout << "2" << endl;
        // Print A(i,1), A(i,2)..A(i,N) ; 1<=i<=N

        // Final X
        // If Matrix A is Correct X=1 -> Solve Next Test Case

        // If X = -1 Incorrect
        // If X = -1 Recieved -> Terminate Your Program
    }

    return 0;
}
