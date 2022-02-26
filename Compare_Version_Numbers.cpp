#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> computeRevisions(string version) {
		int n = version.size();
		vector<int> revisions;

		for (int i = 0; i < n; ++i) {
			int currentRevision = 0;
			while (i < n && version[i] != '.') {
				currentRevision = currentRevision * 10 + (version[i] - '0');
				++i;
			}
			revisions.push_back(currentRevision);
		}

		return revisions;
	}

public:
	int compareVersion(string version1, string version2) {
		vector<int> revisions1 = computeRevisions(version1);
		vector<int> revisions2 = computeRevisions(version2);

		while (revisions1.size() < revisions2.size()) revisions1.push_back(0);

		while (revisions2.size() < revisions1.size()) revisions2.push_back(0);

		for (int i = 0; i < revisions1.size(); ++i) {
			if (revisions1[i] > revisions2[i]) return 1;
			if (revisions2[i] > revisions1[i]) return -1;
		}

		return 0;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		string version1, version2;
		cin >> version1 >> version2;

		Solution solution;
		cout << solution.compareVersion(version1, version2) << endl;
	}

	return 0;
}