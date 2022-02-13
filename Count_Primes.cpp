#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		int ans = 0;
		vector<int> primes(n + 1, 1);

		if (n == 0) return 0;

		for (int i = 4; i <= n; i += 2) {
			primes[i] = 0;
		}

		primes[0] = primes[1] = 0;

		for (int i = 3; i * i <= n; i += 2) {
			if (primes[i] == 1) {
				++ans;
				for (int j = 2 * i; j <= n; j += i) {
					primes[j] = 0;
				}
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

		Solution solution;
		cout << solution.countPrimes(n) << endl;
	}

	return 0;
}