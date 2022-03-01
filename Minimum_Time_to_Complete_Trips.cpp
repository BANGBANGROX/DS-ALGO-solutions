#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	bool checkTime(vector<int>& time, int totalTrips, ll totalTime) {
		ll trips = 0;

		for (int& currentTime : time) {
			trips += (totalTime / currentTime);
			if (trips >= totalTrips) return true;
		}

		return false;
	}

public:
	ll minimumTime(vector<int>& time, int totalTrips) {
		ll maxTime = *max_element(time.begin(), time.end());
		ll l = 1;
		ll r = maxTime * totalTrips;
		
		while (l < r) {
			ll mid = (l + ((r - l) >> 1));
			if (checkTime(time, totalTrips, mid)) r = mid;
			else l = mid + 1;
		}

		return l;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> time(n);
		for (int& currentTime : time) cin >> currentTime;
		int totalTime;
		cin >> totalTime;

		Solution solution;
		cout << solution.minimumTime(time, totalTime) << endl;
	}

	return 0;
}