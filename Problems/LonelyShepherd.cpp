// Problem link: https://csacademy.com/ieeextreme-practice/task/lonely-shepherd
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

int n,k;
const int N=100010;
vector<int> g[N];
int par[N];
int sub[N];
bool found;
bool flipSubtree;
pair<int, int > cut;

int dfs(int u){ // returns the number of elements in the subtree
    int answer = 1;
    for(int v:g[u]){
        if(v==par[u]) continue;
        par[v]=u;
        answer += dfs(v);
    }
    sub[u]=answer;
    if(sub[u]==k){
        cut={u,par[u]};
        found=1;
        flipSubtree=1;
    }
    else if(sub[u]==n-k){
        cut={u,par[u]};
        found=1;
        flipSubtree=0;
    }
    
    return answer;
}

void dfs2(int u,int p){
    cout << "flip " << u << endl;
    for(int v:g[u]){
        if(v!=p){
            dfs2(v,u);
        }
    }
}


int main() {
    cin >> n >> k;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    par[1]=-1;
    dfs(1);
    if(found){
        if(flipSubtree){
            dfs2(cut.first, cut.second);
        }
        else{
            dfs2(cut.second, cut.first);
        }
        cout << "cut " << cut.first << ' ' << cut.second << endl;
    }
    else{
        cout << "-1";
    }
    return 0;
}
