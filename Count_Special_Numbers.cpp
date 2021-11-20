#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int countSpecialNumbers(int n, vector<int>& a) {
	unordered_map<int, int> freq;
	int MAX = 0, ans = 0;

	for (int i = 0; i < n; ++i) {
		MAX = max(MAX, a[i]);
		++freq[a[i]];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 2 * a[i]; j <= MAX; j += a[i]) {
			if (freq[j] > 0) {
				ans += freq[j];
				freq[j] = 0;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (freq[a[i]] > 1) {
			ans += freq[a[i]];
			freq[a[i]] = 0;
		}
	}

	return ans;

}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
        vector<int> a(n);

		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << countSpecialNumbers(n, a) << endl;
	}

	return 0;
}