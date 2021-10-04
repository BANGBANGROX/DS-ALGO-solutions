#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	vector<pair<int, int>>* graph = new vector<pair<int, int>>[n];
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	vector<int> dist(n, INT_MAX);

	for (vector<int>x : flights) {
		graph[x[0]].push_back({ x[1],x[2] });
	}

    pq.push(make_tuple(0, src, 0));

	while (!pq.empty()) {
		tuple<int, int, int > t = pq.top();
        pq.pop();
		int cost = get<0>(t);
		int node = get<1>(t);
		int stops = get<2>(t);
		if (dist[node] < stops) continue;
		dist[node] = stops;
		if (node == dst) return cost;
		if (stops > k) continue;
		for (pair<int, int> x : graph[node]) {
			int child = x.first, weight = x.second;
			pq.push(make_tuple(cost + weight, child, stops + 1));
		}
	}

	return -1;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m, src, dst, k;
		cin >> n >> m >> src >> dst >> k;

		vector<vector<int>> flights(m, vector<int>(3));

		for (int i = 0; i < n; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			flights[i] = { u,v,w };
		}

		cout << findCheapestPrice(n, flights, src, dst, k) << endl;
	}

	return 0;
}