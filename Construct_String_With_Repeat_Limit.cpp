#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string repeatLimitedString(string s, int repeatLimit) {
		vector<int> frequency(26);
		string ans("");
		priority_queue<char> pq;

		for (char ch : s) {
			if (frequency[ch - 'a'] == 0) pq.push(ch);
			++frequency[ch - 'a'];
		}

		while (!pq.empty()) {
			char largestCharacter = pq.top();
			char secondLargestCharacter = NULL;
			pq.pop();
			if (!pq.empty()) {
				secondLargestCharacter = pq.top();
				pq.pop();
			}
			if (!ans.empty() && ans.back() == largestCharacter) {
				ans.pop_back();
				++frequency[largestCharacter - 'a'];
			}
			int limit = min(frequency[largestCharacter - 'a'], repeatLimit);
			for (int i = 0; i < limit; ++i) {
				ans += largestCharacter;
				--frequency[largestCharacter - 'a'];
			}
			if (secondLargestCharacter == NULL) break;
			else ans += secondLargestCharacter;
			--frequency[secondLargestCharacter - 'a'];
			if (frequency[largestCharacter - 'a'] > 0) pq.push(largestCharacter);
			if (frequency[secondLargestCharacter - 'a'] > 0) pq.push(secondLargestCharacter);
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
		int repeatLimit;
		cin >> repeatLimit;

		Solution solution;
		cout << solution.repeatLimitedString(s, repeatLimit) << endl;
	}

	return 0;
}