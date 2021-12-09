#include<bits/stdc++.h>
using namespace std;

bool canReach(vector<int>& a, int start) {
	if (a[start] == -1) return false;

	if (a[start] == 0) return true;

	int right = start + a[start], left = start - a[start];

	a[start] = -1;

	return (right < a.size() && canReach(a, right)) || (left > -1 && canReach(a, left));
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, start;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		cin >> start;

		if (canReach(a, start)) cout << "Possible\n";
		else cout << "Not possible\n";
	}

	return 0;
}