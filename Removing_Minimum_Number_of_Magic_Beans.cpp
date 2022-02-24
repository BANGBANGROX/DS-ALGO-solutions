#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	int findNextGreater(vector<int>& beans, int value, int start, int end) {
		int ans = -1;
        
		while (start <= end) {
			int mid = (start + ((end - start) >> 1));
			if (beans[mid] > value) {
				ans = mid;
				end = mid - 1;
			}
			else start = mid + 1;
		}

		return ans;
	}

	int findPreviousLower(vector<int>& beans, int value, int start, int end) {
		int ans = -1;

		while (start <= end) {
			int mid = (start + ((end - start) >> 1));
			if (beans[mid] < value) {
				ans = mid;
				start = mid + 1;
			}
			else end = mid - 1;
		}

		return ans;
	}

public:
	ll minimumRemoval(vector<int>& beans) {
		int n = beans.size();
		vector<ll> prefix(n);
		ll ans = LONG_MAX;

		sort(beans.begin(), beans.end());

		for (int i = 0; i < n; ++i) {
			prefix[i] = beans[i];
			if (i > 0) prefix[i] += prefix[i - 1];
		}

		for (int i = 0; i < n; ++i) {
			int lower = findPreviousLower(beans, beans[i], 0, i);
			int upper = findNextGreater(beans, beans[i], i, n - 1);
			ll currentValue = 0;
			if (lower == -1 && upper == -1) return 0;
			if (lower == -1) {
				currentValue = (prefix[n - 1] - prefix[upper - 1] - beans[i] * ((ll)n - upper));
			}
			else if (upper == -1) {
				currentValue = prefix[lower];
			}
			else {
				currentValue = ((prefix[n - 1] - prefix[upper - 1] - 
					beans[i] * ((ll)n - upper)) + prefix[lower]);
			}
			ans = min(ans, currentValue);
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
		vector<int> beans(n);
		for (int& x : beans) cin >> x;

		Solution solution;
		cout << solution.minimumRemoval(beans) << endl;
	}

	return 0;
}