#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int x) {
	if (s.empty()) {
		s.push(x);
		return;
	}

	int a = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(a);
}

void reverseStack(stack<int>& s) {
	if (s.empty()) return;

	int a = s.top();
	s.pop();

	reverseStack(s);

	insertAtBottom(s, a);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		stack<int> s;
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			s.push(a);
		}


		reverseStack(s);

		while (!s.empty()) {
			cout << s.top() << " ";
			s.pop();
		}

		cout << endl;
	}

	return 0;
}