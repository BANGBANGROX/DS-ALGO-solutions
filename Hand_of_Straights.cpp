#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		int n = hand.size();
		unordered_map<int, int> frequency;
		priority_queue<int, vector<int>, greater<int>> pq;

		if (n % groupSize != 0) return false;

		for (int num : hand) {
			if (frequency.find(num) == frequency.end()) {
				pq.push(num);
			}
			++frequency[num];
		}

		while (!pq.empty()) {
			vector<int> currentGroup;
			for (int i = 0; i < groupSize; ++i) {
				if (currentGroup.empty()) {
					int num = pq.top();
					pq.pop();
					currentGroup.push_back(num);
					--frequency[num];
					continue;
				}
				int num = pq.top();
				pq.pop();
				if (num != currentGroup.back() + 1) return false;
				currentGroup.push_back(num);
				--frequency[num];
			}
			for (int num : currentGroup) {
				if (frequency[num] > 0) pq.push(num);
			}
		}

		return true;
	}
};


int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, groupSize;
		cin >> n;
		vector<int> hand(n);
		for (int& x : hand) cin >> x;
		cin >> groupSize;

		Solution solution;
		if (solution.isNStraightHand(hand, groupSize)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}