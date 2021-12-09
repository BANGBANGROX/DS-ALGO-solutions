#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
	int n = temperatures.size();
	stack<int> s;
	vector<int> ans(n);

	for (int i = n - 1; i > -1; --i) {
		while (!s.empty() && temperatures[s.top()] <= temperatures[i]) s.pop();
		if (s.empty()) ans[i] = 0;
		else ans[i] = (s.top() - i);
		s.push(i);
	}

	return ans;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> temperatures(n);
		for (int& x : temperatures) cin >> x;

		vector<int> ans = dailyTemperatures(temperatures);
		for (int x : ans) cout << x << " ";
		cout << endl;
	}

	return 0;
}