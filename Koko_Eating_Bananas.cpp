#include<bits/stdc++.h>
using namespace std;

class Solution {
	bool check(vector<int>& piles, int h, int speed) {
		int time = 0;

		for (int pile : piles) {
			time += (pile / speed);
			if (pile % speed == 0) --time;
			if (time > h) return false;
		}

		return true;
	}

public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int l = 1;
		int r = *max_element(piles.begin(), piles.end());
		int ans = -1;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (check(piles, h, mid)) {
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
		vector<int> piles(n);
		int h;
		cin >> h;

		Solution solution;
		cout << solution.minEatingSpeed(piles, h) << endl;
	}

	return 0;
}