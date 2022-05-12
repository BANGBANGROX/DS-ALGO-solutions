#include<bits/stdc++.h>
using namespace std;

class Solution {
	int a;
	int e;
	int i;
	int o;
	int u;

	void increment() {
		a = a + e + i + o + u;
		e = e + i + o + u;
		i = i + o + u;
		o = o + u;
	}

public:
	int countVowelStrings(int n) {
		a = e = i = o = u = 1;

		for (int i = 1; i < n; ++i) {
			increment();
		}

		return (a + e + i + o + u);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {

	}

	return 0;
}