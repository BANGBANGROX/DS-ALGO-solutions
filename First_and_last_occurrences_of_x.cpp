#include<bits/stdc++.h>
using namespace std;

int firstOccurence(int a[], int key, int n) {
	int low = 0, high = n - 1, ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == key) {
			ans = mid;
			high = mid - 1;
		}
		else if (a[mid] > key) high = mid - 1;
		else low = mid + 1;
	}

	return ans;
}

int lastOccurence(int a[], int key, int n) {
	int low = 0, high = n - 1, ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == key) {
			ans = mid;
			low = mid + 1;
		}
		else if (a[mid] > key) high = mid - 1;
		else low = mid + 1;
	}

	return ans;
}

vector<int> find(int arr[], int n, int x) {
	return { firstOccurence(arr,x,n),lastOccurence(arr,x,n) };
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		vector<int> ans = find(a, n, x);
		
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}
