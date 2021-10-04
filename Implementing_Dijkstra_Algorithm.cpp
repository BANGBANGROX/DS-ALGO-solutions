#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<int>>* adj, int s) {
	vector<int> dist(n, INT_MAX);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[s] = 0;
	pq.push({ 0,s });

	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		pq.pop();
		int node = top.second, distance = top.first;
		for (vector<int> x : adj[node]) {
			int child = x[0];
			int weight = x[1];
			if (dist[child] > dist[node] + weight) {
				dist[child] = dist[node] + weight;
				pq.push({ dist[child],child });
			}
		}
	}

	return dist;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, s;
		cin >> n >> m >> s;
		vector<vector<int>>* adj = new vector<vector<int>>[n];
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ v,w });
			adj[v].push_back({ u,w });
		}

		vector<int> dist = dijkstra(n, adj, s);
		for (int x : dist) cout << x << " ";
		cout << endl;
	}

	return 0;
}