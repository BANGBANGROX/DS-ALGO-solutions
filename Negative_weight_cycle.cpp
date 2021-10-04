#include<bits/stdc++.h>
using namespace std;

int isNegativeWeightCycle(int n, vector<vector<int>>edges) {
	vector<int> dist(n, INT_MAX);
	int m = edges.size();
	dist[0] = 0;
	
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int u = edges[j][0];
			int v = edges[j][1];
			int w = edges[j][2];
			if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		if (dist[v] > dist[u] + w) return true;
	}

	return false;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> edges(m, vector<int>(3));

		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			edges[i] = { u,v,w };
		}

		cout << isNegativeWeightCycle(n, edges) << endl;
	}

	return 0;
}