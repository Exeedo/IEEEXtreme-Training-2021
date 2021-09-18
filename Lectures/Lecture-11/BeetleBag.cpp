// Problem link: https://csacademy.com/ieeextreme-practice/task/ed8629419f140a5a2c923b049aba1224/
// By: Osama Khallouf

#include<bits/stdc++.h>
using namespace std;

int t, c, n, w , f;
vector<pair<int,int>> gadgets;
int dp[205][505];

int choose(int idx, int weight){ // returns f
    if(idx == n)
        return 0;
    if(dp[idx][weight] != -1){
        return dp[idx][weight];
    }
    int ans;
    int ans1 = choose(idx+1, weight + 0) + 0;               // try not to select this item
    int ans2 = 0;
    if (weight + gadgets[idx].first <= c)
        ans2 = choose(idx+1, weight + gadgets[idx].first)   // try to select this item
                + gadgets[idx].second;
    ans = max(ans1, ans2);
    return dp[idx][weight] = ans;
}

int main(){
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> c >> n;
        gadgets.resize(n);
        for(int i=0;i<n;i++){
            cin >> w >> f;
            gadgets[i] = {w,f};
        }
        auto x = choose(0, 0);
        cout << x << endl;
    }
    return 0;
}


/*
c = 50
100 50
80 25
60 25
*/

/*

1: 
2:
3:

{{}, {1}, {2}, {3}, {1,2}, {1,3}, {2,3}, {1,2,3}}



1:
2:

{-,-},{-,2}, 
{1,-},{1,2} 
*/
