#include<bits/stdc++.h>
using namespace std;

int findPos(vector<int> a, int k) {
	int l = 0, u = a.size() - 1;

	while (l <= u) {
		int mid = (l + u) / 2;
		if (a[mid] == k) return mid;
		else if (a[mid] < k) l = mid + 1;
		else u = mid - 1;
	}
    
	return -1;
}

string isKSortedArray(int a[], int n, int k) {
	vector<int> aux(n);
    for (int i = 0; i < n; ++i) {
		aux[i] = a[i];
	}

	sort(aux.begin(), aux.end());
	for (int i = 0; i < n; ++i) {
		int ind1 = i;
		int ind2 = findPos(aux, a[i]);
		if (abs(ind1 - ind2) > k) {
			return "No";
		}
	}

	return "Yes";
}

int main() {
	int n, k, a[10005];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> k;

	cout << isKSortedArray(a, n, k) << endl;

	return 0;
}