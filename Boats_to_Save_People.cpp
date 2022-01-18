#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		int n = people.size();
		int l = 0;
		int r = n - 1;
		int ans = 0;

		sort(people.begin(), people.end());

		while (l <= r) {
			++ans;
			if (people[l] + people[r] <= limit) {
				++l;
			}
			--r;
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, limit;
		cin >> n;
		vector<int> people(n);
		for (int& x : people) cin >> x;
		cin >> limit;

		Solution solution;
		cout << solution.numRescueBoats(people, limit) << endl;
	}

	return 0;
}