#include<bits/stdc++.h>
using namespace std;

int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
	vector<vector<int>> graph(n);

	for (vector<int>& e : edges) {
		int u = e[0] - 1, v = e[1] - 1;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> dist(n, INT_MAX);
	queue<int> q;
	q.push(n - 1);
	dist[n - 1] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int child : graph[curr]) {
			if (dist[child] == INT_MAX) {
				dist[child] = dist[curr] + 1;
				q.push(child);
			}
		}
	}

	int len = dist[0] + 2;
	bool found = false;
	q.push(0);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int child : graph[curr]) {
			if (dist[child] == dist[curr]) {
				--len;
				found = true;
				break;
			}
			else if (dist[child] == dist[curr] - 1) {
				q.push(child);
			}
		}
		if (found) break;
	}

	int timer = 0;

	for (int i = 0; i < len; ++i) {
		if ((timer / change) % 2 == 1) {
			timer = (timer / change + 1) * change;
		}
		timer += time;
	}

	return timer;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m, time, change;
		cin >> n >> m >> time >> change;

		vector<vector<int>> edges;

		while (m--) {
			int u, v;
			cin >> u >> v;
			edges.push_back({ u,v });
		}

		cout << secondMinimum(n, edges, time, change) << endl;
	}

	return 0;
}