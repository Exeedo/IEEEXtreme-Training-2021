// Problem link: https://csacademy.com/ieeextreme-practice/task/crafting-wooden-tables/
// By: Osama Khallouf

#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ll;
ll C, N, P, W;

/* C: Number of pieces of wood to make 1 table
 * N: Number of pockets available
 * P: Number of pieces of wood that can fit in a pocket
 * W: Total number of pieces of wood available
 */

int main() {
    cin >> C >> N >> P >> W;
    ll answer = 0;
    
    ll lo = 0, hi = min(N, W/C);
    while(lo <= hi) {
        ll tables = (lo + hi)/2; // mid point
        ll required_wood = tables * C;
        ll wood_left = W - required_wood;
        ll pockets_needed = (wood_left + P-1) / P; // equ. to ceil (wood_left / P)
        if (pockets_needed + tables <= N){
            answer = tables;
            lo = tables + 1;
        }
        else{
            hi = tables - 1;
        }
    }
    
    cout << answer;
	return 0;
}

// N = 3M+0 => M 
// N = 3M+1 => M+1
// N = 3M+2 => M+1
