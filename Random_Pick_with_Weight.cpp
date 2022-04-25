#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> prefixSum;

public:
    Solution(vector<int>& w) {
		prefixSum.push_back(w[0]);

		for (int i = 1; i < w.size(); ++i) {
			prefixSum.push_back(prefixSum.back() + w[i]);
		}
    }

    int pickIndex() {
		int key = rand() % prefixSum.back();

		return upper_bound(prefixSum.begin(), prefixSum.end(), key) - prefixSum.begin();
    }
};

int main() {
	vector<int> w = { 1,3 };

	Solution solution(w);
	cout << solution.pickIndex() << endl; // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
	cout << solution.pickIndex() << endl; // return 1
	cout << solution.pickIndex() << endl; // return 1
	cout << solution.pickIndex() << endl; // return 1
	cout << solution.pickIndex() << endl; 
	// return 0. It is returning the first element (index = 0) that has a probability of 1/4.

	return 0;
}