#include <bits/stdc++.h>
using namespace std;


/*
Return the row and column index
of the largest element in the
2d matrix recursively
*/
vector<int> FindMatrixMax(int i, int j, vector<vector<int>> a, vector<int> mx, int rowMx, int colMx) {
    if (i == a.size()) 
        return {rowMx,colMx};
    
    cout << a[i][j] << '\n';
    if (a[i][j] > a[rowMx][colMx]) {
        rowMx = i;
        colMx = j;
    }
    if (j+1 < a[i].size()) // continue moving to the next element
        return FindMatrixMax(i,j+1,a,mx,rowMx,colMx);

    return FindMatrixMax(i+1,0,a,mx,rowMx,colMx);
}

int main() {
    vector<vector<int>> a = {{1,33,7}, {8,10,6}};
    vector<int> mx;
    mx = FindMatrixMax(0,0,a,mx,0,0);
    cout << mx[0] << " " << mx[1] << " " << a[mx[0]][mx[1]] << '\n';
}