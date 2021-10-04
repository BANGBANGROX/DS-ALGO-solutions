#include<bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
	stack<int> auxS;
	queue<int> auxQ; 
	int counter = 0;

	while (!q.empty()) {
		auxS.push(q.front());
		q.pop();
		++counter;
		if (counter == k) break;
	}

    while (!auxS.empty()) {
		auxQ.push(auxS.top());
		auxS.pop();
	}

	while (!q.empty()) {
		auxQ.push(q.front());
		q.pop();
	}

	return auxQ;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n >> k;

		queue<int> q;
		while (n--) {
			int x;
			cin >> x;
			q.push(x);
		}

		queue<int> newQ = modifyQueue(q, k);

		while (!newQ.empty()) {
			cout << newQ.front() << " ";
			newQ.pop();
		}

		cout << endl;
	}

	return 0;
}