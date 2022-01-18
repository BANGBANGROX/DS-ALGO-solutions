#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
		sort(asteroids.begin(), asteroids.end());

		for (int m : asteroids) {
			if (mass >= m) mass += m;
			else return false;
			if (mass >= asteroids.back()) return true;
		}

		return true;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n, mass;
		cin >> mass >> n;
		vector<int> asteroids(n);
		for (int& x : asteroids) cin >> x;

		Solution solution;
		cout << solution.asteroidsDestroyed(mass, asteroids);
	}

	return 0;
}