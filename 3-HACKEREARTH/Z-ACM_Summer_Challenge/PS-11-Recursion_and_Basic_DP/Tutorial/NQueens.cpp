#include <bits/stdc++.h>
using namespace std;
#define endl 	"\n"

void b_v_r()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool IsSafe(int board[][10],int i,int j,int n)
{
    // Check For Column
    for(int row=0;row<n;row++)
    {
        if(board[row][j]==1)
            return false;
    }

    // Check for Left Diagonal 
    int x = i;
    int y = j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }

    // Check for Right Diagonal 
    x = i;
    y = j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }

    // Position is Safe if Control Reaches Here
    return true;
}

bool SolveNQueen(int board[][10], int i, int n)
{
    // Base Case
    if(i==n)
    {
        // You have Successfully Placed Queens in N Rows(0 .. n-1)
        cout << "YES" <<endl;
        // Print the Board
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true; // N Queen Prob Solved
    }

    // Recursive Case
    // Try to Place the Queen in Current Row
    // Call on Remaining Part which will be Solved by Recursion
    
    for(int j=0;j<n;j++) // Column Iteration
    {
        // Check (i,j) Position is Safe for Queen
        if(IsSafe(board,i,j,n))
        {
            // Place the Queen - Assuming (i,j) is Right
            board[i][j] = 1;

            bool NextQueenRakh = SolveNQueen(board,i+1,n); // Next Row
            if(NextQueenRakh)
            {
                return true;
            }
            // Control Reach Here -> (i,j) is not Right Position
            // Assumption is Wrong
            board[i][j] = 0;
        }
    }
    // You tried for all Positions in Current Row but Couldn't Place Queen
    return false;
}

int main()
{
    b_v_r();

    int n;
    cin >> n;

    int board[10][10] = {0};

    bool ans = SolveNQueen(board,0,n);

    if(ans==false)
    {
        cout << "NO" << endl;
    }
    
    return 0;
}
