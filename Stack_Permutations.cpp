#include<bits/stdc++.h>
using namespace std;

bool isStackPermutation(int input[], int output[], int n) {

	queue<int> ipQ, opQ;
	stack<int> intS;

	for (int i = 0; i < n; ++i) {
		ipQ.push(input[i]);
		opQ.push(output[i]);
	}

	while (!ipQ.empty()) {
		int topEl = ipQ.front();
		ipQ.pop();
		if (topEl != opQ.front()) {
			intS.push(topEl);
			continue;
		}
		opQ.pop();
		while (!intS.empty()) {
			if (opQ.front() == intS.top()) {
				opQ.pop();
				intS.pop();
			}
			else break;
		}
	}

	return ipQ.empty() && intS.empty();

}

int main() {

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int* ip = new int[n];
		int* op = new int[n];
		for (int i = 0; i < n; ++i) cin >> ip[i];
		for (int i = 0; i < n; ++i) cin >> op[i];

		cout << isStackPermutation(ip, op, n) << endl;
	}

	return 0;
}