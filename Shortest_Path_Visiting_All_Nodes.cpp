#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int shortestPathLength(vector<vector<int>>& graph) {
		int n = graph.size();
		int steps = 0;
		int endMask = (1 << n) - 1;
		vector<vector<bool>> visited(n, vector<bool>(1 << n));
		queue<pair<int, int>> q;

		for (int i = 0; i < n; ++i) {
			q.push({ i,(1 << i) });
			visited[i][1 << i] = true;
		}

		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				pair<int, int> currentState = q.front();
				q.pop();
				int node = currentState.first;
				int mask = currentState.second;
				for (int child : graph[node]) {
					int nextMask = mask | (1 << child);
					if (nextMask == endMask) return 1 + steps;
					if (!visited[child][nextMask]) {
						q.push({ child,nextMask });
						visited[child][nextMask] = true;
					}
				}
			}
			++steps;
		}

		return 0;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> graph(n);
		for (int i = 0; i < n; ++i) {
			int m;
			cin >> m;
			for (int j = 0; j < m; ++j) {
				int x;
				cin >> x;
				graph[i].push_back(x);
			}
		}

		Solution solution;
		cout << solution.shortestPathLength(graph) << endl;
	}

	return 0;
}