#include<bits/stdc++.h>
using namespace std;

class Solution {
	int reduce(int val) {
		if (val >= 60) return val / 60 + reduce(val % 60);

		if (val >= 15) return val / 15 + reduce(val % 15);

		if (val >= 5) return val / 5 + reduce(val % 5);

		if (val >= 1) return val;

		return 0;
	}

public:
	int convertTime(string current, string correct) {
		int currentHours = stoi(current.substr(0, 2));
		int currentMinutes = stoi(current.substr(3, 2));
		int correctHours = stoi(correct.substr(0, 2));
		int correctMinutes = stoi(correct.substr(3, 2));

		int difference = abs(correctHours * 60 + correctMinutes - currentHours * 60 - currentMinutes);

		return reduce(difference);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string current, correct;
		cin >> current >> correct;

		Solution solution;
		cout << solution.convertTime(current, correct) << endl;
	}

	return 0;
}