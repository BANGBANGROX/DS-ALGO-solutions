#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	ll putMarbles(vector<int>& weights, int k) {
		int n = (int)weights.size();
		ll answer = 0;
		vector<int> pairWeights(n);

		for (int i = 0; i < n - 1; ++i) {
			pairWeights[i] = weights[i] + weights[i + 1];
		}

		sort(pairWeights.begin(), pairWeights.begin() + n - 1);

		for (int i = 0; i < k - 1; ++i) {
			answer += (pairWeights[n - 2 - i] - pairWeights[i]);
		}

		return answer;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> weights(n);
		for (int& x : weights) {
			cin >> x;
		}
		int k;
		cin >> k;

		Solution solution;
		cout << solution.putMarbles(weights, k) << endl;
	}

	return 0;
}