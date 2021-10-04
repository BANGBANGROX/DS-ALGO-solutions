#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

string secFrequent(string* arr, int n) {
	unordered_map<string, int> freq;

	for (int i = 0; i < n; ++i) {
		++freq[arr[i]];
	}

	int secondMinF = INT_MIN, maxF = INT_MIN;
	string resMax(""), resSecondMax("");

	for (pair<string, int> x : freq) {
		if (x.second > maxF) {
			resSecondMax = resMax;
			secondMinF = maxF;
			maxF = x.second;
			resMax = x.first;
		}
		if (x.second > secondMinF && x.second < maxF) {
			secondMinF = x.second;
			resSecondMax = x.first;
		}
	}

	return resSecondMax;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string* s = new string[n];
		for (int i = 0; i < n; ++i) cin >> s[i];

		cout << secFrequent(s, n) << endl;
	}

	return 0;
}