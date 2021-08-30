#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 20;
vector<int> adj[N];

int n, e;
int dist[N];
bool visited[N];

void BFS(int u) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 0;
		visited[i] = false;
	}

	queue<int> q;
	q.push(u); visited[u] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int w : adj[v]) {
			if (visited[w])
				continue;
			q.push(w); visited[w] = true;
			dist[w] = dist[v] + 1;
		}
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

	int s = 1;
	BFS(s);

	for (int i = 1; i <= n; i++) {
		cout << "Distance between source (1) and " << i << " = " << dist[i] << endl;
	}
}
