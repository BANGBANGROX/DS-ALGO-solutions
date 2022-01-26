#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool validMountainArray(vector<int>& arr) {
		int n = arr.size();

		if (n < 3) return false;

		int i = 0;

		// Left side of the mountain
		while (i < n - 1 && arr[i] < arr[i + 1]) {
			++i;
		}

		if (i == n - 1 || i == 0 || arr[i + 1] == arr[i]) return false;

		// Right side of the mountain
		while (i < n - 1 && arr[i] > arr[i + 1]) {
			++i;
		}

		return i == n - 1;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int& x : arr) cin >> x;

		Solution solution;
		if (solution.validMountainArray(arr)) cout << "true\n";
		else cout << "false\n";
	}

	return 0;
}