#include<bits/stdc++.h>
using namespace std;

int add(int x, int y) {
	if (y == 0) return x;
	return add(x ^ y, (x & y) << 1);
}

int subtract(int x, int y) {
	if (y == 0) return x;
	return subtract(x ^ y, (~x & y) << 1);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int code;
		cin >> code;

		if (code == 1) {
			int a, b;
			cin >> a >> b;
			cout << add(a, b) << endl;
		}

		if (code == 2) {
			int a, b;
			cin >> a >> b;
			cout << subtract(a, b) << endl;
		}
	}

	return 0;
}