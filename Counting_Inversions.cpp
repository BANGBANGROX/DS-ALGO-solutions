#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll merge(int arr[], int temp[], int left, int mid, int right) {
	int i = left, j = mid, k = left;
	ll res = 0;

	while (i < mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i];
			++k;
			++i;
		}
		else {
			res += ((ll)mid - i);
			temp[k] = arr[j];
			++k;
			++j;
		}
	}
	while (i < mid) {
		temp[k] = arr[i];
		++k;
		++i;
	}
	while (j <= right) {
		temp[k] = arr[j];
		++k;
		++j;
	}
	for (i = left; i <= right; ++i) {
		arr[i] = temp[i];
	}

	return res;
}

ll mergeSort(int arr[], int temp[], int left, int right) {
	ll res = 0;

	if (right > left) {
		int mid = (left + right) / 2;
		res += mergeSort(arr, temp, left, mid);
		res += mergeSort(arr, temp, mid + 1, right);
		res += merge(arr, temp, left, mid + 1, right);
	}

	return res;
}

ll countInversions(int arr[], int n) {
	int* temp = new int[n];

	return mergeSort(arr, temp, 0, n - 1);
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		cout << countInversions(a, n) << endl;
	}

	return 0;
}