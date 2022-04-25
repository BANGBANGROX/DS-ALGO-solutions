#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
	ll maximumBeauty(vector<int>& flowers, ll newFlowers, int target, int full, int partial) {
		ll n = flowers.size();
		ll ans = 0;
		ll sum = 0;
		ll p1 = 0;

		sort(flowers.begin(), flowers.end(), greater<int>());

		for (; p1 < n; ++p1) {
			if (newFlowers < (ll)target - flowers[p1]) break;
			newFlowers -= max(0, target - flowers[p1]);
		}

		if (p1 == n)
			return max(n * full, (n - 1) * full + 
				(flowers.back() < target ? ((ll)target - 1) * partial : full));

		for (ll minF = flowers.back(), p2 = n - 1; minF < target;) {
			while (p2 >= p1 && flowers[p2] <= minF) {
				sum += flowers[p2];
				--p2;
			}
			ll needed = (n - p2 - 1) * minF - sum;
			if (needed > newFlowers) {
				--p1;
				if (p1 < 0) break;
				newFlowers += max(0, target - flowers[p1]);
			}
			else {
				ans = max(ans, p1 * full + minF * partial);
				++minF;
			}
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
		vector<int> flowers(n);
		for (int& x : flowers) cin >> x;
		ll newFlowers;
		cin >> newFlowers;
		int target, full, partial;
		cin >> target >> full >> partial;

		Solution solution;
		cout << solution.maximumBeauty(flowers, newFlowers, target, full, partial) << endl;
	}

	return 0;
}