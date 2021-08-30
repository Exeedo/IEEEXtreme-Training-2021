#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 20;
vector<int> adj[N];

int n, e;
bool visited[N];
vector<vector<int>> connected_components;

void DFS(int u) {
	visited[u] = true;
	connected_components.back().push_back(u);
	for (int v : adj[u]) {
		if (visited[v])
			continue;
		DFS(v);
	}
	return;
}

int main() {
	FILE* in_file, * out_file;
	freopen_s(&in_file, "input.txt", "r", stdin);
	freopen_s(&out_file, "output.txt", "w", stdout);
	
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (!visited[i]) {
			connected_components.push_back({});
			DFS(i);
		}

	for (vector<int> x : connected_components) {
		cout << "There are " << x.size() << " node in this component: ";
		for (int u : x) {
			cout << u << ' ';
		}
		cout << endl;
	}
}
