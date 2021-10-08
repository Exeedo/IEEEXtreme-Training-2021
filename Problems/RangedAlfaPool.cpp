// Problem link: https://csacademy.com/ieeextreme-practice/task/ranged-alfa-pool/
// By: Osama Khallouf

// This problem is very similar to the problem Alfa Pool in Session 5. Make sure to check it before solving this.

// This solution must use Bottom-Up approach to calculate the answers of dynamic programming states
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+6;

long long MD = 1e9+7;
long long dp[N];
long long sum[N];

int main() {
    dp[0]=1;
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= i; j = 2*j+1){
            dp[i] += dp[i-j];
            dp[i] %= MD;
        }
    }
    
    for(int i = 1; i < N; i++){
        dp[i] = (2*dp[i]) % MD;
    }
    
    // This part is the difference between this problem and Alfa Pool problem
    for(int i = 1; i < N; i++){
        // sum[0] should be 0, so sum[i] = summation of dp[0]->dp[i-1]
        sum[i] = sum[i-1] + dp[i-1];
    }
    
    int n,a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        // sum[i] = summation of dp[0]->dp[i-1]
        long long answer = (sum[b+1] - sum[a])%MD;
        if(answer < 0) {
            answer += MD;
        }
        cout << answer << endl;
    }
    return 0;
}
