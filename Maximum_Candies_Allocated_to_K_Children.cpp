#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	bool checkCandies(int maxCandies, vector<int>& candies, ll k) {
		ll total = 0;

		if (maxCandies == 0) return false;

		for (int candy : candies) {
			total += (ll)candy / maxCandies;
			if (total >= k) return true;
		}

		return false;
	}

public:
	int maximumCandies(vector<int>& candies, ll k) {
		int l = 1;
		int r = *max_element(candies.begin(), candies.end());
		int ans = 0;

		while (l <= r) {
			int mid = (l + ((r - l) >> 1));
			if (checkCandies(mid, candies, k)) {
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
		int n;
		cin >> n;
		vector<int> candies(n);
		for (int& x : candies) cin >> x;
		long long k;
		cin >> k;

		Solution solution;
		cout << solution.maximumCandies(candies, k) << endl;
	}

	return 0;
}