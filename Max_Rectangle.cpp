#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1005;

ll getMaxArea(ll a[], int n) {
	stack<int> hist;
	int i = 0;
	ll maxArea = 0;

	while (i < n) {
		if (hist.empty() || a[hist.top()] <= a[i]) {
			hist.push(i);
			++i;
			continue;
		}
		int topIndex = hist.top();
		hist.pop();
		int width = i;
		if (!hist.empty())
			width = width - hist.top() - 1;
		ll currArea = a[topIndex] * (ll)width;
		maxArea = max(maxArea, currArea);
	}

	while (!hist.empty()) {
		int topIndex = hist.top();
		hist.pop();
		int width = i;
		if (!hist.empty())
			width = width - hist.top() - 1;
		ll currArea = a[topIndex] * (ll)width;
		maxArea = max(maxArea, currArea);
	}

	return maxArea;
}

ll maxRectangle(ll a[MAX][MAX], int r, int c) {
	ll maxArea = getMaxArea(a[0], c);

	for (int i = 1; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (a[i][j])
				a[i][j] += a[i - 1][j];
		}
		maxArea = max(maxArea, getMaxArea(a[i], c));
	}

	return maxArea;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int r, c;
		cin >> r >> c;
		ll a[MAX][MAX];
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j)
				cin >> a[i][j];
		}

		cout << maxRectangle(a, r, c) << endl;
	}

	return 0;
}