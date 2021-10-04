#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& pos, int n, int dist, int noCows) {
	--noCows;
	int currPos = pos[0];
	
	for (int i = 1; i < n; ++i) {
		if (pos[i] - currPos >= dist) {
			currPos = pos[i];
			--noCows;
		}
		if (noCows == 0) return true;
	}

	return false;
}

int findMinDist(vector<int>& pos, int n, int noCows) {
	sort(pos.begin(), pos.end());
	int low = 0, high = pos[n - 1], ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (check(pos, n, mid, noCows)) {
			ans = mid;
			low = mid + 1;
		}
		else high = mid - 1;
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, c;
		cin >> n >> c;
		vector<int> pos(n);
		for (int& x : pos) cin >> x;

		cout << findMinDist(pos, n, c) << endl;
	}

	return 0;
}