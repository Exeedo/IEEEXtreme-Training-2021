// Problem link: https://csacademy.com/ieeextreme-practice/task/tree-fun
// By: Osama Khallouf

#include <bits/stdc++.h>
using namespace std;

const int N=100010;
vector<int> g[N];
int par[N][20]; // sparse table
int depth[N];
int n,m;
long long score[N];

void fillSparseTable(){
    for(int p=1;p<20;p++){
        for(int i=0;i<n;i++){
            int midPar=par[i][p-1];
            if(midPar==-1){
                par[i][p]=-1;
            }
            else {
                par[i][p]=par[midPar][p-1];
            }
        }
    }
}

void dfs(int u){
    for(int v:g[u]){
        if(v==par[u][0]) continue;
        depth[v]=depth[u]+1;
        par[v][0]=u;
        dfs(v);
    }
}

int lca(int u,int v){
    int answer;
    if(depth[u]<depth[v]) swap(u,v); // now u has higher depth or equal
    for(int i=19;i>=0;i--){
        int p=par[u][i];
        if(p==-1) continue;
        if(depth[p]>=depth[v])
            u=p;
    }
    if(u==v){
        return v;
    }
    for(int i=19;i>=0;i--){
        int parU = par[u][i];
        int parV = par[v][i];
        if(parU!=parV){
            u=parU;
            v=parV;
        }
    }
    return par[u][0];
}

bool sortDepth(int a,int b){
    return depth[a]<depth[b];
}

int main() {
    memset(score,0,sizeof(score));
    cin >> n >> m;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depth[0]=1;
    par[0][0]=-1;
    dfs(0);
    fillSparseTable();
    for(int i=0;i<m;i++){
        int a,b,k;
        cin >> a >> b >> k;
        int ancestor=lca(a,b);
        score[a]+=k;
        score[b]+=k;
        score[ancestor]-=k;
        if(par[ancestor][0]!=-1)
            score[par[ancestor][0]]-=k;
    }
    
    vector<int> nodes(n);
    for(int i=0;i<n;i++)
        nodes[i]=i;
    sort(nodes.begin(),nodes.end(),sortDepth);
    
    for(int i=nodes.size()-1;i>=0;i--){
        int u=nodes[i];
        int p=par[u][0];
        if(p==-1) continue;
        score[p]+=score[u];
    }
    
    long long answer=0;
    for(int i=0;i<n;i++){
        answer=max(answer,score[i]);
    }
    cout << answer;
    return 0;
}
