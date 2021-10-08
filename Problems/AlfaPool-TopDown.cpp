// Problem link: https://csacademy.com/ieeextreme-practice/task/alfa-pool/
// By: Osama Khallouf

// This solution uses Top-Down approach to calculate the answers of dynamic programming states
#include <bits/stdc++.h>
using namespace std;

long long MD = 1e9+7;
long long dp[100010];

long long cal(int x){
    if(x==0) return 1;
    if(dp[x]!=0){
        return dp[x];
    }
    long long answer = 0;
    for(int i=1; i<=x; i = 2*i+1){
        answer += cal(x-i);
        answer %= MD;
    }
    dp[x] = answer;
    return answer;
}

long long solve(int x){
    if(x==0) return 1;
    long long answer = cal(x);
    answer = (2*answer)%MD;
    return answer;
}

int main() {
    int n,b;
    cin >> n;
    while(n--){
        cin >> b;
        cout << solve(b) << endl;
    }
    return 0;
}
