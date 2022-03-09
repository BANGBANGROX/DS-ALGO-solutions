// https://leetcode.com/problems/cells-in-a-range-on-an-excel-sheet/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> cellsInRange(string s) {
		char row1 = s[0];
		char row2 = s[3];
		char col1 = s[1];
		char col2 = s[4];
		vector<string> ans;

		for (char row = row1; row <= row2; ++row) {
			for (char col = col1; col <= col2; ++col) {
				string cell("");
				cell += row;
				cell += col;
				ans.push_back(cell);
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
		vector<string> ans = solution.cellsInRange(s);
		for (string& x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}