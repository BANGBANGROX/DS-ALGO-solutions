#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		vector<vector<pair<int,int>>> graph(n);
		vector<int> distances(n, INT_MAX);
		set<pair<int, int>> s;
		int ans = 0;

		for (const vector<int>& time : times) {
			int u = time[0] - 1;
			int v = time[1] - 1;
			int w = time[2];
			graph[u].push_back({ v,w });
		}

		s.insert({ 0,k - 1 });
		distances[k - 1] = 0;

		while (!s.empty()) {
			int currentNode = (*s.begin()).second;
			int distance = distances[currentNode];
			s.erase(s.begin());
			for (const pair<int,int>& child : graph[currentNode]) {
				int childNode = child.first;
				int weight = child.second;
				if (distances[childNode] > distance + weight) {
					if (s.find({ distances[childNode],childNode }) != s.end()) {
						s.erase({ distances[childNode],childNode });
					}
					distances[childNode] = distance + weight;
					s.insert({ distances[childNode],childNode });
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			ans = max(ans, distances[i]);
		}

		return ans == INT_MAX ? -1 : ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}