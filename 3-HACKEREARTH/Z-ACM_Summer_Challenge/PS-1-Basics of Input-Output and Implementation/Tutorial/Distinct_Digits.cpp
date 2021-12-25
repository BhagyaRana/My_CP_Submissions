#include <bits/stdc++.h>
using namespace std;

void printUnique(int l, int r)
{
    int num;
    for (int i = l; i <= r; )
    {
        num = i;
        bool visited[10] = {false};
        while (num)
        {
            if (visited[num % 10])
                {break;}

            visited[num % 10] = true;

            num = num / 10;
        }

        if (num == 0)
        {
            cout << i << "\n";
            return;
        }
        else{
            i++;
        }
    }
    cout<<-1<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l, r;
    cin >> l >> r;
    printUnique(l, r);
    return 0;
}