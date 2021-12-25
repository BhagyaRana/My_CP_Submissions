#include<iostream>
using namespace std;

void print(int mat[][9]) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool canPlace(int no, int x, int y, int mat[][9]) {

    ///Check for row
    for (int i = 0; i < 9; i++) {
        if (mat[x][i] == no) {
            return false;
        }
    }
    ///Check for col
    for (int j = 0; j < 9; j++) {
        if (mat[j][y] == no) {
            return false;
        }
    }
    ///Check for subgrid
    int sx = (x / 3) * 3;
    int sy = (y / 3) * 3;

    for (int i = sx; i < sx + 3; i++) {
        for (int j = sy; j < sy + 3; j++) {
            if (mat[i][j] == no) {
                return false;
            }

        }
    }
    return true;
}
bool solveMySudoku(int mat[][9], int i, int j, bool marked[][9]) {
    if (i == 9) {

        return true;
    }
    ///jump to next row
    if (j == 9) {
        return solveMySudoku(mat, i + 1, 0, marked);
    }
    if (marked[i][j] == false) {
        ///Try Placing a No
        for (int no = 1; no <= 9; no++) {
            if (canPlace(no, i, j, mat) == true) {
                mat[i][j] = no;
                bool solveHoPaega = solveMySudoku(mat, i, j + 1, marked);
                if (solveHoPaega) {
                    return true;
                }
            }
        }
        mat[i][j] = 0;
        return false;
    }
    else {
        return solveMySudoku(mat, i, j + 1, marked);
    }


}


int main() {


    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };


    bool marked[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (mat[i][j]) {
                marked[i][j] = true;
            }
            else {
                marked[i][j] = false;
            }
        }
    }
    print(mat);
    solveMySudoku(mat, 0, 0, marked);
    print(mat);


    return true;
}