#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	int findIndexLesser(string num, int x) {
		int n = num.size();

		for (int i = 0; i < n; ++i) {
			if ((num[i] - '0') < x) return i;
		}

		return n;
	}

	int findIndexGreater(string num, int x) {
		int n = num.size();

		for (int i = 1; i < n; ++i) {
			if ((num[i] - '0') > x) return i;
		}

		return n;
	}

public:
	string computeMaxValue(string num, int x) {
		string dig = to_string(x);
		int n = num.size();

		if (num[0] == '-') {
			int index = findIndexGreater(num, x);
			if (index == n) {
				num += dig;
			}
			else {
				num.insert(index, dig);
			}
		}

		else {
			int index = findIndexLesser(num, x);
			if (index == n) {
				num += dig;
			}
			else {
				num.insert(index, dig);
			}
		}

		return num;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string num;
		int x;
		cin >> num >> x;

		Solution obj;
		cout << obj.computeMaxValue(num, x) << endl;
	}

	return 0;
}