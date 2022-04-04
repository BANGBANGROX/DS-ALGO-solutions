#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minBitFlips(int start, int goal) {
		int ans = 0;

		for (int i = 31; i >= 0; --i) {
			int startBit = (start & (1 << i));
			int goalBit = (goal & (1 << i));
			if ((startBit > 0 && goalBit > 0) || (startBit == 0 && goalBit == 0)) continue;
			++ans;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int start, goal;
		cin >> start >> goal;

		Solution solution;
		cout << solution.minBitFlips(start, goal) << endl;
	}

	return 0;
}