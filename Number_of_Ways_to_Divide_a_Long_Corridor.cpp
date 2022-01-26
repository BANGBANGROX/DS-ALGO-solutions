#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

	const int mod = 1e9 + 7;

public:
	int numberOfWays(string corridor) {
		int n = corridor.size();
		int seats = 0;
		ll ans = 1;
		int cnt = 0;

		for (char s : corridor) {
			if (s == 'S') ++seats;
		}

		if (seats == 0 || seats % 2 == 1) return 0;

		for (int i = 0; i < n; ++i) {
			if (corridor[i] == 'S') ++cnt;
			if (cnt == 2) {
				int partition = 1;
				++i;
				while (i < n && corridor[i] == 'P') {
					++i;
					++partition;
				}
				if (i == n) break;
				ans = (ans * (ll)partition) % mod;
				--i;
				cnt = 0;
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string corridor;
		cin >> corridor;

		Solution solution;
		cout << solution.numberOfWays(corridor) << endl;
	}

	return 0;
}