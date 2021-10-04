#include<bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
	sort(arr, arr + n);
	sort(dep, dep + n);
	int platformsNeeded = 1, minPlatforms = 1, i = 1, j = 0;

	while (i < n && j < n) {
		if (arr[i] <= dep[j]) {
			++platformsNeeded;
			++i;
		}
		else {
			--platformsNeeded;
			++j;
		}
		minPlatforms = max(minPlatforms, platformsNeeded);
	}

	return minPlatforms;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* arr = new int[n];
		int* dep = new int[n];
		for (int i = 0; i < n; ++i) cin >> arr[i] >> dep[i];

		cout << findPlatform(arr, dep, n) << endl;
	}

	return 0;
}
