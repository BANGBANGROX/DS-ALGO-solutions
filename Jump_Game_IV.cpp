#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int minJumps(vector<int>& arr) {
		int n = arr.size();
		int lastIndex = n - 1;
		int steps = 0;

		if (n <= 1) return 0;

		unordered_map<int, vector<int>> graph;

		for (int i = 0; i < n; ++i) {
			graph[arr[i]].push_back(i);
		}

		queue<int> q;
		vector<bool> visited(n);

		q.push(0);
		visited[0] = true;

		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				int currNode = q.front();
				q.pop();
				if (currNode == lastIndex) return steps;
				for (int childNode : graph[arr[currNode]]) {
					if (!visited[childNode]) {
						visited[childNode] = true;
						q.push(childNode);
					}
				}
				graph[arr[currNode]].clear();
				if (currNode + 1 < n && !visited[currNode + 1]) {
					visited[currNode + 1] = true;
					q.push(currNode + 1);
				}
				if (currNode - 1 >= 0 && !visited[currNode - 1]) {
					visited[currNode - 1] = true;
					q.push(currNode - 1);
				}
			}
			++steps;
		}

		return -1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int& x : arr) cin >> x;

		Solution solution;
		cout << solution.minJumps(arr) << endl;
	}

	return 0;
}