#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int index) {
	int largest = index;
	int l = 2 * index + 1;
	int r = 2 * index + 2;

	if (l < n && a[l] > a[largest]) largest = l;
	if (r < n && a[r] > a[largest]) largest = r;

	if (largest != index) {
		swap(a[largest], a[index]);
		heapify(a, n, largest);
	}

	return;
}

void buildHeap(int a[], int n) {
	int start = n / 2 - 1;

	for (int i = start; i >= 0; --i) {
		heapify(a, n, i);
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; ++i) cin >> a[i];

		buildHeap(a, n);

		for (int i = 0; i < n; ++i) cout << a[i] << " ";
		cout << endl;
	}

	return 0;
}
