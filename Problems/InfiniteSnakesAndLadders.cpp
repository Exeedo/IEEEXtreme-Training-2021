// Problem link: https://csacademy.com/ieeextreme-practice/task/infinite-snakes-and-ladders/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=2e6+5;
bool startingPoint[N];

// size of the board
long long boardSize;

// position of each player
long long pos[10];

int lastIndex = 0;
map<long long, int> ind; // index for each position (because the positions can be too big)
map<int, long long> inv; // position for each index (the inverse of the previous map)

// a map to store where each position ends up after all snakes and ladders starting from that point
map<long long, long long> reachAt;

// the graph representing the board
vector<int> g[N]; 

// an array to check whether each player has won the game
bool win[10];

// find the coordinates of the position:
pair<int,int> findCoordinates(long long position){
    pair<int,int> answer = { 0,0 };
    if(position == 0) {
        return answer;
    }
    
    answer.first  = 1 + (position - 1) % boardSize;
    answer.second = 1 + (position - 1) / boardSize;
    
    // odd and even rows are flipped
    if(answer.second % 2 == 0) {
        answer.first = boardSize + 1 - answer.first;
    }
    return answer;
}

// find the position from the coordinates
long long findPosition(long long x,long long y){
    long long position = (y - 1) * boardSize;
    if(y%2 == 1){
        position += x;
    }
    else {
        // odd and even rows are flipped
        position += boardSize - x + 1;
    }
    return position;
}

// this function will find where each point that has a ladder or snakes ends up at
void bfs(){
    for(int i = 1; i <= lastIndex; i++){
        // start only from ending points and move in reverse
        // because all points leading to an ending point will end in that point
        if(!startingPoint[i]) {
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                
                // position at u will end up at the position at i
                reachAt[inv[u]] = inv[i];
                
                for(int v:g[u]) {
                    // position at v will also end up at the position at i
                    reachAt[inv[v]] = inv[i];
                    q.push(v);
                }
            }
        }
    }
}

// read and store the snakes and ladders as directed edges
void read(int x){
    for(int i = 0; i < x; i++) {
        long long position[2];
        for(int j = 0; j < 2; j++) {
            int a, b;
            cin >> a >> b;
            position[j] = findPosition(a,b);
            
            // give each position a new index
            if(ind[position[j]] == 0) {
                ind[position[j]] = ++lastIndex;
                inv[lastIndex] = position[j];
            }
        }
        // add the edge inverted (check bfs() function)
        g[ind[position[1]]].push_back(ind[position[0]]);
        // mark the first point as a starting point
        startingPoint[ind[position[0]]] = 1;;
    }
}

int main() {
    int players;
    cin >> boardSize >> players;
    int s,l; // number of snakes and ladders
    cin >> s;
    read(s);
    cin >> l;
    read(l);
    
    bfs();
    memset(win,0,sizeof win);
    memset(pos,0,sizeof pos);
    
    int rolls;
    cin >> rolls;
    int currentPlayer = 0, wins = 0;
    while(rolls--) {
        int a,b;
        cin >> a >> b;
        int d = a + b;
        
        // increase the position of the player
        pos[currentPlayer] += d;
        
        // check for snakes and ladders
        if(ind[pos[currentPlayer]] != 0) {
            pos[currentPlayer] = reachAt[pos[currentPlayer]];
        }
        
        // check for winning the game
        if(pos[currentPlayer] > boardSize * boardSize) { 
            win[currentPlayer] = 1;
            wins++;
        }
        
        // if all players won, the game is finished
        if(wins==players) {
            break;
        }
        
        // move to the next player that did not win already
        do {
            currentPlayer = (currentPlayer+1)%players;
        } while(win[currentPlayer]);
    }
    
    // Print the position of each player or state that they have won
    for(int i = 0; i < players; i++){
        cout << i+1 << ' ';
        if(win[i]) {
            cout << "winner" << endl;
        }
        else {
            pair<int,int> coordinates = findCoordinates(pos[i]);
            cout << coordinates.first << ' ' << coordinates.second << endl;
        }
    }
    return 0;
}
