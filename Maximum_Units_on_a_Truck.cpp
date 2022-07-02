#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
			return a[1] > b[1]; });

		int ans = 0;

		for (vector<int>& boxType : boxTypes) {
			int box = boxType[0];
			int units = boxType[1];
			if (box <= truckSize) {
				ans += box * units;
				truckSize -= box;
			}
			else {
				ans += truckSize * units;
				break;
			}
		}

		return ans;
	}
};

int main() {
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> boxType(n, vector<int>(2));
		for (vector<int>& x : boxType) {
			cin >> x[0] >> x[1];
		}
		int truckSize;
		cin >> truckSize;
		
		Solution solution;
		cout << solution.maximumUnits(boxType, truckSize) << endl;
	}

	return 0;
}