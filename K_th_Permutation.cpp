#include<bits/stdc++.h>
using namespace std;

int index(int& k, int n) {
	if (n == 1) return 0;

	--n;
	int fact = n;

	while (k >= fact && n > 1) {
		fact *= (n - 1);
		--n;
	}
	int idx = k / fact;
	k %= fact;

	return idx;
}

string kthPermutation(int n, int k) {
	set<int> s;
	for (int i = 1; i <= n; ++i) s.insert(i);
	set<int>::iterator it = s.begin();
	string ans("");
	--k;

	for (int i = 0; i < n; ++i) {
		int idx = index(k, n - i);
		advance(it, idx);
		ans += (to_string(*it));
		s.erase(it);
		it = s.begin();
	}

	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		
		cout << kthPermutation(n, k) << endl;
	}

	return 0;
}