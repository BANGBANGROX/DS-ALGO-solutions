#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getMaxArea(ll a[], int n) {
	stack<int> hist;
	int i = 0;
	ll maxArea = 0;

	while (i < n) {
		if (hist.empty() || a[hist.top()] <= a[i]) {
			hist.push(i);
			++i;
		}
		else {
			int top = hist.top();
			hist.pop();
			int width = i;
			if (!hist.empty()) width = width - (hist.top() + 1);
			ll currArea = a[top] * (ll)width;
			maxArea = max(maxArea, currArea);
		}
	}

	while (!hist.empty()) {
		int top = hist.top();
		hist.pop();
		int width = i;
		if (!hist.empty()) width = width - (hist.top() + 1);
		ll currArea = a[top] * (ll)width;
		maxArea = max(maxArea, currArea);
	}

	return maxArea;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		ll* a = new ll[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << getMaxArea(a, n) << endl;
	}

	return 0;
}
