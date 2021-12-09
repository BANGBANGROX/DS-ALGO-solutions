#include<bits/stdc++.h>
using namespace std;

string addStrings(string& n1, string& n2) {
	int n = n1.size(), m = n2.size(), carry = 0;
	int i = n - 1, j = m - 1;
	string ans("");

	while (i > -1 && j > -1) {
		int val = (n1[i] - '0') + (n2[j] - '0') + carry;
		carry = val / 10;
		val %= 10;
		ans = to_string(val) + ans;
		--i;
		--j;
	}
    
	while (i > -1) {
		int val = (n1[i] - '0') + carry;
		carry = val / 10;
		val %= 10;
		ans = to_string(val) + ans;
		--i;
	}

	while (j > -1) {
		int val = (n2[j] - '0') + carry;
		carry = val / 10;
		val %= 10;
		ans = to_string(val) + ans;
		--j;
	}

	if (carry) ans = to_string(carry) + ans;

	return ans;
}

string multiply(string num1, string num2) {
	if (size(num1) < size(num2)) swap(num1, num2);
	
	int n = num1.size(), m = num2.size(), count = 0;
	string add("");

	for (int i = m - 1; i > -1; --i) {
		int carry = 0;
		string newNum("");
		for (int j = n - 1; j > -1; --j) {
			int val = (num2[i] - '0') * (num1[j] - '0') + carry;
			carry = val / 10;
			val %= 10;
			newNum = to_string(val) + newNum;
		}
		if (carry) newNum = to_string(carry) + newNum;
		if (add == "") add = newNum;
		else {
			for (int k = 0; k < count; ++k) newNum.push_back('0');
			add = addStrings(add, newNum);
		}
		++count;
	}

	int i = 0;
	while (add[i] == '0') add.erase(i, 1);
	if (add == "") add = "0";

	return add;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string num1, num2;
		cin >> num1 >> num2;

		cout << multiply(num1, num2) << endl;
	}

	return 0;
}