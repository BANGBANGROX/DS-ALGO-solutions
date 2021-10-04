#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>a, pair<int, int>b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first < b.first;
}

int maxMeetings(int start[], int end[], int n) {
	vector<pair<int, int>> timings(n);
	for (int i = 0; i < n; ++i) {
		timings[i] = { start[i],end[i] };
	}

	sort(timings.begin(), timings.end(), comp);
    int ans = 1, prevEnd = timings[0].second;
	for (int i = 1; i < n; ++i) {
		if (prevEnd < timings[i].first) {
			++ans;
			prevEnd = timings[i].second;
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
		int* a = new int[n];
		int* b = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];
		for (int i = 0; i < n; ++i) cin >> b[i];

		cout << maxMeetings(a, b, n) << endl;
	}

	return 0;
}
