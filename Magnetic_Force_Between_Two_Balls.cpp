#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool check(vector<int>& positions, int m, int distance) {
		int last = positions[0];
		int n = positions.size();

		--m;

		for (int i = 1; i < n; ++i) {
			if (m == 0) return true;
			if (last + distance > positions[i]) continue;
			--m;
			last = positions[i];
		}

		return m == 0;
	}

public:
	int maxDistance(vector<int>& position, int m) {
		sort(position.begin(), position.end());

		int l = 1;
		int r = position.back() - position[0];
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(position, m, mid)) {
				ans = mid;
				l = mid + 1;
			}
			else r = mid - 1;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int m, n;
		cin >> n;
		vector<int> positions(n);
		for (int& x : positions) cin >> x;
		int m;
		cin >> m;

		Solution solution;
		cout << solution.maxDistance(positions, m) << endl;
	}

	return 0;
}