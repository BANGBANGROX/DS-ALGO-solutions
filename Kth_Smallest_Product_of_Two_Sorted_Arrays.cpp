#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll count(vector<int>& n1, vector<int>& n2, ll val) {
	int len = n1.size();
	ll cnt = 0;

	for (int i = 0, j = n2.size() - 1; i < len; ++i) {
		while (j > -1 && (ll)n1[i] * n2[j] > val) --j;
		cnt += (1LL * j + 1);
	}
	
	return cnt;
}

ll kthSmallestProductUtil(vector<int>& pos1, vector<int>& pos2, vector<int>& neg1, vector<int>& neg2, ll k) {
	vector<int> pos1_r(pos1.rbegin(), pos1.rend()), pos2_r(pos2.rbegin(), pos2.rend()),
		neg1_r(neg1.rbegin(), neg1.rend()), neg2_r(neg2.rbegin(), neg2.rend());
	ll low = -1 * 1e10, high = 1e10;

	while (low < high) {
		ll mid = (low + high - 1) / 2, cnt = 0;
		if (mid >= 0) {
			 cnt = count(pos1, pos2, mid) + count(neg1_r, neg2_r, mid) + 
				(ll)pos1.size() * neg2.size() + (ll)pos2.size() * neg1.size();
		}
		else {
			cnt = count(pos1_r, neg2, mid) + count(pos2_r, neg1, mid);
		}
		if (cnt < k) low = mid + 1;
		else high = mid;
	}

	return low;
}

ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
	auto low1 = lower_bound(nums1.begin(), nums1.end(), 0), low2 = lower_bound(nums2.begin(), nums2.end(), 0);

	vector<int> neg1(nums1.begin(), low1), neg2(nums2.begin(), low2),
		pos1(low1, nums1.end()), pos2(low2, nums2.end());

	ll ans = kthSmallestProductUtil(pos1, pos2, neg1, neg2, k);

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;
		ll k;
		cin >> k;
		vector<int>n1(n), n2(m);

		for (int& x : n1) cin >> x;
		for (int& x : n2) cin >> x;

		cout << kthSmallestProduct(n1, n2, k) << endl;
	}

	return 0;
}