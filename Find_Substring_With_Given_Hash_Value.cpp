#include<bits/stdc++.h>
using namespace std;

class Solution {
	typedef long long ll;

public:
	string subStrHash(string s, int power, int modulo, int k, int hashValue) {
		int n = s.size();
		vector<ll> p(k);

		p[0] = 1;

		for (int i = 1; i < k; ++i) {
			p[i] = ((p[i - 1] % modulo) * power) % modulo;
		}

		int l = n - k;
		int r = n - 1;
		int start = -1;
		ll hash = 0;

		for (int i = l; i <= r; ++i) {
			hash = (hash + (((ll)s[i] - 'a' + 1) * p[i - l])) % modulo;
		}

		while (l >= 0) {
			if (hash == hashValue) start = l;
			hash = (hash - (((ll)s[r] - 'a' + 1) * p[k - 1]) % modulo + modulo) % modulo;
			--l;
			--r;
			if (l >= 0) {
				hash = ((hash * power) % modulo +((ll)s[l] - 'a' + 1)) % modulo;
			}
		}

		return s.substr(start, k);
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		int power, k, modulo, hashValue;
		cin >> power >> modulo >> k >> hashValue;

		Solution solution;
		cout << solution.subStrHash(s, power, modulo, k, hashValue) << endl;
	}

	return 0;
}