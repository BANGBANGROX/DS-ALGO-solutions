#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> Anagrams(vector<string>& stringList) {
	int n = stringList.size();
	vector<vector<string>> res;
	vector<pair<string, int>> sortedList;

	for (int i = 0; i < n; ++i) {
		string temp = stringList[i];
		sort(temp.begin(), temp.end());
		sortedList.push_back({ temp,i });
	}

	sort(sortedList.begin(), sortedList.end());

	for (int i = 0; i < n; ++i) {
		vector<string> temp;
		while (i < n - 1 && sortedList[i].first == sortedList[i + 1].first) {
			temp.push_back(stringList[sortedList[i].second]);
			++i;
		}
		if (i < n) temp.push_back(stringList[sortedList[i].second]);
		res.push_back(temp);
	}

	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<string> stringList(n);

		for (string& x : stringList) cin >> x;

		vector<vector<string>> res = Anagrams(stringList);

		for (vector<string> x : res) {
			for (string y : x) cout << y << " ";
			cout << endl;
		}
	}

	return 0;
}