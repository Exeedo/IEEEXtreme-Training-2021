#include <bits/stdc++.h>
using namespace std;

int n, s, f , d;

struct star{
    int start, finish, score;
};

vector<star> stars;

bool sort_stars(star &a, star &b){
    return a.start < b.start;
}

int dp[10010][1005];

int find_answer(int idx, int finish_time){
    if(idx == n){
        return 0;
    }
    if (dp[idx][finish_time] != -1){
        return dp[idx][finish_time];
    }
    int ans = 0;
    int option1 = find_answer(idx + 1, finish_time + 0) + 0; // try not to attend this event
    int option2 = 0;
    if (stars[idx].start > finish_time) {
        option2 = find_answer(idx + 1, stars[idx].finish)    // try to attend this event
                    + stars[idx].score;
    }
    ans = max(option1, option2);
    return dp[idx][finish_time] = ans;
}


int main() {
    cin >> n;
    stars.resize(n);
    for(star &S:stars){
        cin >> S.start >> S.finish >> S.score;
        S.start++;
        S.finish++;
    }
    
    sort(stars.begin(), stars.end(), sort_stars); // O(N*log(N))
    memset(dp, -1, sizeof(dp));
    cout << find_answer(0, 0) << endl;
}

/*

1: 0 10 10
2: 1 4 6
3: 7 9 6

*/
