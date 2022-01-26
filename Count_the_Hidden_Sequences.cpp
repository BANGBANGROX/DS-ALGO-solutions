#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;
public:
	int numberOfArrays(vector<int>& differences, int lower, int upper) {
		ll minDiff = LONG_MAX;
		ll maxDiff = LONG_MIN;
		ll cumSum = 0;

		for (int difference : differences) {
			cumSum += (ll)difference;
			minDiff = min(minDiff, cumSum);
			maxDiff = max(maxDiff, cumSum);
		}

		ll lowerBound = lower - minDiff;
		ll upperBound = upper - maxDiff;

		if (lowerBound > upperBound || lowerBound > upper || upperBound < lower) return 0;

		lowerBound = max((ll)lower, lowerBound);
		upperBound = min(upperBound, (ll)upper);

		return (upperBound - lowerBound + 1);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> differences(n);
		for (int& x : differences) cin >> x;
		int lower, upper;
		cin >> lower;
		cin >> upper;

		Solution solution;
		cout << solution.numberOfArrays(differences, lower, upper) << endl;
	}

	return 0;
}