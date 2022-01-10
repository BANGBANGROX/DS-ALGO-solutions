#include<bits/stdc++.h>
using namespace std;

class Solution {
	const int DIVISOR = 60;
public:
	int numPairsDivisibleBy60(vector<int>& time) {
		vector<int> frequency(DIVISOR);
		int ans = 0;

		for (int t : time) {
			++frequency[t % DIVISOR];
		}

		for (int t : time) {
			int a1 = t % DIVISOR;
			int a2 = (DIVISOR - a1) % DIVISOR;
			if (a1 == a2) {
				ans += (frequency[a1] * (frequency[a1] - 1)) / 2;
			}
			else {
				ans += frequency[a1] * frequency[a2];
			}
			frequency[a1] = frequency[a2] = 0;
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
		vector<int> time(n);
		for (int& x : time) cin >> x;

		Solution obj;
		cout << obj.numPairsDivisibleBy60(time) << endl;
	}

	return 0;
}