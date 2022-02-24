#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	vector<ll> sumOfThree(ll num) {
		if (num % 3 != 0) return {};

		ll a = num / 3;
		
		return { a - 1,a,a + 1 };
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		long long num;
		cin >> num;

		Solution solution;
		vector<long long> ans = solution.sumOfThree(num);
		cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	}

	return 0;
}