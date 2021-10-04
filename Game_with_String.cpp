#include<bits/stdc++.h>
using namespace std;

int minValue(string s, int k) {
	vector<int> freq(26);
	priority_queue<int> pq;
	int n = s.size();

	for (int i = 0; i < n; ++i) ++freq[s[i] - 'a'];

	for (int i = 0; i < 26; ++i) {
		if (freq[i] != 0) pq.push(freq[i]);
	}

	while (!pq.empty() && k--) {
		int f = pq.top();
		pq.pop();
		if (f > 1) pq.push(f - 1);
	}

	int res = 0;

	while (!pq.empty()) {
		int top = pq.top();
		res += top * top;
		pq.pop();
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		int k;
		cin >> s >> k;

		cout << minValue(s, k) << endl;
	}

	return 0;
}
