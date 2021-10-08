// Problem link: https://csacademy.com/ieeextreme-practice/task/ed8629419f140a5a2c923b049aba1224/
// By: Osama Khallouf

#include<bits/stdc++.h>
using namespace std;


int t,c,n;
vector <int> w, f;

int dp[205][505];

int cal(int idx, int capacity_left){ // returns the maximum fighting power within capacity limits
    if(capacity_left < 0){
        return -1e9;
    }
    if(idx >= n ){
        return 0;
    }
    if(capacity_left == 0){
        return 0;
    }
    if(dp[idx][capacity_left] != -1){
        return dp[idx][capacity_left];
    }
    int answer;
    answer = cal(idx+1, capacity_left - w[idx]) + f[idx]; // try to take this element
    answer = max(answer, cal(idx+1, capacity_left) + 0);  // try not to take this element
    dp[idx][capacity_left] = answer;
    return answer;
}


int main(){
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin >> c >> n;
        w.resize(n);
        f.resize(n);
        for(int i=0;i<n;i++){
            cin >> w[i] >> f[i];
        }
        cout << cal(0, c) << endl; // starting from index 0 with full capacity (c)
    }
    return 0;
}
