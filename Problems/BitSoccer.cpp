// Problem link: https://csacademy.com/ieeextreme-practice/task/crafting-wooden-tables/
// By: Osama Khallouf

#include <iostream>
#include <vector>
using namespace std;

int N, Q;
vector<long long> players;

bool can(long long g) {
    // Step 1: exculde some players
    vector<long long> potential_players;
    for(long long p:players){
        if((p&g) == p){
            potential_players.push_back(p);
        }
    }
    
    // Step 2: create team from all potential_players
    long long team = 0;
    for(long long p:potential_players){
        team |= p;
    }
    return team == g;
}

int main(){
    cin >> N;
    players.resize(N);
    for (int i=0; i<N; i++)
        cin >> players[i];
    cin >> Q;
    
    for (int i=0; i<Q; i++){
        long long g;
        cin >> g;
        cout << (can(g)?"YES":"NO") << endl;
    }
    
    return 0;
}

/*
10 := 0000 1010 X7 X4
 3 := 0000 0011    X4
 5 := 0000 0101    X4
 8 := 0000 1000 X7 X4
 6 := 0000 0110    X4
 
 7 := 0000 0111 YES
 4 := 0000 0100 NO
31 := 0001 1111 NO
15 := 0000 1111 YES
*/

