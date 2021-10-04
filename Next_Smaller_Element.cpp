#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(int a[], int n) {
	stack<int> s;
	vector<int> res;

	s.push(a[n - 1]);
	res.push_back(-1);

	for (int i = n - 2; i > -1; --i) {
		while (!s.empty() && s.top() >= a[i]) {
			s.pop();
		}
		if (s.empty()) res.push_back(-1);
		else res.push_back(s.top());
		s.push(a[i]);
	}

	reverse(res.begin(), res.end());

	return res;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> ans = nextSmaller(a, n);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}