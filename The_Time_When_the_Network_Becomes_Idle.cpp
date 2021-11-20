#include<bits/stdc++.h>
using namespace std;

int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
	int n = patience.size(), ans = 0;

	vector<vector<int>> graph(n);
	vector<int> dist(n,INT_MAX);
	queue<int> q;

	for (vector<int> e : edges) {
		int u = e[0], v = e[1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	q.push(0);
	dist[0] = 0;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int child : graph[node]) {
			if (dist[child] == INT_MAX) dist[child] = dist[node] + 1;
		}
	}

	for (int i = 1; i < n; ++i) {
		int extraMessages = (2 * dist[i] - 1) / patience[i];
		int lastOut = extraMessages * patience[i];
		int lastIn = lastOut + 2 * dist[i];
		ans = max(ans, lastIn + 1);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> edges;
		vector<int> patience(n);

		while (m--) {
			int a, b;
			cin >> a >> b;
			edges.push_back({ a,b });
		}

		for (int i = 0; i < n; ++i) cin >> patience[i];

		cout << networkBecomesIdle(edges, patience) << endl;
	}

	return 0;
}
