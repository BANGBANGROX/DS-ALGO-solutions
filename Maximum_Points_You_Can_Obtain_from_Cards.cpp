#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int n = cardPoints.size();
		int ans = 0;
		vector<int> prefix(n);
		vector<int> suffix(n);

		prefix[0] = cardPoints[0];
		suffix[n - 1] = cardPoints[n - 1];

		for (int i = 1; i < n; ++i) {
			prefix[i] = prefix[i - 1] + cardPoints[i];
		}

		for (int i = n - 2; i >= 0; --i) {
			suffix[i] = suffix[i + 1] + cardPoints[i];
		}

		for (int i = 0; i <= k; ++i) {
			if (i == 0) ans = max(ans, suffix[n - k]);
			else if (i == k)ans = max(ans, prefix[k - 1]);
			else ans = max(ans, prefix[i - 1] + suffix[n - k + i]);
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
		vector<int> cardPoints(n);
		for (int& x : cardPoints) cin >> x;
		int k;
		cin >> k;

		Solution solution;
		cout << solution.maxScore(cardPoints, k) << endl;
	}

	return 0;
}