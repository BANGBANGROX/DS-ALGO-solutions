#include<bits/stdc++.h>
using namespace std;

vector<bool> vis;
vector<int> low, disc;
vector<int> graph[10005];
vector<vector<int>> res;
int timer = 0;

void dfs(int node, int par) {
	vis[node] = 1;
	low[node] = disc[node] = ++timer;

	for (int child : graph[node]) {
		if (!vis[child]) {
			dfs(child, node);
			low[node] = min(low[node], low[child]);
			if (low[child] > disc[node]) {
				res.push_back({ node,child });
			}
		}
		else if (child != par) {
			low[node] = min(low[node], disc[child]);
		}
	}
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
	vis.resize(n);
	low.resize(n);
	disc.resize(n);
	timer = 0;
	res.clear();
	for (int i = 0; i < n; ++i) {
		graph[i].clear();
	}

	for (vector<int> x : connections) {
		graph[x[0]].push_back(x[1]);
		graph[x[1]].push_back(x[0]);
	}

	for (int i = 0; i < n; ++i) {
		if (!vis[i]) dfs(i, -1);
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> connections(m, vector<int>(2));

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			connections.push_back({ u,v });
		}

		vector<vector<int>> bridges = criticalConnections(n, connections);

		for (vector<int> x : bridges) {
			cout << x[0] << " " << x[1] << endl;
		}
	}

	return 0;
}