#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minDeletions(string s) {
		vector<int> frequency(26);
		priority_queue<int> pq;
		int ans = 0;

		for (char ch : s) {
			++frequency[ch - 'a'];
		}

		for (int i = 0; i < 26; ++i) {
			if (frequency[i] > 0) {
				pq.push(frequency[i]);
			}
		}

		while (pq.size() > 1) {
			int top = pq.top();
			pq.pop();
			if (top == pq.top()) {
				if (top > 1) {
					pq.push(top - 1);
				}
				++ans;
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		Solution solution;
		cout << solution.minDeletions(s) << endl;
	}

	return 0;
}