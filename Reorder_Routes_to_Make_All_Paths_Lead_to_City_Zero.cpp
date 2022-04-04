#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minReorder(int n, vector<vector<int>>& connections) {
		vector<vector<int>> graph(n);
		vector<vector<int>> reverseGraph(n);
		queue<int> q;
		vector<bool> visited(n);
		int ans = 0;

		for (const vector<int>& edge : connections) {
			int u = edge[0];
			int v = edge[1];
			graph[u].push_back(v);
			reverseGraph[v].push_back(u);
		}

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int child : graph[node]) {
				if (!visited[child]) {
					++ans;
					visited[child] = true;
					q.push(child);
				}
			}
			for (int child : reverseGraph[node]) {
				if (!visited[child]) {
					visited[child] = true;
					q.push(child);
				}
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		vector<vector<int>> connections(m, vector<int>(2));
		for (int i = 0; i < m; ++i) {
			cin >> connections[i][0] >> connections[i][1];
		}

		Solution solution;
		cout << solution.minReorder(n, connections);
	}

	return 0;
}