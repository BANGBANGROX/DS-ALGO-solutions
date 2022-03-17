// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/

#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	vector<ll> dijkstra(int n, vector<vector<pair<int,int>>>& graph, int src) {
		vector<ll> distance(n, LONG_MAX);
		set<pair<ll, int>> s;

		distance[src] = 0;
		s.insert({ 0,src });

		while (!s.empty()) {
			pair<int, int> currentNode = *s.begin();
			int node = currentNode.second;
			int dist = currentNode.first;
			s.erase(currentNode);
			for (pair<int,int>& childNode : graph[node]) {
				int child = childNode.first;
				int weight = childNode.second;
				if (distance[child] > distance[node] + weight) {
					if (s.find({ distance[child],child }) != s.end()) 
						s.erase({ distance[child],child });
					distance[child] = distance[node] + weight;
					s.insert({ distance[child],child });
				}
			}
		}

		return distance;
	}

public:
	ll minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
		vector<vector<pair<int, int>>> graph(n);
		vector<vector<pair<int, int>>> reversedGraph(n);

		for (const vector<int>& edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			graph[u].push_back({ v,wt });
			reversedGraph[v].push_back({ u,wt });
		}

		vector<ll> distanceFromSrc1 = dijkstra(n, graph, src1);
		vector<ll> distanceFromSrc2 = dijkstra(n, graph, src2);
		vector<ll> distanceFromDest = dijkstra(n, reversedGraph, dest);
		ll ans = LONG_MAX;

		for (int i = 0; i < n; ++i) {
			if (distanceFromSrc1[i] != LONG_MAX && distanceFromSrc2[i] != LONG_MAX &&
				distanceFromDest[i] != LONG_MAX) {
				ans = min(ans, distanceFromSrc1[i] + distanceFromSrc2[i] + distanceFromDest[i]);
			}
		}

		return ans == LONG_MAX ? -1 : ans;
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
		vector<vector<int>> edges(m, vector<int>(3));
		for (vector<int>& edge : edges) {
			cin >> edge[0] >> edge[1] >> edge[2];
		}
		int src1, src2, dest;
		cin >> src1 >> src2 >> dest;

		Solution solution;
		cout << solution.minimumWeight(n, edges, src1, src2, dest) << endl;
	}

	return 0;
}