#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
	int getMask(string s) {
		int mask = 0;

		for (char ch : s) {
			mask |= (1 << ch - 'a');
		}

		return mask;
	}

	static class UnionFind {
		vector<int> parent;
		vector<int> size;
		int groupCount;
		int maxSize;

	public :
		UnionFind(int n) {
			parent = vector<int>(n);
			size = vector<int>(n, 1);

			for (int i = 0; i < n; ++i) {
				parent[i] = i;
			}

			groupCount = n;
			maxSize = 1;
		}

		int find(int a) {
			if (parent[a] != a) return parent[a] = find(parent[a]);

			return a;
		}

		void unionNode(int a, int b) {
			if (a == b) return;

			int pa = find(a);
			int pb = find(b);

			if (pa != pb) {
				if (size[pa] > size[pb]) {
					parent[pb] = pa;
					size[pa] += size[pb];
					maxSize = max(maxSize, size[pa]);
				}
				else {
					parent[pa] = pb;
					size[pb] += size[pa];
					maxSize = max(maxSize, size[pb]);
				}
				--groupCount;
			}
		}

		int getSize() {
			return maxSize;
		}

		int getCount() {
			return groupCount;
		}
	};

public:
	vector<int> groupStrings(vector<string>& words) {
		int n = words.size();
		vector<int> masks(n);
		unordered_map<int, int> maskToIndex;
		UnionFind unionFind(n);

		for (int i = 0; i < n; ++i) {
			masks[i] = getMask(words[i]);
			maskToIndex[masks[i]] = i;
		}

		for (int i = 0; i < n; ++i) {
			// Look for anagrams as they will be grouped together
			// All anagrams will have same mask
			unionFind.unionNode(i, maskToIndex[masks[i]]);
			for (char ch : words[i]) {
				// Let's try to first delete the character ch
				int maskToFind = masks[i] ^ (1 << (ch - 'a'));
				if (maskToIndex.find(maskToFind) != maskToIndex.end()) {
					unionFind.unionNode(i, maskToIndex[maskToFind]);
				}
				// Now we will try to replace the character ch
				for (char c = 'a'; c <= 'z'; ++c) {
					if (c == ch || (maskToFind & (1 << (c - 'a'))) > 0) continue;
					int maskWithReplace = maskToFind | (1 << (c - 'a'));
					if (maskToIndex.find(maskWithReplace) != maskToIndex.end()) {
						unionFind.unionNode(i, maskToIndex[maskWithReplace]);
					}
				}
			}
		}

		return { unionFind.getCount(), unionFind.getSize() };
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<string> words(n);
		for (string& word : words) cin >> word;

		Solution solution;
		vector<int> ans = solution.groupStrings(words);
		cout << ans[0] << " " << ans[1] << endl;
	}

	return 0;
}