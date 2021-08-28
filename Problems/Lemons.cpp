// Problem link: https://csacademy.com/ieeextreme-practice/task/lemons/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int n , m , s;

int LOG2(int x){
    int ans=0;
    while( x != 0 ){
        ans++;
        x = x/2;
    }
    return ans;
}

int main() {
    cin >> n >> m >> s;
    cout << s*LOG2(n-1) // Total checking time
            + m*(n-1); // Total travelling time
    return 0;
}
