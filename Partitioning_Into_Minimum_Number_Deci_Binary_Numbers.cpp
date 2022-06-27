#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minPartitions(string n) {
		return *max_element(n.begin(), n.end()) - '0';
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string n;
		cin >> n;

		Solution solution;
		cout << solution.minPartitions(n) << endl;
	}

	return 0;
}