#include<bits/stdc++.h>
using namespace std;

int maxScoreSightseeingPair(vector<int>& values) {
	int n = values.size(), ans = 0;
	vector<int> dp1(n), dp2(n);
	
	for (int i = n - 1; i > -1; --i) {
		dp1[i] = values[i] + i;
		dp2[i] = values[i] - i;
		if (i + 1 < n) { 
			dp2[i] = max(dp2[i], dp2[i + 1]); 
			ans = max(ans, dp1[i] + dp2[i + 1]);
		}
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> values(n);
		for (int& x : values) cin >> x;

		cout << maxScoreSightseeingPair(values) << endl;
	}

	return 0;
}
