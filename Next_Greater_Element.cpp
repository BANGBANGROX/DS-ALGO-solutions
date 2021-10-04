#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> nextLargerElement(vector<ll> arr, int n) {
	vector<ll> res;
	stack<ll> nextGreater;

	res.push_back(-1);
	nextGreater.push(arr[n - 1]);

	for (int i = n - 2; i > -1; --i) {
		while (!nextGreater.empty() && nextGreater.top() <= arr[i]) {
			nextGreater.pop();
		}
		if (!nextGreater.empty()) res.push_back(nextGreater.top());
		else res.push_back(-1);
		nextGreater.push(arr[i]);
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
		vector<ll> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<ll> res = nextLargerElement(a, n);
		for (ll x : res) cout << x << " ";
		cout << endl;
	}

	return 0;
}