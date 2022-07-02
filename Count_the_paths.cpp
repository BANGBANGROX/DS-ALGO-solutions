// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	vector<vector<int>> graph;
	vector<bool> visited;
	int ans;
	int source;
	int destination;

	void countPaths(int node) {
		if (node == destination) {
			++ans;
			return;
		}

		visited[node] = true;

		for (int child : graph[node]) {
			if (!visited[child]) countPaths(child);
		}

		visited[node] = false;
	}

public:
	int possible_paths(vector<vector<int>>edges, int n, int s, int d) {
		// Code here
		graph = vector<vector<int>>(n);
		visited = vector<bool>(n);
		source = s;
		destination = d;
		ans = 0;

		for (vector<int>& edge : edges) {
			graph[edge[0]].push_back(edge[1]);
		}

		countPaths(source);

		return ans;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			edges.push_back({ u,v });
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends