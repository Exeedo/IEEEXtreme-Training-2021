#include <iostream>
#include <vector>
using namespace std;

const int N = 20;
vector<int> adj[N];
int par[N];
int n, e;
int counter = 0;
int idx[N];
int subtree[N];
int score[N];

void dfs(int u) {
	idx[u] = counter++;
	subtree[u] = 1;
	for (int v : adj[u]) {
		if (v == par[u])
			continue;
		par[v] = u;
		dfs(v);
		subtree[u] += subtree[v];
	}
}

void dfs2(int u, int added_score) {
	score[u] += added_score;
	for (int v : adj[u]) {
		if (v == par[u])
			continue;
		dfs2(v, added_score);
	}
}

int partial[N];

int main() {

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	par[0] = -1;
	dfs(0);

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int subroot, added_score;
		cin >> subroot >> added_score;
		// dfs2(subroot, added_score);
		partial[idx[subroot]] += added_score;
		partial[idx[subroot] + subtree[subroot]] -= added_score;
	}

	for (int i = 1; i < N; i++) {
		partial[i] += partial[i - 1];
	}
}
