#include<bits/stdc++.h>
using namespace std;

class Solution {
	map<vector<int>, int> dp;

public:
	int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
		if (dp.find(needs) != dp.end()) return dp[needs];

		int minPrice = 0;

		for (int i = 0; i < (int)price.size(); ++i) {
			minPrice += price[i] * needs[i];
		}

		for (vector<int>& offer : special) {
			bool isPossible = true;
			for (int i = 0; i < (int)needs.size(); ++i) {
				if (offer[i] > needs[i]) {
					isPossible = false;
					break;
				}
			}
			if (!isPossible) continue;
			for (int i = 0; i < (int)needs.size(); ++i) {
				needs[i] -= offer[i];
			}
			minPrice = min(minPrice, offer.back() + shoppingOffers(price, special, needs));
			for (int i = 0; i < (int)needs.size(); ++i) {
				needs[i] += offer[i];
			}
		}

		return dp[needs] = minPrice;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> price(n);
		for (int& x : price) cin >> x;
		int m;
		cin >> m;
		vector<vector<int>> special(m, vector<int>(n + 1));
		for (vector<int>& x : special) {
			for (int& y : x) cin >> y;
		}
		vector<int> needs(n);
		for (int& x : needs) cin >> x;

		Solution solution;
		cout << solution.shoppingOffers(price, special, needs);
	}

	return 0;
}