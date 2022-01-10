#include<bits/stdc++.h>
using namespace std;

class Solution {
	const int MAX_TIME = 1e9;

	bool checkTime(int time, int n, int k, vector<int>& positions) {
		int pos = positions[0] + time;
		int count = 1;

		for (int i = 1; i < n; ++i) {
			if (positions[i] - time <= pos) continue;
			pos = positions[i] + time;
			++count;
		}

		return count <= k;
	}

public:
	int findMinTime(int n, int k, vector<int>& positions) {
		sort(positions.begin(), positions.end());

		int low = 1, high = MAX_TIME;

		while (low < high) {
			int mid = (low + high) / 2;
			if (checkTime(mid, n, k, positions)) high = mid;
			else low = mid + 1;
		}

		return low;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;
		vector<int> positions(n);
		for (int& x : positions) cin >> x;

		Solution obj;
		cout << obj.findMinTime(n, k, positions) << endl;
	}

	return 0;
}