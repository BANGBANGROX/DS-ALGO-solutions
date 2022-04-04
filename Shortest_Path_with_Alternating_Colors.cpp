#include<bits/stdc++.h>
using namespace std;

class Solution {
	struct Node {
		int value;
		int length;
		int previousColor;

		Node(int value, int length, int previousColor) {
			this->value = value;
			this->length = length;
			this->previousColor = previousColor;
		}
	};

public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
		// Normal q -> size -> node -> child -> distance
		// Problem q -> size -> (node, color) -> (child, color) -> distance
		// node -> value, length, previousColor

		vector<int> ans(n, -1);
		vector<vector<bool>> visited(n, vector<bool>(2));
		vector<vector<pair<int, int>>> graph(n);
		queue<Node> q;

		for (const vector<int>& edge : redEdges) {
			int u = edge[0];
			int v = edge[1];
			graph[u].push_back({ v,0 }); // 0 for red edge
		}

		for (const vector<int>& edge : blueEdges) {
			int u = edge[0];
			int v = edge[1];
			graph[u].push_back({ v,1 }); // 1 for blue edge
		}

		q.push(Node(0, 0, -1));
		visited[0][1] = true;
		visited[0][0] = true;
		ans[0] = 0;

		while (!q.empty()) {
			int node = q.front().value;
			int length = q.front().length;
			int previousColor = q.front().previousColor;
			q.pop();
			if (ans[node] == -1) ans[node] = length;
			for (const pair<int, int>& childNode : graph[node]) {
				int child = childNode.first;
				int color = childNode.second;
				if (color != previousColor && !visited[child][color]) {
					visited[child][color] = true;
					q.push(Node(child, length + 1, color));
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
		vector<vector<int>> redEdges(m, vector<int>(2));
		for (int i = 0; i < m; ++i) {
			cin >> redEdges[i][0] >> redEdges[i][1];
		}
		cin >> m;
		vector<vector<int>> blueEdges(m, vector<int>(2));
		for (int i = 0; i < m; ++i) {
			cin >> blueEdges[i][0] >> blueEdges[i][1];
		}

		Solution solution;
		vector<int> ans = solution.shortestAlternatingPaths(n, redEdges, blueEdges);
		for (int& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}