#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumSum(int num) {
		string numString = to_string(num);

		sort(begin(numString), end(numString));

		int num1 = (numString[0] - '0') * 10 + (numString[3] - '0');
		int num2 = (numString[1] - '0') * 10 + (numString[2] - '0');

		return num1 + num2;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		Solution solution;
		cout << solution.minimumSum(n) << endl;
	}

	return 0;
}