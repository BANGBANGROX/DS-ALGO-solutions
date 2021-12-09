#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<int> parent;
vector<int> ranks;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void dsuUnion(int x, int y) {
	int parX = find(x), parY = find(y);
	if (parX == parY) return;
	if (ranks[parX] > ranks[parY]) parent[parY] = parX;
	if (ranks[parY] > ranks[parX]) parent[parX] = parY;
	else {
		parent[parX] = parY;
		++ranks[parX];
	}
}

int largestComponentSize(vector<int>& nums) {
	int maxValue = *max_element(nums.begin(), nums.end());
	int maxSize = 1;
	unordered_map<int, int> sizes;

	parent.resize(maxValue + 1);
	ranks.resize(maxValue + 1);

	for (int i = 1; i <= maxValue; ++i) parent[i] = i;

	for (int val : nums) {
		for (int i = 2; i * i <= val; ++i) {
			if (val % i != 0) continue;
			dsuUnion(val, i);
			dsuUnion(val / i, i);
		}
	}

	for (int val : nums) {
		int x = find(val);
		++sizes[x];
	}

	for (pair<int, int> x : sizes) maxSize = max(maxSize, x.second);

	return maxSize;
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<int> nums(n);
		for (int& x : nums) cin >> x;

		cout << largestComponentSize(nums) << endl;
	}

	return 0;
}
