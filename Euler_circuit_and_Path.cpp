// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	void dfs(int node, vector<int> graph[], vector<bool>& visited) {
		visited[node] = true;

		for (int child : graph[node]) {
			if (!visited[child]) dfs(child, graph, visited);
		}
	}

public:
	int isEularCircuit(int n, vector<int> graph[]) {
		// Code here
		vector<bool> visited(n);
		int oddDegree = 0;
		int source = -1;

		for (int i = 0; i < n; ++i) {
			if ((int)graph[i].size() > 0) {
				source = i;
				break;
			}
		}

		dfs(source, graph, visited);

		for (int i = 0; i < n; ++i) {
			if (!visited[i] && (int)graph[i].size() > 0) return 0;
			if (((int)graph[i].size() & 1) > 0) ++oddDegree;
		}

		if (oddDegree == 0) return 2;

		if (oddDegree == 2) return 1;

		return 0;
	}
};

// { Driver Code Starts.
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int V, E;
		cin >> V >> E;
		vector<int>* adj = new vector<int>[V];
		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends