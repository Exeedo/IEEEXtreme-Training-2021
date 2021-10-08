// Problem link: https://csacademy.com/ieeextreme-practice/task/alfa-pool/
// By: Osama Khallouf

// This solution uses Bottom-Up approach to calculate the answers of dynamic programming states
#include <bits/stdc++.h>
using namespace std;

long long MD = 1e9+7;
long long dp[100010];

int main() {
    // This part is similar to (cal) function in the Top-Down approach 
    dp[0]=1;
    for(int i=1;i<100010;i++){
        for(int j=1; j<=i; j = 2*j+1){
            dp[i] += dp[i-j];
            dp[i] %= MD;
        }
    }
    
    // This part is similar to (solve) function in the Top-Down approach 
    for(int i=1;i<100010;i++){
        dp[i] = (2*dp[i]) % MD;
    }
    
    // This part is similar to the Top-Down approach
    int n,b;
    cin >> n;
    while(n--){
        cin >> b;
        cout << dp[b] << endl;
    }
    return 0;
}
