// Problem link: https://csacademy.com/ieeextreme-practice/task/e610aba28810ebcf2d3998692269b5a0/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=205;
int grid[N][N], health[N][N];

int main() {
    int r,c;
    cin >> r >> c;
    for(int i = 1; i <= r; i++) { 
        for(int j = 1; j <= c; j++) {
            cin >> grid[i][j];
            health[i][j] = 1e9; // initialize the health array
        }
    }
    
    health[r][c] = 1;
    
    for(int i = r; i > 0; i--) {
        for(int j = c; j > 0; j--) {
            health[i-1][j] = max(1, min(health[i-1][j],
                                        health[i][j] - grid[i-1][j]));
            health[i][j-1] = max(1, min(health[i][j-1],
                                        health[i][j] - grid[i][j-1]));
        }
    }
    cout << health[1][1] << endl;
    return 0;
}
