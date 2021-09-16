#include <iostream>
#include <vector>
using namespace std;

const int N = 100000;
const int K = 20;
vector<int> adj[N];

int par[N];
int ancestor[N][K]; // O(N*log(N))
int depth[N];

int n, e;

void DFS(int u) { // O(V+E)
	for (int v : adj[u]) {
		if (v == par[u])
			continue;
		par[v] = u;
		depth[v] = depth[u] + 1;
		DFS(v);
	}
}

int lca(int u, int v) {
	if (depth[v] > depth[u])
		swap(u, v);

	for (int k = K - 1; k >= 0; k--) {
		int a = ancestor[u][k];
		if (a == -1)
			continue;
		if (depth[a] < depth[v])
			continue;
		u = a;
	}
	if (u == v) {
		return u;
	}

	for (int k = K - 1; k >= 0; k--) {
		int au = ancestor[u][k];
		int av = ancestor[v][k];
		if (au == av) {
			continue;
		}
		else {
			u = au;
			v = av;
		}
	}
	return par[u]; // return ancestor[u][0];
}

int dist(int u, int v) {
	int l = lca(u, v);
	return (depth[u] - depth[l]) + (depth[v] - depth[l]);
}

int dist2(int u, int v) {
	if (depth[v] > depth[u])
		swap(u, v);
	int answer = 0;

	for (int k = K - 1; k >= 0; k--) {
		int a = ancestor[u][k];
		if (a == -1)
			continue;
		if (depth[a] < depth[v])
			continue;
		u = a;
		answer += (1 << k); // in math, equ. to [2 to the power k]
	}
	if (u == v) {
		return answer;
	}

	for (int k = K - 1; k >= 0; k--) {
		int au = ancestor[u][k];
		int av = ancestor[v][k];
		if (au == av) {
			continue;
		}
		else {
			u = au;
			v = av;
			answer += 1 << (k + 1);
		}
	}
	answer += 2;
	return answer;
}

int main(){
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int root = 0;
	par[root] = -1;
	depth[root] = 0;
	DFS(root);

	// Fill sparse table (ancestor)
	for (int i = 0; i < n; i++) {
		ancestor[i][0] = par[i];
	}

	for (int k = 1; k < K; k++) { // parent number (2^k)
		for (int i = 0; i < n; i++) {
			int mid_ancestor = ancestor[i][k - 1];
			if (mid_ancestor == -1)
				ancestor[i][k] = -1;
			else
				ancestor[i][k] = ancestor[mid_ancestor][k - 1];
		}
	}

	// Answering queries
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int u, v;
		cin >> u >> v;
		cout << dist(u, v) << endl;
	}
}
