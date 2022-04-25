#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int largestInteger(int num) {
		vector<int> oddDigits;
		vector<int> evenDigits;
		string stringNum = to_string(num);

		for (int i = 0; i < stringNum.size(); ++i) {
			if (((stringNum[i] - '0') & 1) > 0) oddDigits.push_back(stringNum[i]);
			else evenDigits.push_back(stringNum[i]);
		}

		sort(oddDigits.begin(), oddDigits.end());
		sort(evenDigits.begin(), evenDigits.end());

		for (int i = 0; i < stringNum.size(); ++i) {
			int dig = stringNum[i] - '0';
			if ((dig & 1) > 0) {
				stringNum[i] = oddDigits.back();
				oddDigits.pop_back();
			}
			else {
				stringNum[i] = evenDigits.back();
				evenDigits.pop_back();
			}
		}

		return stoi(stringNum);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		Solution solution;
		cout << solution.largestInteger(n) << endl;
	}

	return 0;
}