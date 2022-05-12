#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	static class UnionFind {
		vector<int> parent;
		vector<int> groupSize;

	public :
		UnionFind(int n) {
			parent = vector<int>(n);
			groupSize = vector<int>(n);

			for (int i = 0; i < n; ++i) {
				parent[i] = i;
			}
		}

		int find(int a) {
			if (parent[a] != a) return parent[a] = find(parent[a]);

			return a;
		}

		void unionDSU(int a, int b) {
			int parent1 = find(a);
			int parent2 = find(b);

			if (parent1 == parent2) return;

			if (groupSize[parent1] > groupSize[parent2]) {
				parent[parent2] = parent1;
				groupSize[parent1] += groupSize[parent2];
			}
			else {
				parent[parent1] = parent2;
				groupSize[parent2] += groupSize[parent1];
			}
		}
	};

public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int n = s.size();
		string ans("");
		UnionFind unionFind(n);
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;

		for (const vector<int>& pair : pairs) {
			int a = pair[0];
			int b = pair[1];
			unionFind.unionDSU(a, b);
		}

		for (int i = 0; i < n; ++i) {
			mp[unionFind.find(i)].push(s[i]);
		}

		for (int i = 0; i < n; ++i) {
			ans += mp[unionFind.find(i)].top();
			mp[unionFind.find(i)].pop();
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		int n; 
		cin >> n;
		vector<vector<int>> pairs(n, vector<int>(2));
		for (int i = 0; i < n; ++i) {
			cin >> pairs[i][0] >> pairs[i][1];
		}

		Solution solution;
		cout << solution.smallestStringWithSwaps(s, pairs) << endl;
	}

	return 0;
}