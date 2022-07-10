#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minimumBoxes(int n) {
		int current = 0;
		int edges = 0;
		int extra = 0;

		while (current + (edges + 1) * (edges + 2) / 2 <= n) {
			current += (edges + 1) * (edges + 2) / 2;
			++edges;
		}

		while (current < n) {
			++extra;
			current += extra;
		}

		return edges * (edges + 1) / 2 + extra;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		Solution solution;
		cout << solution.minimumBoxes(n) << endl;
	}

	return 0;
}