#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int ans = 0;
		int num = 5;
		
		while ((n / num) > 0) {
			ans += (n / num);
			num *= 5;
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
		cout << solution.trailingZeroes(n) << endl;
	}

	return 0;
}