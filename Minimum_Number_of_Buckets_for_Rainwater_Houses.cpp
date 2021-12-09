#include<bits/stdc++.h>
using namespace std;

int minimumBuckets(string street) {
	int n = street.size(), buckets = 0, lastMarked = -1;

	for (int i = 0; i < n; ++i) {
		if (street[i] == 'H') {
			if (i > 0) {
				if (lastMarked != i - 1) {
					if (i < n - 1 && street[i + 1] == '.') {
						++buckets;
						lastMarked = i + 1;
					}
					else if (street[i - 1] == '.') {
						++buckets;
						lastMarked = i - 1;
					}
					else return -1;
				}
			}
			else {
				if (i < n - 1 && street[i + 1] == '.') {
					++buckets;
					lastMarked = i + 1;
				}
				else return -1;
			}
		}
	}

	return buckets;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string street;
		cin >> street;

		cout << minimumBuckets(street) << endl;
	}

	return 0;
}