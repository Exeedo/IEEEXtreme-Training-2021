// Problem link: https://csacademy.com/ieeextreme-practice/task/bd45c86a844acd8ffc58b6a965cb0197/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

bool grid[1005][1005];
bool vis[1005][1005];
int w,h;

// direction arrays:
//       [first brush]  [second one]
int dx[]={1,-1, 0, 0,   +1,+1,-1,-1};
int dy[]={0, 0, 1,-1,   +1,-1,+1,-1};
//      [all of them in third brush] 

void bfs(int x,int y, int startIndex, int endIndex){
    // process of (x,y) node
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
        for(int i=startIndex; i<endIndex; i++){
            int newX=x+dx[i];
            int newY=y+dy[i];
            // checking (newX,newY) node
            /* if we read the grid as 1-indexed and increase its size by 2 or more, we can skip these checkings
            if(newX<0) continue;
            if(newY<0) continue;
            if(newX>=h) continue;
            if(newY>=w) continue;
            */
            
            if(vis[newX][newY]) continue;
            if(grid[newX][newY] == 0) continue;
            q.push({newX,newY});
            vis[newX][newY] = 1;
        }
    }
}

void solve(){
    memset(grid,0,sizeof(grid));
    memset(vis,0,sizeof(vis));
    cin >> w >> h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            char c;
            cin >> c;
            grid[i][j]=(c=='1');
        }
    }
    
    int answer=0;
    
    // process of + brush
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j] && !vis[i][j]){ // if true
                bfs(i,j,0,4);
                answer++;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    cout << answer << ' ';
    answer = 0;
    
    
    // process of x brush
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j] && !vis[i][j]){ // if true
                bfs(i,j,4,8);
                answer++;
            }
        }
    }
    memset(vis,0,sizeof(vis));
    cout << answer << ' ';
    answer = 0;
    
    // process of * brush
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(grid[i][j] && !vis[i][j]){ // if true
                bfs(i,j,0,8);
                answer++;
            }
        }
    }
    cout << answer << '\n'; // endl
}


int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
