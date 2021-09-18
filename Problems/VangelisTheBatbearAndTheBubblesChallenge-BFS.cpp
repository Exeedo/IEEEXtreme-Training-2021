// Problem link: https://csacademy.com/ieeextreme-practice/task/979a09a0cd8c4e98dd0a690f39a55bd2/
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=1005;
vector<int> g[N];
bool vis[N];
int par[N];

int bfs(int u){ // O(V+E), V: number of vertices, E: number of edges
    queue<int> q;
    q.push(u);
    vis[u]=true;
    par[u]=-1;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int x:g[v]){ // equivalent to {for(int i=0;i<g[v].size();i++) int x=g[v][i]}
            if(par[v]==x)
                continue;
            par[x]=v;
            if(vis[x]){
                return 1;
            }
            vis[x]=1;
            q.push(x);
        }
    }
    return 0;
}

int solve(){
    int n,e;
    cin >> n >> e;
    for(int i=0;i<n;i++){
        g[i].clear();
    }
    memset(vis,0,sizeof(vis));
    memset(par,-1,sizeof(par));
    bool cycle = 0;
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        if(a==b)
            cycle = 1;
    }
    for(int i=0;i<n;i++){ // O(N log N), N = E+V
        sort(g[i].begin(),g[i].end());
        for(int j=1;j<g[i].size();j++){
            if(g[i][j]==g[i][j-1]){
                cycle =1;
            }
        }
    }
    if(cycle){
        return 1;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cycle = bfs(i);
            if(cycle)
                return 1;
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cout << solve() << endl;
    }
    return 0;
}
