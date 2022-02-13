#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	int nextGreaterElement(int n) {
		string numString = to_string(n);
		int size = numString.size();

		if (size == 1) return -1;

		int left = size - 2;

		while (left >= 0 && numString[left + 1] <= numString[left]) --left;

		if (left < 0) return -1;

		int last = size - 1;

		for (int i = size - 1; i >= 0; --i) {
			if (numString[i] > numString[left]) {
				last = i;
				break;
			}
		}

		swap(numString[last], numString[left]);
		reverse(numString.begin() + left + 1, numString.end());

		ll ans = stoll(numString);

		if (ans > INT_MAX) ans = -1;

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
		cout << solution.nextGreaterElement(n) << endl;
	}

	return 0;
}