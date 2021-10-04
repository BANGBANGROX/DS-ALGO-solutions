#include<bits/stdc++.h>
using namespace std;

vector<int> graph[500005];
vector<bool> vis, color;

bool isBipartiteUtil(int node) {
	vis[node] = 1;

	for (int child : graph[node]) {
		if (vis[child]) {
			if (color[node] == color[child]) return false;
			continue;
		}
		color[child] = !color[node];
		if (!isBipartiteUtil(child)) return false;
	}

	return true;
}

bool isBipartite(int n, vector<int>* adj) {
	vis.resize(n);
	color.resize(n);
	for (int i = 0; i < n; ++i) {
		vis[i] = 0;
		color[i] = 0;
		graph[i] = adj[i];
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i] && !isBipartiteUtil(i)) return false;
	}

	return true;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<int>* adj = new vector<int>[n];
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool res = isBipartite(n, adj);

		if (res) cout << "Bipartite graph\n";
		else cout << "Not Bipartite graph\n";
	}

	return 0;
}