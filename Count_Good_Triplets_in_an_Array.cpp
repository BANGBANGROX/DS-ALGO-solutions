#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	constexpr int static  N = 1e5;

	int bt[N + 1] = {};

	int prefixSum(int i) {
		int sum = 0;

		for (i = i + 1; i > 0; i -= i & (-1 * i)) {
			sum += bt[i];
		}

		return sum;
	}

	void add(int i, int val) {
		for (i = i + 1; i <= N; i += i & (-1 * i)) {
			bt[i] += val;
		}
	}

public:
	ll goodTriplets(vector<int>& nums1, vector<int>& nums2) {
		ll ans = 0;
		int size = nums1.size();
		vector<int> ids(size);

		for (int i = 0; i < size; ++i) {
			ids[nums2[i]] = i;
		}

		for (int i = 0; i < size - 1; ++i) {
			int mid = ids[nums1[i]];
			int sm = prefixSum(mid);
			int gr = size - 1 - mid - i + sm;
			ans += (ll)sm * gr;
			add(mid, 1);
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
		vector<int> nums1(n), nums2(n);
		for (int& x : nums1) cin >> x;
		for (int& x : nums2) cin >> x;

		Solution solution;
		cout << solution.goodTriplets(nums1, nums2) << endl;
	}

	return 0;
}