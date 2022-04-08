#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq;

		for (int stone : stones) {
			pq.push(stone);
		}

		while (pq.size() > 1) {
			int x = pq.top();
			pq.pop();
			int y = pq.top();
			pq.pop();
			if (x != y) pq.push(abs(x - y));
		}

		return pq.empty() ? 0 : pq.top();
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> stones(n);
		for (int& x : stones) cin >> x;

		Solution solution;
		cout << solution.lastStoneWeight(stones) << endl;
	}

	return 0;
}