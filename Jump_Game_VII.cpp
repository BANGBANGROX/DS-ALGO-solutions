#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool canReach(string s, int minJump, int maxJump) {
		int n = s.size();
		int lastIndex = n - 1;
		int farthest = 0;

		if (s[lastIndex] == '1') return false;

		vector<bool> visited(n);
		queue<int> q;

		q.push(0);
		visited[0] = true;

		while (!q.empty()) {
			int node = q.front();
			q.pop();
			if (node == lastIndex) return true;
			int start = max(node + minJump, farthest + 1);
			int end = min(node + maxJump, n - 1);
			for (int i = start; i <= end; ++i) {
				if (!visited[i] && s[i] == '0') {
					visited[i] = true;
					q.push(i);
					if (i == lastIndex) return true;
				}
			}
			farthest = end;
		}

		return false;
	}
};


int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		int minJump, maxJump;
		cin >> minJump >> maxJump;

		Solution solution;
		cout << solution.canReach(s, minJump, maxJump) << endl;
	}

	return 0;
}