#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int smallestRepunitDivByK(int k) {
		int remainder = 0;

		for (int len = 1; len <= k; ++len) {
			remainder = (remainder * 10 + 1) % k;
			if (remainder == 0) return len;
		}

		return -1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int k;
		cin >> k;

		Solution obj;
		cout << obj.smallestRepunitDivByK(k) << endl;
	}

	return 0;
}