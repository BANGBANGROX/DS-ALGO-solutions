#include<bits/stdc++.h>
using namespace std;

int wateringPlants(vector<int>& plants, int capacity) {
	int n = plants.size(), steps, left = capacity - plants[0] % capacity;
	
	if (plants[0] / capacity > 1) steps = 2 * (plants[0] / capacity + 1) + 1;
	else steps = 1;

	for (int i = 1; i < n; ++i) {
		if (left >= plants[i]) {
			++steps;
			left -= plants[i];
			continue;
		}
		steps += i;
		int rounds = (plants[i] % capacity == 0) ? plants[i] / capacity : plants[i] / capacity + 1;
		steps += (rounds * (i + 1));
		left = capacity - plants[i] % capacity;
		if (left == capacity) left = 0;
	}

	return steps;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, capacity;
		cin >> n;
		vector<int> plants(n);
		for (int& x : plants) cin >> x;
		cin >> capacity;

		cout << wateringPlants(plants, capacity) << endl;
	}

	return 0;
}
