#include<bits/stdc++.h>
using namespace std;

int minimumNumberOfSwaps(string s) {
	int n = s.size();
	int leftCount = 0, rightCount = 0, imbalance = 0, swaps = 0;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '[') {
			++leftCount;
			if(imbalance > 0)
		     	swaps += imbalance;
		}
		if (s[i] == ']') {
			++rightCount;
		}
		imbalance = rightCount - leftCount;
	}

	return swaps;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;

		cout << minimumNumberOfSwaps(s) << endl;
	}

	return 0;
}
