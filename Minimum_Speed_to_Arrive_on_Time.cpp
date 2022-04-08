#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool check(vector<int>& distances, double hour, int speed) {
		double timeStamp = 0;
		int n = distances.size();

		for (int i = 0; i < n - 1; ++i) {
			timeStamp += ceil(double(distances[i]) / speed);
			if (timeStamp > hour) return false;
		}

		timeStamp += ((double)distances[n - 1] / speed);

		return timeStamp <= hour;
	}

public:
	int minSpeedOnTime(vector<int>& distances, double hour) {
		int l = 1;
		int r = 1e8;
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(distances, hour, mid)) {
				ans = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> distances(n);
		for (int& x : distances) cin >> x;
		double hour;
		cin >> hour;

		Solution solution;
		cout << solution.minSpeedOnTime(distances, hour) << endl;
	}

	return 0;
}